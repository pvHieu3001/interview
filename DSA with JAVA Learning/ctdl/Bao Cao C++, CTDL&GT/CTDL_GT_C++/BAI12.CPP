#include<stdio.h>
#include<conio.h>
#include<iostream.h>

class nguoi
 {
  char *ten,*diachi;
  int tuoi;
  nguoi()
   {
    ten=NULL;
    diachi=NULL;
    tuoi=0;
   }
  nguoi(char *name,char *dc,int t)
   {
    ten=name;
    diachi=dc;
    tuoi=t;
   }
 };

class MonHoc
 {
  char *monhoc;	//ten mon hoc
  int st;	//so tiet
 };

class GiaoVien:public nguoi
 {
  MonHoc MH;
 };

