#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>


struct Node
 {
  char Info;
  Node *Left;
  Node *Right;
 };

struct Stack
 {
  Node *First;
  Node *Last;
  int n;
 };

void Create(Stack &S)
 {
  S.First=new Node;
  S.Last= new Node;
  S.First->Left=NULL;
  S.First->Right=S.Last;
  S.Last->Left=S.First;
  S.Last->Right=NULL;
  S.n=0;
 }

int Emty(Stack &S)
 {
  return(S.First->Right==S.Last);
 }

//hien thi ngan xep
void Display(Stack &S)
 {
  cout<<"\n\n";
  Node *N;
  N=S.First->Right;
  for(int i=1;i<=S.n;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
 }

//vao sau ra truoc (them vao dau danh sach)
void Push(Stack &S,char phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Left=S.First;
  N->Right=S.First->Right;
  S.First->Right->Left=N;
  S.First->Right=N;
  S.n++;
 }

//lay mot phan tu o dinh ngan xep
char Pop(Stack &S)
 {
  if(S.n<=0) {cout<<"Ngan xep rong";getch();return 0;}
  char n=S.First->Right->Info;
  Node*N=S.First->Right;
  S.First->Right->Right->Left=S.First;
  S.First->Right=S.First->Right->Right;
  delete N;S.n--;
  return n;
 }

//nhap vao cac pha ntu cua ngan xep
void Add(Stack &S)
 {
  char ch='1';
  cout<<"\nNhap vao cac phan tu cua ngan xep, nhan ENTER de ket thuc\n\t: ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
       if(int(ch)!=13)Push(S,ch);
    }
 }

//dao nguoc mot stack
void DaoNguoc(Stack &S)
 {
  Stack S1,S2;char c;
  Create(S1);Create(S2);
  while(!Emty(S))
    {
     c=Pop(S);
     Push(S1,c);
    }
  while(!Emty(S1))
    {
     c=Pop(S1);
     Push(S2,c);
    }
  while(!Emty(S2))
    {
     c=Pop(S2);
     Push(S,c);
    }
 }

void main()
 {
  clrscr();int n;

  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  Stack B;
  Create(B);
  Add(B);
  cout<<"\nNgan xep sau khi nhap:";
  Display(B);
  cout<<"\nNgan xep sau khi dao nguoc:";
  DaoNguoc(B);
  Display(B);

  getch();

 }