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
  Node *N=new Node;
  N=S.First->Right;
  for(int i=1;i<=S.n;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
  getch();
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

//nhap vao bieu thuc toan hoc
void Add_And_Insert(Stack &S)
 {
  char ch='1';
  cout<<"\nNhap vao chuoi hau to dung (vd: 12+ ): ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
     if(ch=='('||ch==')')
       Push(S,ch);
    }
 }

//kiem tra chuoi dau ngoac
void Check(Stack &S,Stack &K)
 {
  char c;int i;
  while(!Emty(S))	//chuyen bieu thuc ve dang 1,0
    {                   //toan hang(=1, )=0
     c=Pop(S);
     if(c=='(')
       Push(K,'1');
     else Push(K,'0');
    }
  cout<<"\n\nBieu thuc duoc chuyen ve dang 0,1";
  cout<<"\n  ( =1,  )=0";
  Display(K);
  //kiem tra Node N,N+1 co dang 10 hay ko?
  //neu co thi xoa N va N+1
  i=K.n;Node *N;
  while(!Emty(K)&&i>0)
    {
     N=K.First;
     while(N->Right->Right!=NULL)
       {
	if(N->Right->Info=='1'&&N->Right->Right->Info=='0')
	  {
	   //xoa 2 Node sau N
	   Node *t1=N->Right,*t2=N->Right->Right;
	   N->Right->Right->Right->Left=N;
	   N->Right=N->Right->Right->Right;
	   delete t1,t2;K.n-=2;
	  }
	N=N->Right;
       }
     i--;
    }

  if(K.First->Right==K.Last)
    cout<<"\nBieu thuc nhap vao co chuoi ngoac dung";
  else cout<<"\nBieu thuc nhap vao co chuoi ngoac sai";getch();
 }


void main()
 {
  clrscr();

  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  Stack A,B;
  Create(A);
  Create(B);
  Add_And_Insert(A);
  Check(A,B);
  getch();

 }