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
  L.First->Left=L.Last;
  L.First->Right=L.Last;
  L.Last->Left=L.First;
  L.Last->Right=L.First;
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

//vao truoc ra truoc (them vao cuoi danh sach)
void Add_FIFO(List &L,int phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Right=L.Last;
  N->Left=L.Last->Left;
  L.Last->Left->Right=N;
  L.Last->Left=N;
  L.n++;
 }


void DeleteN(List &L,int ViTri)
 {
  if(ViTri<=0||ViTri>L.n)
    {cout<<"Sai vi tri xoa phan tu";getch();return;}
  Node *N=L.First->Right;
  for(int i=1;i<ViTri;i++)
    N=N->Right;
  char c;cout<<"\nSo can xoa la: "<<N->Info<<" ,tai vi tri: "<<ViTri;
  cout<<"\nBan co chac la muon xoa ? (y,n)";c=getch();
  if(c!='y'){cout<<"\nDanh sach duoc giu nguyen:";Display(L);return;}
  //xoa N
  N->Left->Right=N->Right;
  N->Right->Left=N->Left;
  delete N;L.n--;
  cout<<"\nDanh sach sau khi xoa:";
  Display(L);
 }

void Add_And_Insert(List &L)
 {
  char ch='1';
  cout<<"\nNhap vao mot day so nguyen: ";
  while(int(ch)>=48 && int(ch)<= 57)
    {
     ch=getch();cout<<ch;
     if(int(ch)>=48 && int(ch)<= 57)
       Add_FIFO(L,int(ch)-48);
    }
 }



void main()
 {
  clrscr();int n;

  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK noi vong";
  List B;
  Create(B);
  Add_And_Insert(B);
  cout<<"\nDanh sach sau khi nhap";
  Display(B);

  cout<<"\nNhap vao vi tri cua phan tu can xoa: ";cin>>n;
  DeleteN(B,n);
  getch();

 }