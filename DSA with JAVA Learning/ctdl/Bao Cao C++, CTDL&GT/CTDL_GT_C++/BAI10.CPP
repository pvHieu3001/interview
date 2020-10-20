#include<iostream.h>
#include<conio.h>
#include<math.h>

class point
 {
  private:
   int x,y;
  public:
   point()
    {
     x=0,y=0;	//mac dinh x,y=0, goc toa do
    }
   point(int x0,int y0)
    {
     x=x0;y=y0;	//ham tao
    }
   void in()
    {cout<<"\n\t("<<x<<" ,"<<y<<")";}
 };

class HinhTron:public point
 {
  private:
   float R;	//ban kinh
  public:
   HinhTron():point()
    {R=1;}	//mac dinh
   HinhTron(int x0,int y0,float BK):point(x0,y0)
    {R=BK;}
   getR()
    {return R;}
   void display(int x0,int y0)
    {cout<<"\n\t("<<x0<<" ,"<<y0<<")"<<" R= "<<R;}
 };


void main()
 {
  clrscr();
  cout<<"\nThuc Hanh Mon C++ \tBai 10\n";
  HinhTron C(5,2,3);
  C.in();
  cout<<" "<<C.getR();
  getch();
 }