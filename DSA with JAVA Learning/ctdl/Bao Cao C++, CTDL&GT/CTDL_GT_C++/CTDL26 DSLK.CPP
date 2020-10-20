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
  Node *Last1;	//day ngan xep 1
  Node *Last2;  //day ngan xep 2
  Node *Center; //dinh cua 2 ngan xep
  int n1;	//so phan tu cua NX 1
  int n2;	//so phan tu cua NX 2
 };

void Create(Stack &S)
 {
  S.Last1=new Node;
  S.Last2=new Node;
  S.Center=new Node;
  S.Center->Right=S.Last2;
  S.Center->Left=S.Last1;
  S.Last1->Left=S.Center;
  S.Last1->Right=NULL;
  S.Last2->Left=S.Center;
  S.Last2->Right=NULL;
  S.n1=S.n2=0;
 }


int Emty1(Stack &S)
 {
  return(S.Center->Left==S.Last1);
 }
int Emty2(Stack &S)
 {
  return(S.Center->Right==S.Last2);
 }

//hien thi ngan xep
void Display1(Stack &S)
 {
  cout<<"\n";
  Node *N;
  N=S.Center->Left;
  for(int i=1;i<=S.n1;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
 }
void Display2(Stack &S)
 {
  cout<<"\n";
  Node *N;
  N=S.Center->Right;
  for(int i=1;i<=S.n2;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
 }


//vao sau ra truoc (them vao dau danh sach)
void Push1(Stack &S,char phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Left=S.Center;
  N->Right=S.Center->Left;
  S.Center->Left->Left=N;
  S.Center->Left=N;
  S.n1++;
 }
void Push2(Stack &S,char phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Left=S.Center;
  N->Right=S.Center->Right;
  S.Center->Right->Left=N;
  S.Center->Right=N;
  S.n2++;
 }


//lay mot phan tu o dinh ngan xep
char Pop1(Stack &S)
 {
  if(S.n1<=0) {cout<<"Ngan xep rong 1";getch();return 0;}
  char n=S.Center->Left->Info;
  Node*N=S.Center->Left;
  S.Center->Left->Right->Left=S.Center;
  S.Center->Left=S.Center->Left->Right;
  delete N;S.n1--;
  return n;
 }
char Pop2(Stack &S)
 {
  if(S.n1<=0) {cout<<"Ngan xep rong 2";getch();return 0;}
  char n=S.Center->Right->Info;
  Node*N=S.Center->Right;
  S.Center->Right->Right->Left=S.Center;
  S.Center->Right=S.Center->Right->Right;
  delete N;S.n2--;
  return n;
 }


//nhap vao cac pha ntu cua ngan xep
void Add(Stack &S)
 {
  char ch='1';
  cout<<"\nNhap vao cac phan tu cua ngan xep, nhan ENTER de ket thuc:\n\t ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
       if(int(ch)!=13){Push1(S,ch);Push2(S,ch);}
    }
 }

void main()
 {
  clrscr();

  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  Stack A;
  Create(A);
  Add(A);
  cout<<"\nNgap xep sau khi nhap:";
  Display1(A);
  Display2(A);
  getch();

 }