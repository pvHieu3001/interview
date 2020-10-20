#include<conio.h>
#include<iostream.h>
int gt(int n)
 { if (n==0) return 1;
    else return (gt(n-1)*n);
 }

int sn(int n)
 {if (n==0) return 0;
  else return(sn(n-1)+n);
 }

int sk(int n)
 { if (n<=0) return 0;
   else
   {if (n%2==0)
    {n--;
     return (sk(n-2)+n) ;
     }
   else return(sk(n-2)+n);
   }
 }

int dtop(int n)
 {int m=n;
 return m;
 }
 /*
int dao(int n,int m)
 {


 }*/
int mun(int n)
 {
 if (n==0) return 1;
 else if (n==1) return 2;
      else return(mun(n-1)*2);
 }
int xmuy(int x, int y)
{if (y==0) return 1;
 else if (y==1) return x;
      else return(xmuy(x,y-1)*x);
}
void main()
{clrscr();
 int n=3;
 cout<<"\n\t"<<xmuy(n,n);
 getch();
}