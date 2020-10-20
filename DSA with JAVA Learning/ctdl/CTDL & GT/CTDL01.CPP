#include<iostream.h>
#include<conio.h>
#include<math.h>

double giaithua(int n)
 {
  if(n<0) return 0;
  else if(n<=1) return 1;
       else return n*giaithua(n-1);
 }

double S1(int n)
 {
  if(n<=0) return 0;
  else return n+S1(n-1);
 }

double S2(int n)
 {
  if(n<=0) return 0;
  else if(n%2==0)
   return S2(n-1);
       else return n+S2(n-2);
 }

void he10to2(long n)
 {
  if(n==0) return;
  he10to2(n/2);
  if(n%2==0) cout<<"0";
  else cout<<"1";
 }

void DaoNguoc(long n)
 {
  if(n==0)return;
  else
    {
     cout<<n%10;
     DaoNguoc(n/10);
    }
 }

int fibonaci(int n)
 {
  if(n<=2)return 1;
  else return fibonaci(n-1)+fibonaci(n-2);
 }

int UCLN(int a,int b)
 {
  if(a==b) return a;
  else if(a>b) return UCLN(a-b,b);
  	else return UCLN(a,b-a);
 }

float HaiMuN(int n)
 {
  if(n<0) return 1/HaiMuN(-n);
  if(n==0)return 1;
  else return 2*HaiMuN(n-1);
 }

float XmuY(int x,int y)
 {
  if(y<0) return 1/XmuY(x,-y);
  if(x==0)return 0;
  else if(y==0)return 1;
	else return x*XmuY(x,y-1);
 }

void main()
 {
  clrscr();
  long n,m;
  cout<<"Nhap 1 so n= ";cin>>n;
  cout<<"Nhap 1 so m= ";cin>>m;
  cout<<"\nn giai thua= "<<giaithua(n);
  cout<<"\nS1="<<S1(n);
  cout<<"\nS2="<<S2(n);
  //cout<<"\nDay So Fibonaci\n";
  //for(int i=1;i<=n;i++)
  //cout<<" "<<fibonaci(i);
  cout<<"\nn duoc chuyen sang he 2: ";he10to2(n);
  cout<<"\nn duoc dao nguoc: ";DaoNguoc(n);
  cout<<"\n UCLN n,m "<<UCLN(n,m);
  cout<<"\n2^n= "<<HaiMuN(n);
  cout<<"\nn^m= "<<XmuY(n,m);
  getch();
 }