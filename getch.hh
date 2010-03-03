/// This file provides a getch() function
/// which gets character from stdin in a
/// non-blocking way.
/// In Windows, conio.h is used, but in
/// Linux, a custom function is needed.

#include <iostream>

#ifdef WIN32
#include <conio.h>
#else
#include <cstdio>
#include <termios.h>
#include <unistd.h>
int getch() {
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
bool kbhit() {
	return true;
}
#endif
