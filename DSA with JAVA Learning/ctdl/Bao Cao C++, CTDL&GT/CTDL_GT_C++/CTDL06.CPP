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



void XoaPhanTu(DanhSach &DS,int pt)
 {
  for(int i=1;i<=DS.n;i++)//tim phan tu
    {
     if(DS.PhanTu[i]==pt)
       {
	//xoa phan tu
	for(int j=i;i<DS.n;i++)
	  DS.PhanTu[j]=DS.PhanTu[j+1];
	DS.n--;
       }
    }
 }

struct Node
 {
  int PhanTu;
  Node *Left;
  Node *Right;
 };



struct List
 {
  Node *First;
  Node *Last;
 };





void DeleteItem(List &L,int pt)
 {
  Node *tam=new Node;
  tam=L.First;
  while(tam->Right!=L.Last&&tam->PhanTu < pt) 	//chay tu Node dau tien cho den Node cuoi
    {                                           //Dieu kien dung la pt lon hon PhanTu tai Node tam
     tam=tam->Right;
     //tim vi tri thich hop
     if(tam->PhanTu==pt)
       {
	//xoa phan tu tai vi tri vua tim duoc
	delete tam->Left->Right;
	tam->Right->Left=tam->Left;
	tam->Left->Right=tam->Right;
	delete tam;
       }
     }
 }

