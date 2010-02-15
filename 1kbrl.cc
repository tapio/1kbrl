#include <iostream>
#include <cstdlib>
#include "getch.hh"
#define o std::cout
#define e std::endl
#define f(i) for(int i=0;i<s;i++){
#define ei else if
#define r (1+rand()%(s-2))
#define s 15
#define mm m[i][j]
#define m_ m[x][y]
int m[s][s],x,y;
void gen(int n){
f(j)f(i)
if(i==0||i==s-1||j==0||j==s-1||rand()%10==0)mm=1;
ei(rand()%20==0)mm=2;
ei(rand()%100==0)mm=4;
else mm=0;
}}x=r;y=r;m_=0;m[r][r]=8;
}
int main(){
int g=0,b=30,t=0,l=1;
gen(l);
while(1){
o<<"\033[2J"<<"\e[1;33mCoins: "<<g<<e<<"\e[1;31mTorch: "<<b<<e<<"\e[1;35mMoves: "<<t<<e<<"\e[1;32mLevel: "<<l<<e;
f(j)f(i)
if(i==x&&j==y)o<<"\e[1;31m@";
ei(abs(x-i)+abs(y-j)>std::min(10,b/2))o<<" ";
ei(mm==0)o<<"\e[0;36m.";
ei(mm&1)o<<"\e[1;36m#";
ei(mm&2)o<<"\e[1;33mo";
ei(mm&4)o<<"\e[0;33mf";
ei(mm&8)o<<"\e[1;32m<";
}o<<e;}
char k=getch();
int u=x,v=y;
if(k=='a'){--x;++t;}ei(k=='d'){++x;++t;}ei(k=='w'){--y;++t;}ei(k=='s'){++y;++t;}ei(k==27)break;
if(m_&1){x=u;y=v;}ei(m_&2){g++;m_^=2;}ei(m_&4){b+=20;m_^=4;}ei(m_&8)gen(++l);
if(--b<1)break;
}
return 0;
}
