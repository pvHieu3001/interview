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
  while(tam1->Right->Right!=L.Last) 	//chay tu Node dau tien cho den Node ke cuoi
    {
     tam1=tam1->Right;
     while(tam2->Right!=L.Last)		//chay tu Node tam den Node cuoi
       {
	tam2=tam1->Right;
	if(tam1->PhanTu > tam2->PhanTu)
	swap(tam1,tam2);
       }
    }

 }