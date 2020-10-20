#include<iostream.h>
#include<conio.h>

class Diem
 {
 private:
  int x;
  int y;
 public:
   Diem(int x0,int y0)
    {
     x=x0;
     y=y0;
    }

   Diem() 	//mac dinh la goc toa do
    {x=0;y=0;}

   void Display()
    {cout<<"O("<<x<<","<<y<<")";}
 };

class HinhTron:private Diem
 {
  private:
   int R;
  public:

   HinhTron(int x0,int y0, int bk):Diem(x0,y0)
    {R=bk;}

   HinhTron():Diem()
    {R=1;}

   int getR()
    {return R;}
   void Display()
    {
     Diem::Display();
     cout<<" R= "<<R;
    }

 };

void main()
 {
  clrscr();
  HinhTron C(2,5,6);
  C.Display();
  cout<<"\n\nBan Kinh= "<<C.getR();


  getch();
 }