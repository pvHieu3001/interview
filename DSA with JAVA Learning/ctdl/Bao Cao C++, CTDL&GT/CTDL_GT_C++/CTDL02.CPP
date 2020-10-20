#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct DanhSach
 {
  int PhanTu[100];
  int n;  //so phan tu cua danh sach
 };

void TaoRong(DanhSach &DS)
 {
  DS.n=0;
 }

//them vao dau sanh sach
void ThemDau(DanhSach &DS,int phantu)
 {
  for(int i=DS.n;i>=1;i--)
    DS.PhanTu[i+1]=DS.PhanTu[i];
    DS.PhanTu[1]=phantu;
    DS.n++;
 }

//them vao cuoi danh sach
void ThemCuoi(DanhSach &DS,int phantu)
 {
  DS.n++;
  DS.PhanTu[DS.n]=phantu;
 }

//nhap va luu tru theo thu tu
void Nhap(DanhSach &DS)
 {
  char str[99];
  cout<<"\nNhap vao mot day so nguyen";
  gets(str);
  for(int i=1;i<=strlen(str);i++)
    ThemCuoi(DS,int(str[i-1])-48);
 }

//nhap va luu tru nguoc voi thu tu nhap
void NhapNguoc(DanhSach &DS)
 {
  char str[99];
  cout<<"\nNhap vao mot day so nguyen";
  gets(str);
  for(int i=1;i<=strlen(str);i++)
    ThemDau(DS,int(str[i-1])-48);
 }

void Xuat(DanhSach DS)
 {
  for(int i=1;i<=DS.n;i++)
    cout<<DS.PhanTu[i];
  getch();
 }

void main()
 {
  clrscr();
  DanhSach A,B;

  TaoRong(A);
  Nhap(A);
  Xuat(A);

  TaoRong(B);
  NhapNguoc(B);
  Xuat(B);

  getch();
 }