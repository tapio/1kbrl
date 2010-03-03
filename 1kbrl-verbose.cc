#include <iostream>
#include <cstdio>
#include <cstdlib>

#define CLS std::cout << "\033[2J";
#define ESC "\e["
#define BLACK ESC << "0;30m"
#define RED ESC << "0;31m"
#define GREEN ESC << "0;32m"
#define YELLOW ESC << "0;33m"
#define BLUE ESC << "0;34m"
#define MAGENTA ESC << "0;35m"
#define CYAN ESC << "0;36m"
#define WHITE ESC << "0;37m"

#ifdef WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
int getch( ) {
	struct termios oldt, newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}
#endif

#define FLOOR 0
#define WALL 1
#define COIN (1 << 1)
#define STAIRS_DOWN (1 << 2)
#define STAIRS_UP (1 << 3)
#define TORCH (1 << 4)

#define MAPSIZE 15

int x, y;
int coins = 0, moves = 0, torch = 30, level = 1;
int lvl[MAPSIZE][MAPSIZE];


void gen(int seed) {
	srand(seed);
	for (int j = 0; j < MAPSIZE; j++) {
		for (int i = 0; i < MAPSIZE; i++) {
			if (i == 0 || i == MAPSIZE-1 || j == 0 || j == MAPSIZE-1 ||
			  rand() % 10 == 0) lvl[i][j] = 1;
			else if (rand() % 20 == 0) lvl[i][j] = COIN;
			else if (rand() % 100 == 0) lvl[i][j] = TORCH;
			else lvl[i][j] = 0;
		}
	}
	#define randcoord (1+rand()%(MAPSIZE-2))
	x = randcoord;
	y = randcoord;
	lvl[x][y] ^= STAIRS_DOWN;
	lvl[randcoord][randcoord] = STAIRS_UP;
}

void draw() {
	CLS;
	std::cout << YELLOW << "Coins: " << WHITE << coins << std::endl;
	std::cout << RED << "Torch: " << WHITE << torch << std::endl;
	std::cout << MAGENTA << "Moves: " << WHITE << moves << std::endl;
	std::cout << GREEN << "Level: " << WHITE << level << std::endl;
	for (int j = 0; j < MAPSIZE; j++) {
		for (int i = 0; i < MAPSIZE; i++) {
			if (i == x && j == y) std::cout << WHITE << "@";
			else if (abs(x-i)+abs(y-j)>std::min(10,torch/2)) std::cout << " ";
			else if (lvl[i][j] == 0) std::cout << BLUE << ".";
			else if (lvl[i][j] & WALL) std::cout << CYAN << "#";
			else if (lvl[i][j] & COIN) std::cout << YELLOW << "o";
			else if (lvl[i][j] & STAIRS_DOWN) std::cout << RED << "<";
			else if (lvl[i][j] & STAIRS_UP) std::cout << GREEN << ">";
			else if (lvl[i][j] & TORCH) std::cout << RED << "f";
		}
		std::cout << std::endl;
	}
}


int main() {
	gen(level);
	std::cout << GREEN << "Welcome! Use WASD to move." << std::endl;
	while (true) {
		// Drawing
		draw();
		// Input
		char k = getch();
		int oldx = x, oldy = y;
		if (k == 'a') { --x; ++moves; }
		else if (k == 'd') { ++x; ++moves; }
		else if (k == 'w') { --y; ++moves; }
		else if (k == 's') { ++y; ++moves; }
		else if (k == 27) exit(0);
		// Collisions
		if (lvl[x][y] & WALL) { x = oldx; y = oldy; }
		else if (lvl[x][y] & COIN) { coins++; lvl[x][y] ^= COIN; }
		else if (lvl[x][y] & TORCH) { torch+=20; lvl[x][y] ^= TORCH; }
		else if (lvl[x][y] & STAIRS_UP) gen(++level);
		// Die
		if (--torch <= 0) break;
	}

	return 0;
}


