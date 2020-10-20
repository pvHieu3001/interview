#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<string.h>

struct DanhSach
 {
  int PhanTu[100];
  int n;  //so phan tu cua danh sach
 };

void TaoRong(DanhSach &DS)
 {
  DS.n=0;
 }

 //xuat danh sach
void Xuat(DanhSach DS)
 {
  cout<<"\n\n";
  for(int i=1;i<=DS.n;i++)
    cout<<DS.PhanTu[i];
    getch();
 }

//them vao dau danh sach
void ThemDau(DanhSach &DS,int phantu)
 {
  for(int i=DS.n;i>=1;i--)
    DS.PhanTu[i+1]=DS.PhanTu[i];
  DS.PhanTu[1]=phantu;
  DS.n++;
 }

//them vao cuoi danh sach
void ThemCuoi(DanhSach &DS,int phantu)
 {
  DS.n++;
  DS.PhanTu[DS.n]=phantu;
 }

//them vao vi tri k trong sanh sach
void ThemK(DanhSach &DS,int phantu,int k)
 {
  int i,n=DS.n,j=DS.n-k+1;
  for(i=1;i<=j;i++) //dich chuyen cac phan tu sau vi tri k lui 1
    {
     DS.PhanTu[n+1]=DS.PhanTu[n];
     n--;
    }
  //them vao vi tri k
  DS.PhanTu[k]=phantu;
  DS.n++;
 }

//tim vi tri thich hop va them vao sanh sach
void Them(DanhSach &DS,int phantu)
 {
  if(DS.n==0) ThemDau(DS,phantu);
  else if(phantu<=DS.PhanTu[1]) ThemDau(DS,phantu);
  else if(phantu>=DS.PhanTu[DS.n]) ThemCuoi(DS,phantu);
       else
	 for(int i=1;i<=DS.n-1;i++)
	   if(DS.PhanTu[i]<=phantu&&DS.PhanTu[i+1]>phantu)
	     {
	      ThemK(DS,phantu,i+1);i=DS.n;//ket thuc vong lap(chi them 1 lan)
	     }
 }

void NhapVaSapXep(DanhSach &DS)
 {
  char ch='1';
  cout<<"\nNhap vao mot day so nguyen: ";
  while(int(ch)>=48 && int(ch)<= 57)
    {
     ch=getch();cout<<ch;
     if(int(ch)>=48 && int(ch)<= 57)
       Them(DS,int(ch)-48);
    }
 }

void Tach(DanhSach &A,DanhSach &B,DanhSach &C)
 {
  for(int i=1;i<=A.n;i++)
    if(A.PhanTu[i]%2==0)
      Them(B,A.PhanTu[i]);
    else Them(C,A.PhanTu[i]);
 }


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
  cout<<"\n\n";
  Node *N=new Node;
  N=L.First->Right;
  for(int i=1;i<=L.n;i++)
    {
     cout<<N->Info;
     N=N->Right;
    }
  getch();
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

//them vao vi tri thich hop trong danh sach
void Add(List &L,int phantu)
 {
  if(Emty(L)) Add_LIFO(L,phantu);
  else if(phantu <= L.First->Right->Info) Add_LIFO(L,phantu);//them dau
  else if(phantu >= L.Last->Left->Info) Add_FILO(L,phantu);  //them cuoi
  else
   {
    Node *N;Node *M;
    N=L.First;  M=L.First->Right;
    for(int i=1;i<=L.n-1;i++)
      {
       N=N->Right;
       M=M->Right;
       if(N->Info <= phantu && M->Info > phantu)
	 {
	  Node *K=new Node;
	  K->Info=phantu;
	  K->Left=N;
	  K->Right=M;
	  N->Right=K;
	  M->Left=K;
	  L.n++;return;//dung vong lap, chi them 1 Node
	 }
      }
    delete N,M;
   }
 }

void Add_And_Insert(List &L)
 {
  char ch='1';
  cout<<"\nNhap vao mot day so nguyen: ";
  while(int(ch)>=48 && int(ch)<= 57)
    {
     ch=getch();cout<<ch;
     if(int(ch)>=48 && int(ch)<= 57)
       Add(L,int(ch)-48);
    }
 }

void Tach2(List &P,List &Q,List &R)
 {
  Node *N=P.First->Right;
  while(N->Right!=NULL)
    {
     if(N->Info%2==0)
       Add(Q,N->Info);
     else Add(R,N->Info);
     N=N->Right;
    }
 }



void main()
 {
  clrscr();
  cout<<"\n\n\nDoi voi danh sach luu tru bang mang";
  DanhSach A,B,C;
  TaoRong(A);
  TaoRong(B);
  TaoRong(C);
  NhapVaSapXep(A);
  cout<<"\nDanh sach sau khi sap xep";
  Xuat(A);
  Tach(A,B,C);
  cout<<"\nSau khi tach ta co 2 danh sach";
  cout<<"\nDanh sach gom so chan";
  Xuat(B);
  cout<<"\nDanh sach gom so le";
  Xuat(C);
  getch();

  cout<<"\n\n\nDoi voi danh sach luu tru bang con tro, DSLK doi";
  List P,Q,R;
  Create(P);
  Create(Q);
  Create(R);
  Add_And_Insert(P);
  cout<<"\nDanh sach sau khi sap xep";
  Display(P);
  Tach2(P,Q,R);
  cout<<"\nSau khi tach ta co 2 danh sach";
  cout<<"\nDanh sach gom so chan";
  Display(Q);
  cout<<"\nDanh sach gom so le";
  Display(R);
  getch();

 }