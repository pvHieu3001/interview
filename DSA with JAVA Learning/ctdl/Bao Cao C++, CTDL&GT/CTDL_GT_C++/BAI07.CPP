#include<conio.h>
#include<iostream.h>

class sophuc
 {
  private:
    int thuc;int ao;
  public:
   void nhap()
     {
      cout<<"thuc=";cin>>thuc;
      cout<<"ao=";cin>>ao;
     }

   void nhap(int a,int b)
     {
      thuc=a;ao=b;
     }
   void xuat()
     {
      cout<<thuc<<":"<<ao;
     }

   int getT()
     {
      return thuc;
     }

   int getA()
     {
      return ao;
     }
   sophuc operator +(sophuc y)
	 {
	  sophuc z;
	  z.nhap(thuc+y.getT(),ao+y.getA());
	  return z;
	 }

   sophuc operator -(sophuc y)
     {
      sophuc z;
      z.nhap(thuc-y.getT(),ao-y.getA());
      return z;
     }
 };

void main()
{
  clrscr();
  cout<<"\nThuc Hanh Mon C++ \tBai 3\n";
  sophuc a,b,c;
  a.nhap();
  b.nhap();

  c=a+b;
  cout<<"\na+b= ";c.xuat();
  c=a-b;
  cout<<"\na-b= ";c.xuat();
  getch();
}
