#include<stdio.h>
#include<conio.h>
#include<iostream.h>

int n,i,j;
void swap(int &a,int &b)
 {
  int tg=a;
  a=b;
  b=tg;
 }


void nhap(int *x)
 {
  cout<<"\nSo phan tu cua day = ";cin>>n;
  for(i=1;i<=n;i++)
   {
    cout<<"Nhap phan tu thu "<<i<<":";
    cin>>x[i];
   }
 }


void xuat(int*x,int n)
 {
  cout<<"\nDay so sau khi sap xep\n";
  for(i=1;i<=n;i++)
  cout<<"\t"<<x[i];
 }


void sxtang(int *x,int n)
 {
  for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
    if(x[i]>x[j])
    swap(x[i],x[j]);
 }


void sxgiam(int *x,int n)
 {
  for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
    if(x[i]<x[j])
    swap(x[i],x[j]);
 }


void main()
 {
  clrscr();
  int x[60];
  cout<<"\nThuc Hanh Mon C++ \tBai 1\n";
  nhap(x);
  cout<<"Ban muon sap xep tang hay giam?\n";
  cout<<"\tSap xep tang nhan phim so 1\n";
  cout<<"\tSap xep giam nhan phim bat ky\n";
  cin>>i;
  if (i==1)
   {sxtang(x,n);xuat(x,n);}
   else {sxgiam(x,n);xuat(x,n);}
  getch();
}