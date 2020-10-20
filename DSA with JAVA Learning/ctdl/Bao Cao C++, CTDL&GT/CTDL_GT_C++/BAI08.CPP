#include<stdio.h>
#include<conio.h>
#include<iostream.h>

struct MaTran
 {
  double mt[20][20]; 	//ma tran duoc bieu dien bang mang 2 chieu
  int n;              	//cap cua ma tran
 };

istream& operator >> (istream& is,MaTran &A)
 {
  A.n=-1;
  while(A.n<0||A.n>20)
    {cout<<"\nCap cua Ma Tran= ";cin>>A.n;}
  cout<<"Nhap cac pha ntu cua ma tran:\n";
  for(int i=1;i<=A.n;i++)
    {
     for(int j=1;j<=A.n;j++)
       {cout<<"\tA "<<i<<j<<"= ";cin>>A.mt[i][j];}
     cout<<"\n";
    }
  return is;
 }

ostream& operator << (ostream& os,MaTran A)
 {
  cout<<"\n";
  for(int i=1;i<=A.n;i++)
    {
     for(int j=1;j<=A.n;j++)
       cout<<"\t"<<A.mt[i][j];
     cout<<"\n\n";
    }
  return os;
 }

MaTran operator +(MaTran A,MaTran B)
 {
  MaTran C;C.n=A.n;
  if(A.n!=B.n)cout<<"Hai ma tran khong cung cap";
  else
    {
     for(int i=1;i<=A.n;i++)
       for(int j=1;j<=A.n;j++)
	 C.mt[i][j]=A.mt[i][j]+B.mt[i][j];
    }
  return C;
 }

MaTran operator -(MaTran A,MaTran B)
 {
  MaTran C;C.n=A.n;
  if(A.n!=B.n)cout<<"Hai ma tran khong cung cap";
  else
    {
     for(int i=1;i<=A.n;i++)
       for(int j=1;j<=A.n;j++)
	 C.mt[i][j]=A.mt[i][j]-B.mt[i][j];
    }
  return C;
 }

MaTran operator *(MaTran A,MaTran B)
 {
  MaTran C;C.n=A.n;
  if(A.n!=B.n)cout<<"Hai ma tran khong cung cap";
  else
    {
     for(int i=1;i<=A.n;i++)
       for(int j=1;j<=A.n;j++)
	 {
	  C.mt[i][j]=0;
	  for(int k=1;k<=A.n;k++)
	    C.mt[i][j]=C.mt[i][j]+A.mt[i][k]*B.mt[k][j];
	 }
    }
  return C;
 }


void main()
 {
  clrscr();
  MaTran A,B,C;
  cin>>A;
  cin>>B;
  cout<<"A="<<A;
  cout<<"B="<<B;
  C=A+B;
  cout<<"A+B="<<C;
  C=A-B;
  cout<<"A-B="<<C;
  C=A*B;
  cout<<"A*B="<<C;

  getch();

 }