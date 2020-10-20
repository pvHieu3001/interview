#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>


	//------ doi voi danh sach luu tru bang con tro -------

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

//nhap va luu tru mot so nguyen lon
void Add(List &L)
 {
  char ch='1';int i=0,j=0,n=0;
  cout<<"\nNhap vao mot day so nguyen: ";
  while(j>=0 && j<=9)
    {
     ch=getch();cout<<ch;j=int(ch)-48;
     if(j>=0 && j<=9)
       {
	i++;n=n*10+j;
	if(i==3)
	  {
	   Add_FILO(L,n);
	   i=j=n=0;
	  }
       }
    }
 }

//cong hai so nguyen lon
void Cong(List &A,List &B,List &C)
 {
  Node *N,*M;
  if(A.n>=B.n)
    {
     C=A;Display(C);getch();
     N=B.Last->Left;
     M=C.Last->Left;
     while(N->Left!=NULL)
      {
       if(M->Info+N->Info>1000)M->Left->Info+=1;
       M->Info=(M->Info+N->Info)%1000;
       N=N->Left;
       M=M->Left;
      }
    }
  else
    {
     C=B;C.First->Info=0;
     N=A.Last->Left;
     M=C.Last->Left;
     while(N->Left!=NULL)
      {
       if(M->Info+N->Info>1000)M->Left->Info+=1;
       M->Info=(M->Info+N->Info)%1000;
       N=N->Left;
       M=M->Left;
      }
    }
  if(C.First->Info==1)
    Add_LIFO(C,1);
 }

void main()
 {
  clrscr();
  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  List A,B,C;
  Create(A);
  Create(B);
  Create(C);
  Add(A);
  cout<<"\n\nSo nguyen lon sau khi nhap\nA= ";
  Display(A);
  Add(B);
  cout<<"\n\nSo nguyen lon sau khi nhap\nB=";
  Display(B);

  Cong(A,B,C);
  cout<<"\nC=A+B, C= ";
  Display(C);
  cout<<"\n";
  Display(A);
  cout<<"\n";
  Display(B);
  getch();

 }