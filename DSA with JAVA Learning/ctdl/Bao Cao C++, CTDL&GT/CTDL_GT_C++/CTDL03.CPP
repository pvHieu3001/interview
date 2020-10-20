#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct Node
 {
  int Info;
  Node *Left;
  Node *Right;
 };

struct List
 {
  Node *First;
  Node *Last;
  int n;
 };

void Create(List &L)
 {
  L.First=new Node;
  L.Last= new Node;
  L.First->Left=NULL;
  L.First->Right=L.Last;
  L.Last->Left=L.First;
  L.Last->Right=NULL;
  L.n=0;
 }

int Emty(List &L)
 {
  return(L.First->Right==L.Last);
 }

//hien thi danh sach
void Display(List &L)
 {
  cout<<"\n\n";
  Node *N=new Node;
  N=L.First->Right;
  for(int i=1;i<=L.n;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
 }

//vao sau ra truoc (them vao dau danh sach)
void Add_LIFO(List &L,int phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Left=L.First;
  N->Right=L.First->Right;
  L.First->Right->Left=N;
  L.First->Right=N;
  L.n++;
 }

//vao truoc ra sau (them vao cuoi danh sach)
void Add_FILO(List &L,int phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Right=L.Last;
  N->Left=L.Last->Left;
  L.Last->Left->Right=N;
  L.Last->Left=N;
  L.n++;
 }

//nhap va luu tru theo thu tu nhap vao hoac nguoc lai
void Add_And_Insert(List &L)
 {
  char ch='1';int sx=0;
  cout<<"Ban muon sap xep day so theo thu tu nao ?";
  cout<<"\n  Nhan phim '1' neu theo thu tu nhap\n  Nhan phim bat ky neu nguoc lai";cin>>sx;
  cout<<"Nhap vao mot day so nguyen: ";
  while(int(ch)>=48 && int(ch)<= 57)
    {
     ch=getch();cout<<ch;
     if(int(ch) >= 48 && int(ch) <= 57)
       if(sx==1) Add_FILO(L,int(ch)-48);
       else Add_LIFO(L,int(ch)-48);
    }
 }

void main()
 {
  clrscr();
  cout<<"\n\n";
  List B;
  Create(B);
  Add_And_Insert(B);
  Display(B);
  getch();
 }