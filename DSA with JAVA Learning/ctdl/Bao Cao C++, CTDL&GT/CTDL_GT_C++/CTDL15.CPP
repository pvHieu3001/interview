#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>


struct Node
 {
  int HeSo,SoMu;
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
  cout<<"\n";
  Node *N=new Node;
  N=L.First->Right;
  for(int i=1;i<=L.n-1;i++)
    {
     cout<<N->HeSo<<"X^"<<N->SoMu<<" + ";
     N=N->Right;
    }
  if(!Emty(L)&&N->SoMu==0) cout<<N->HeSo;
  else if(N->SoMu!=0) cout<<N->HeSo<<"X^"<<N->SoMu;
 }

//hien thi da thuc mau
void DisplayEx(int bac)
 {
  int i;
  cout<<"\nDa thuc can nhap co dang:\n\t";
  for(i=bac;i>=1;i--)
    {
     cout<<"a"<<i<<"X^"<<i<<" + ";
    }
  cout<<"a0";getch();
 }

//vao sau ra truoc (them vao dau danh sach)
void Add_LIFO(List &L,int hs,int sm)
 {
  Node *N=new Node;
  N->HeSo=hs;
  N->SoMu=sm;
  N->Left=L.First;
  N->Right=L.First->Right;
  L.First->Right->Left=N;
  L.First->Right=N;
  L.n++;
 }

//vao truoc ra sau (them vao cuoi danh sach)
void Add_FILO(List &L,int hs,int sm)
 {
  Node *N=new Node;
  N->HeSo=hs;
  N->SoMu=sm;
  N->Right=L.Last;
  N->Left=L.Last->Left;
  L.Last->Left->Right=N;
  L.Last->Left=N;
  L.n++;
 }

//them vao vi tri thich hop trong danh sach
void Add(List &L,int hs,int sm)
 {
  if(hs>L.First->Right->HeSo) {Add_LIFO(L,hs,sm);return;}
  if(hs<L.Last->Left->HeSo) {Add_FILO(L,hs,sm);return;}

  Node *N;
  N=L.First->Right;
  while(N->Right!=NULL)
   if(N->SoMu==sm) {N->HeSo=N->HeSo+hs;return;}
   else N=N->Right;

  N=L.First->Right;
  while(N->Right!=NULL)
     if(N->SoMu > sm)// && sm > N->Right->SoMu)
       {
	Node *K=new Node;
	K->HeSo=hs;
	K->SoMu=sm;
	K->Left=N;
	K->Right=N->Right;
	N->Right->Left=K;
	N->Right=K;
	L.n++;return;
       }
     else N=N->Right;
 }



void CongDaThuc(List &A,List &B,List& C)
 {
  int i;Node*N=A.First->Right;
  //da thuc c=a
  while(N->Right!=NULL)
    {
     Add_FILO(C,N->HeSo,N->SoMu);
     N=N->Right;
    }
  N=B.First->Right;
  //cong da thuc c=c+b
  while(N->Right!=NULL)
    {
     Add(C,N->HeSo,N->SoMu);
     N=N->Right;
    }
 }


void DaoHam(List &A)
 {
  Node*N=A.First->Right;
  //keiem tra cac truong hop dac biet
  if(N->SoMu==0 || A.n==0)
    {cout<<"Dao ham cua da thuc = 0";return;}

  while(N->Right!=NULL)
    {
     N->HeSo*=N->SoMu;
     N->SoMu--;
     N=N->Right;
    }
  A.n--;
 }

//nhap da thuc
void AddDT(List &L)
 {
  int ch,i,n;
  cout<<"\nNhap vao bac cua da thuc: ";cin>>ch;
  DisplayEx(ch);
  cout<<"\n";
  for(i=ch;i>=0;i--)
    {
     cout<<"a"<<i<<"= ";cin>>n;
     if(n!=0)Add_FILO(L,n,i);
    }
 }

void main()
 {
  clrscr();
  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  List A,B,C;
  Create(A);
  Create(B);
  Create(C);
  AddDT(A);
  cout<<"\nDa thuc 1 ban vua nhap:";
  Display(A);
  DaoHam(A);
  cout<<"\nA dao ham bang ";
  Display(A);

  AddDT(B);
  cout<<"\nDa thuc 2 ban vua nhap:";
  Display(B);

  CongDaThuc(A,B,C);
  cout<<"\nDa thuc sau ki cong ";
  Display(C);
  getch();

 }