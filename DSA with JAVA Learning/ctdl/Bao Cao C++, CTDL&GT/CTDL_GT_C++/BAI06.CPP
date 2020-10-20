#include "conio.h"
#include "stdio.h"
#include "iostream.h"
#include "math.h"
//------------------- Dinh nghia lop phan so -------------------------------

class PhanSo
 {
  private:
   int TuSo;  //Numerator
   int MauSo; //Denominator
  public:
   //--------- Khai bao phuong thuc ---------
   PhanSo operator + (PhanSo b);
   PhanSo operator - (PhanSo b);
   PhanSo operator * (PhanSo b);
   PhanSo operator / (PhanSo b);
      int operator > (PhanSo b);
      int operator >=(PhanSo b);
      int operator < (PhanSo b);
      int operator <=(PhanSo b);
      int operator ==(PhanSo b);
      int operator !=(PhanSo b);
   void RutGonPS();
   int getTS();  		//lay tu so
   int getMS();         		//lay mau so
   void nhap();                	//nhap phan so
   void nhap(int a, int b);   	//nhap PS
   void xuat();                	//xuat phan so

 };

//----------------------- Chuong Trinh Chinh --------------------------------

void main()
 {
  clrscr();
  cout<<"\nThuc Hanh Mon C++ \tBai 6\n";
  PhanSo a,b,c;
  a.nhap();
  b.nhap();
  //------- Kiem Tra Cac Truong Hop -------


  c=a+b;
  c.RutGonPS();
  cout<<"a+b=";c.xuat();

  c=a-b;
  c.RutGonPS();
  cout<<"a-b=";c.xuat();

  c=a*b;
  c.RutGonPS();
  cout<<"a*b=";c.xuat();

  c=a/b;
  c.RutGonPS();
  cout<<"a/b=";c.xuat();

  if (a==b)
   cout<<"\nPS a bang PS b";
  else cout<<"\nPS b khac PS a";
  if (a!=b)
   cout<<"\nPS a khac PS b";
  else cout<<"\nPS b bang PS a";

  if (a>b)
   cout<<"\nPS a lon hon PS b";
  else if(b>a)
   cout<<"\nPS b lon hon PS a";
       else cout<<"\na=b";

  if (a>=b)
   cout<<"\nPS a lon hon hoac bang PS b";
  else cout<<"\nPS b lon hon hoac bang PS a";

  if (a<b)
   cout<<"\nPS a be hon PS b";
  else if (b<a)
   cout<<"\nPS b be hon PS a";
       else cout<<"\nb=a";

  if (a<=b)
   cout<<"\nPS a be hon hoac bang PS b";
  else cout<<"\nPS b be hon hoac bang PS a";

  getch();
}



//----------------------- Dinh Nghia Cac Phuong Thuc  -----------------------

PhanSo PhanSo::operator + (PhanSo b)
 {
  PhanSo c;
  c.nhap(TuSo*b.getMS()+MauSo*b.getTS(),MauSo*b.getMS());
  return c;
 }

PhanSo PhanSo::operator - (PhanSo b)
 {
  PhanSo c;
  c.nhap(TuSo*b.getMS()-MauSo*b.getTS(),MauSo*b.getMS());
  return c;
 }

PhanSo PhanSo::operator * (PhanSo b)
 {
  PhanSo c;
  c.nhap(TuSo*b.getTS(),MauSo*b.getMS());
  return c;
 }

PhanSo PhanSo::operator / (PhanSo b)
 {
  PhanSo c;
  c.nhap(TuSo*b.getMS(),MauSo*b.getTS());
  return c;
 }

int PhanSo::operator > (PhanSo b)
 {
 if(TuSo*b.getMS()>b.getTS()*MauSo)
  return 1;
 else return 0;
 }

int PhanSo::operator >= (PhanSo b)
 {
 if(TuSo*b.getMS()>=b.getTS()*MauSo)
  return 1;
 else return 0;
 }

int PhanSo::operator < (PhanSo b)
 {
 if(TuSo*b.getMS()<b.getTS()*MauSo)
  return 1;
 else return 0;
 }

int PhanSo::operator <= (PhanSo b)
 {
 if(TuSo*b.getMS()<=b.getTS()*MauSo)
  return 1;
 else return 0;
 }

int PhanSo::operator == (PhanSo b)
 {
 if(TuSo*b.getMS()==b.getTS()*MauSo)
  return 1;
 else return 0;
 }

int PhanSo::operator != (PhanSo b)
 {
 if(TuSo*b.getMS()!=b.getTS()*MauSo)
  return 1;
 else return 0;
 }

void PhanSo::RutGonPS ()
{
  int UCLN;
  int n=abs(TuSo),m=abs(MauSo);
  while (n != 0 && m != 0)
    if (n>m)
      n -= m;
    else
      m -= n;
  if (n != 0)
    UCLN= n;
  else
    UCLN= m;
  TuSo=TuSo/UCLN;
  MauSo=MauSo/UCLN;
}

int PhanSo::getTS()
     {
      return TuSo;
     }

int PhanSo::getMS()
     {
      return MauSo;
     }

void PhanSo::nhap()
     {
      cout<<"Tu So a="; cin>>TuSo;
      cout<<"MauSo a="; cin>>MauSo;
     }

void PhanSo::nhap(int a, int b)
     {
      TuSo=a;
      MauSo=b;
     }

void PhanSo::xuat()
     {
      cout<<TuSo<<"/"<<MauSo<<"\n";
     }

//---------------------------------- End  -----------------------------------