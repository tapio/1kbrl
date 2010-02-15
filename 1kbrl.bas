#define o Print
#define f(i) For i ai=0 To s-1
#define Ei ElseIf
#define r (1+Int(Rnd*(s-2)))
#define mm m(i,j)
#define m_ m(x,y)
#define ai As Integer
#define h Then
#define a And
#define Fi EndIf
#define c Color
#define s 15
Dim Shared ai m(s,s),x,y
Sub gen()
f(j):f(i)
If(i=0 Or i=s-1 Or j=0 Or j=s-1 Or Int(Rnd*10)=0)h:mm=1
Ei(Int(Rnd*20)=0)h mm=2
Ei(Int(Rnd*100)=0)h mm=4
Else mm=0:Fi
Next:Next:x=r:y=r:m_=0:m(r,r)=8
End Sub
Dim ai g=0,b=30,t=0,l=1,u,v
gen
While(1)
Cls
c 14:o "Coins:";g
c 6:o "Torch:";b
c 4:o "Moves:";t
c 2:o "Level:";l
f(j):f(i)
If(i=x a j=y)h:c 4:o "@";
Ei(Abs(x-i)+Abs(y-j)>IIF(10<b\2,10,b\2))h:o " ";
Ei(mm=0)h c 3:o ".";
Ei(mm a 1)h c 3:o "#";
Ei(mm a 2)h c 14:o "o";
Ei(mm a 4)h c 6:o "f";
Ei(mm a 8)h c 2:o "<";
Fi
Next
o
Next
Sleep
Dim As String k=Inkey()
u=x:v=y
If(k="a")h:x-=1:t+=1
Ei(k="d")h x+=1:t+=1
Ei(k="w")h y-=1:t+=1
Ei(k="s")h y+=1:t+=1
Ei(k=Chr(27))h End
Fi
If(m_ a 1)h:x=u:y=v
Ei(m_ a 2)h g+=1:m_ Xor=2
Ei(m_ a 4)h b+=20:m_ Xor=4
Ei(m_ a 8)h l+=1:gen
Fi
b-=1:if(b<1)h End
Wend
