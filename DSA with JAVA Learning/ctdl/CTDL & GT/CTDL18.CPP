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
 }

//vao sau ra truoc (them vao dau danh sach)
void Push(Stack &S,int phantu)
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
int Pop(Stack &S)
 {
  if(S.n<=0) {cout<<"Ngan xep rong";getch();return 0;}
  int n=S.First->Right->Info;
  Node*N=S.First->Right;
  S.First->Right->Right->Left=S.First;
  S.First->Right=S.First->Right->Right;
  delete N;S.n--;
  return n;
 }

//doi 1 so thap phan sang nhi phan
void Thap2NhiPhan(Stack &S,long n)
 {
  //int check=0;
  if(n<0) n=n*-1;//check=1;}
  while(n!=0)
    {
     Push(S,n%2);
     n=n/2;
    }
 }




void main()
 {
  clrscr();
  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  Stack B;long n;
  Create(B);
  cout<<"\nNhap mot so thap phan: "; cin>>n;
  Thap2NhiPhan(B,n);
  cout<<n<<" duoc doi thanh so nhi phan:\n";
  Display(B);
  getch();

 }