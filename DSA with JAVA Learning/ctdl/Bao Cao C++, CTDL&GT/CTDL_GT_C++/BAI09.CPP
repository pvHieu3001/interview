#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>

void KhoiDong();//Khoi Dong che do do hoa
void HuyBo();   //Huy Bo che do do hoa

class diem
 {
    private:
       int x,y;
    public:
       void nhap();
       void nhap(int x0,int y0)
	{x=x0;y=y0;}
       void TinhTien();
       void QuayGocToaDo();
       double KhoangCach(diem B)
	{
	 double d;
	 d=sqrt(pow((*this).x-B.getx(),2)+pow((*this).y-B.gety(),2));
	 return d;
	}
       void hien();
       int getx()
	{return x;}
       int gety()
	{return y;}
 };

void diem::nhap()
      {
	cout<<"\n\n  Nhap hoanh do diem: x= ";
	cin>>x;
	cout<<"  Nhap tung  do diem: y= ";
	cin>>y;
      }

void diem::TinhTien()
{
 int x0,y0,kx,x1,y1;
 cout<<"\n\n  Nhap vecto tinh tien:";
 cout<<"\n  X=";cin>>x1;
 cout<<"\n  Y=";cin>>y1;

 KhoiDong();

    cleardevice();
    setviewport(320,240,639,479,0);
    //ve hinh
    setbkcolor(7);//mau nen la mau trang
    setcolor(BLUE);//mau ve la mau xanh
    kx=10;//he so truc x
    y0=0;//Y goc toa do
    x0=0;//X goc toa do
    // ve truc toa do toi thieu
    line(x0-300,y0,x0+300,y0);//ve truc hoanh
    outtextxy(x0+300,y0-3,">x");
    line(y0,y0-230,x0,y0+230);// ve truc tung
    outtextxy(x0-3,y0-230,"^y");
    outtextxy(x0-10,y0+5,"0");

 x1=x1+x;
 y1=y1+y;
 x=x*kx;
 y=-y*kx;
 x1=x1*kx;
 y1=-y1*kx;

 fillellipse(x, y, 3, 3); getch();
 fillellipse(x1,y1, 3, 3);
 getch();
 HuyBo();
 textbackground(9);
 clrscr();

}
	    //----------------------------------------

void main()
 {
  clrscr();
  diem A;
  A.TinhTien();
  getch();
 }
	    //----------------------------------------


void KhoiDong()
{
 clrscr();
 int gd=DETECT,gm,maloi;
  //khoi tao che do do hoa
  initgraph(&gd,&gm,"C:\BORLADNC\BGI");
  maloi=graphresult();
  if(maloi!=0)
   {cout<<"loi khoi tao do hoa\n";
    cout<<"co loi "<<grapherrormsg(maloi);
    getch();
    //exit(1);//thoat khoi chuong trinh
   }
}

void HuyBo()
{
 closegraph();
 textmode(C4350);
 textbackground(9);
 clrscr();
 //cleardevice();
 //textbackground(1);
}