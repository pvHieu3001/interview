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

struct Queue
 {
  Node *First;
  Node *Last;
  int n;
 };

void Create(Queue &Q)
 {
  Q.First=new Node;
  Q.Last= new Node;
  Q.First->Left=NULL;
  Q.First->Right=Q.Last;
  Q.Last->Left=Q.First;
  Q.Last->Right=NULL;
  Q.n=0;
 }

int Emty(Queue &Q)
 {
  return(Q.First->Right==Q.Last);
 }

//hien thi ngan xep
void Display(Queue &Q)
 {
  cout<<"\n\n";
  Node *N;
  N=Q.First->Right;
  for(int i=1;i<=Q.n;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
 }

//vao sau ra truoc (them vao dau danh sach)
void Push(Queue &Q,char phantu)
 {
  Node *N=new Node;
  N->Info=phantu;
  N->Right=Q.Last;
  N->Left=Q.Last->Left;
  Q.Last->Left->Right=N;
  Q.Last->Left=N;
  Q.n++;
 }

//lay mot phan tu o dinh hang doi
char Pop(Queue &Q)
 {
  if(Q.n<=0) {cout<<"Hang doi rong";getch();return 0;}
  char n=Q.First->Right->Info;
  Node*N=Q.First->Right;
  Q.First->Right->Right->Left=Q.First;
  Q.First->Right=Q.First->Right->Right;
  delete N;Q.n--;
  return n;
 }

//nhap vao cac phan tu cua ngan xep
void Add(Queue &Q)
 {
  char ch='1';
  cout<<"\nNhap vao cac phan tu cua hang doi, nhan ENTER de ket thuc\n\t: ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
       if(int(ch)!=13)Push(Q,ch);
    }
 }

int Count(Queue &Q)
 {
  Queue K;Create(K);char c;int check=0;
  while(!Emty(Q))  //dem so phan tu cua hang doi
    {
     c=Pop(Q);check++;
     Push(K,c);
    }
  while(!Emty(K))  //Tra lai hang doi nhu ban dau
    {
     c=Pop(K);
     Push(Q,c);
    }
  return check;
 }

void XemPTn(Queue &Q,int n)
 {
  if(n<=0||n>Q.n)
    {
     cout<<"\nn<0 hoac n lon hon so phan tu cua hang doi";
     getch();return;
    }
  //lay noi dung cua phan tu thu n
  Queue K;Create(K);int kt=0;char c,tam;
  while(!Emty(Q))
    {c=Pop(Q);  Push(K,c); kt++;if(kt==n)tam=c;}
  cout<<"Phan tu thu "<<n<<"= "<<tam;getch();

  //tra lai ngan xep ban dau
  while(!Emty(K))
    {c=Pop(K);Push(Q,c);}
 }

void XoaPTn(Queue &Q,int n)
 {
  if(n<=0||n>Q.n)
    {
     cout<<"\nn<0 hoac n lon hon so phan tu cua hang doi";
     getch();return;
    }

  //lay noi dung cua phan tu thu n
  Queue K;Create(K);int kt=n-1;char c,tmp;
  while(kt!=0)
    {
     c=Pop(Q);
     Push(K,c);
     kt--;
    }
  tmp=Pop(Q);
  cout<<"\nPhan tu thu "<<n<<"= "<<tmp;
  cout<<"\nban co muon xoa phan tu nay khong (y,n):";c=getch();

  if(c=='y')
    {
     //chuyen toan bo nhung phan tu con lai trong Q sang K
     while(!Emty(Q))
       {c=Pop(Q);Push(K,c);}
    }
  else
    {
     //chuyen ky tu vao K va chuyen toan bo PT con lai trong Q sang K
     Push(K,tmp);
     while(!Emty(Q))
       {c=Pop(Q);Push(K,c);}
    }
  //tra lai Hang doi Q
  while(!Emty(K))
    {c=Pop(K);Push(Q,c);}
 }

void main()
 {
  clrscr();int n;

  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  Queue B;
  Create(B);
  Add(B);
  cout<<"\nHang Doi sau khi nhap:";
  Display(B);
  cout<<"\nSo phan tu cua Hang Doi= "<<Count(B);
  Display(B);
  cout<<"\nNhap so thu tu cua phan tu can xem: n= ";cin>>n;
  XemPTn(B,n);
  Display(B);
  cout<<"\nNhap so thu tu cua phan tu can xoa: n= ";cin>>n;
  XoaPTn(B,n);
  Display(B);
  getch();

 }