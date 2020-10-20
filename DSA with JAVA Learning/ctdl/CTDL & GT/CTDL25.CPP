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

void CreateS(Stack &S)
 {
  S.First=new Node;
  S.Last= new Node;
  S.First->Left=NULL;
  S.First->Right=S.Last;
  S.Last->Left=S.First;
  S.Last->Right=NULL;
  S.n=0;
 }

int EmtyS(Stack &S)
 {
  return(S.First->Right==S.Last);
 }

//hien thi ngan xep
void DisplayS(Stack &S)
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
void PushS(Stack &S,char phantu)
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
char PopS(Stack &S)
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
void AddS(Stack &S)
 {
  char ch='1';
  cout<<"\nNhap vao cac phan tu cua ngan xep, nhan ENTER de ket thuc\n\t: ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
       if(int(ch)!=13)PushS(S,ch);
    }
 }

//------------------------- Hang doi -----------------------------
struct Queue
 {
  Node *First;
  Node *Last;
  int n;
 };

void CreateQ(Queue &Q)
 {
  Q.First=new Node;
  Q.Last= new Node;
  Q.First->Left=NULL;
  Q.First->Right=Q.Last;
  Q.Last->Left=Q.First;
  Q.Last->Right=NULL;
  Q.n=0;
 }

int EmtyQ(Queue &Q)
 {
  return(Q.First->Right==Q.Last);
 }

//hien thi ngan xep
void DisplayQ(Queue &Q)
 {
  cout<<"\n";
  Node *N;
  N=Q.First->Right;
  for(int i=1;i<=Q.n;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
 }

//vao sau ra truoc (them vao dau danh sach)
void PushQ(Queue &Q,char phantu)
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
char PopQ(Queue &Q)
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
void AddQ(Queue &Q)
 {
  char ch='1';
  cout<<"\nNhap vao mot day ky tu, nhan ENTER de ket thuc\n\t: ";
  while(int(ch)!=13)
    {
     ch=getch();cout<<ch;
       if(int(ch)!=13)PushQ(Q,ch);
    }
 }

//-------- Kiem tra doi xung (dung Queue va Stack) ----------

void KiemTra(Queue &Q)
 {
  //chuyen nua chuoi ky tu tu Queue sang Stack
  Stack S; CreateS(S);
  int n=Q.n/2;char c;
  for(int i=1;i<=n;i++)
    {c=PopQ(Q);PushS(S,c);}

  cout<<"\n\nQ= ";DisplayQ(Q);
  cout<<"\n\nS= ";DisplayS(S);
  if(Q.n>S.n)cout<<"\nKy tu giua: "<<PopQ(Q);
  //kiem tra
  n=Q.n;int check=1;
  for(i=1;i<=n;i++)
   {if(PopQ(Q)!=PopS(S))check=0;}

  if(check) cout<<"\nChuoi vua moi nhap doi xung";
  else cout<<"\nChuoi vua moi nhap khong doi xung";
  getch();
 }

void main()
 {
  clrscr();int n;

  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  Queue Q; CreateQ(Q); AddQ(Q);
  cout<<"\nChuoi ky tu sau khi nhap:";
  DisplayQ(Q);
  KiemTra(Q);


  getch();

 }