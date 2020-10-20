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

void SapXepTang(DanhSach DS)
 {
  int tam;
  for(int i=1;i<DS.n;i++)
    for(int j=i+1;j<=DS.n;j++)
      if(DS.PhanTu[i]>DS.PhanTu[j])
	{
	 swap(DS.PhanTu[i],DS.PhanTu[j]);
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

void SapXepTang(List &L)
 {
  Node *tam1=new Node;
  Node *tam2=new Node;
  tam1=L.First;
  while(tam1->Right!=L.Last) 	//chay tu Node dau tien cho den Node cuoi
    {
     tam1=tam1->Right;
     while(tam2->Right->Right!=L.Last)	//chay tu Node tam den Node ke^` cuoi
       {
	tam2=tam1->Right;
	if(tam1->PhanTu > tam2->PhanTu)
	swap(tam1,tam2);
       }
    }

 }

void ThemPhanTu(List &L,int pt)
 {
  Node *tam=new Node;
  tam=L.First;
  while(tam->Right!=L.Last&&tam->PhanTu < pt) 	//chay tu Node dau tien cho den Node cuoi
    {                                           //Dieu kien dung la pt lon hon PhanTu tai Node tam
     tam=tam->Right;
     //tim vi tri thich hop
     if(tam->PhanTu>=pt && tam->Right->PhanTu<=pt)
       {
	//chen vao vi tri vua tim duoc
	tam->Right->Left=tam;
	tam->Left->Right=tam;
	tam->Left=tam->Left->Right;
       }
     }
 }

