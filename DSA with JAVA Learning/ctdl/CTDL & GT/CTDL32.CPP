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
void Add_LIFO(List &L,char phantu)
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
void Add_FILO(List &L,char phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Right=L.Last;
  N->Left=L.Last->Left;
  L.Last->Left->Right=N;
  L.Last->Left=N;
  L.n++;
 }


void Add_HauTo(List &L)
 {
  char ch='1';
  cout<<"\nNhap vao chuoi hau to dung (vd: 12+ ): ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
     if((int(ch)>=48 && int(ch)<= 57)||ch=='+'||ch=='-'||ch=='*'||ch=='/')
       Add_FILO(L,ch);
    }
 }

void Add_TienTo(List &L)
 {
  char ch='1';
  cout<<"\nNhap vao chuoi tien to dung (vd: +12 ): ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
     if((int(ch)>=48 && int(ch)<= 57)||ch=='+'||ch=='-'||ch=='*'||ch=='/')
       Add_FILO(L,ch);
    }
 }


	//-----------------------------

struct Stack
 {
  int so[30];
  int top;
 };

void CreateS(Stack &S)
  {S.top=0;}

void Push(Stack &S,int n)
 {S.top++;S.so[S.top]=n;}

int Pop(Stack &S)
 {
 if(S.top>0)
  {S.top--;return S.so[S.top+1];}
 else return -1;
 }


int DinhGiaHauTo(List &L)
 {
  int tam1,tam2;
  Stack S;CreateS(S);int n=0;Node *N=L.First->Right;
  for(int i=0;i<=L.n;i++)
    {
     n=int(N->Info-48);
     if(n>=1 && n<=9)
       Push(S,n);
     else
       {
	tam1=Pop(S);
	tam2=Pop(S);
	switch (N->Info) {
	 case'+':tam1=tam2+tam1;break;
	 case'-':tam1=tam2-tam1;break;
	 case'*':tam1=tam2*tam1;break;
	 case'/':tam1=tam2/tam1;break;
	  };
	Push(S,tam1);
       }
     N=N->Right;
    }
   return Pop(S);
 }

int DinhGiaTienTo(List &L)
 {
  int tam1,tam2;
  Stack S;CreateS(S);int n=0;Node *N=L.Last->Left;
  for(int i=0;i<=L.n-1;i++)
    {
     n=int(N->Info-48);
     if(n>=1 && n<=9)
       Push(S,n);
     else
       {
	tam1=Pop(S);
	tam2=Pop(S);
	switch (N->Info) {
	 case'+':tam1=tam2+tam1;break;
	 case'-':tam1=tam2-tam1;break;
	 case'*':tam1=tam2*tam1;break;
	 case'/':tam1=tam2/tam1;break;
	  };
	Push(S,tam1);
       }
     N=N->Left;
    }
   return Pop(S);
 }

	//-----------------------------


void main()
 {
  clrscr();
  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  List A,B;
  Create(A);Create(B);
  Add_HauTo(A);
  cout<<"\nDanh sach sau khi nhap";
  Display(A);
  cout<<"\nKet qua cua chuoi hau to la: "<<DinhGiaHauTo(A);

  Add_TienTo(B);
  cout<<"\nDanh sach sau khi nhap";
  Display(B);
  cout<<"\nKet qua cua chuoi hau to la: "<<DinhGiaTienTo(B);

  getch();

 }