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

//nhap vao cac phan tu cua ngan xep
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

int Count(Stack &S)
 {
  Stack K;Create(K);char c;int check=0;
  while(!Emty(S))  //dem so phan tu cua ngan xep
    {
     c=Pop(S);check++;
     Push(K,c);
    }
  while(!Emty(K))  //Tra lai ngan xep nhu ban dau
    {
     c=Pop(K);
     Push(S,c);
    }
  return check;
 }

void XemPTn(Stack &S,int n)
 {
  if(n<=0||n>S.n)
    {
     cout<<"\nn<0 hoac n lon hon so phan tu cua ngan xep";
     getch();return;
    }
  //lay noi dung cua phan tu thu n
  Stack K;Create(K);int kt=n;char c;
  while(kt!=0)
    {c=Pop(S);  Push(K,c); kt--;}
  cout<<"Phan tu thu "<<n<<"= "<<c;getch();

  //tra lai ngan xep ban dau
  while(!Emty(K))
    {c=Pop(K);Push(S,c);}
 }

void XoaPTn(Stack &S,int n)
 {
  if(n<=0||n>S.n)
    {
     cout<<"\nn<0 hoac n lon hon so phan tu cua ngan xep";
     getch();return;
    }

  //lay noi dung cua phan tu thu n
  Stack K;Create(K);int kt=n;char c,tmp;
  while(kt!=0)
    {
     c=Pop(S);
     Push(K,c);
     kt--;
    }
  cout<<"\nPhan tu thu "<<n<<"= "<<c;
  cout<<"\nban co muon xoa phan tu nay khong (y,n):";tmp=getch();

  if(tmp=='y')
    {
     c=Pop(K);//bo di phan tu thu n
     //tra lai ngan xep sau khi xoa
     while(!Emty(K))
       {c=Pop(K);Push(S,c);}
    }
  else
    {
     //tra lai ngan xep nhu ban dau
     while(!Emty(K))
       {c=Pop(K);Push(S,c);}
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
  cout<<"\nSo phan tu cua ngan xep= "<<Count(B);
  Display(B);
  cout<<"\nNhap so thu tu cua phan tu can xem: n= ";cin>>n;
  XemPTn(B,n);
  Display(B);
  cout<<"\nNhap so thu tu cua phan tu can xoa: n= ";cin>>n;
  XoaPTn(B,n);
  Display(B);
  getch();

 }