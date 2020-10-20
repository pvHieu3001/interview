#include<iostream.h>
#include<conio.h>

class hcn
{
 private:
  int chieudai;
  int chieurong;
 public:
  void nhapsl()
   {
    cout<<"nhap chieu dai:";
    cin>>chieudai;
    cout<<"nhap chieu rong:";
    cin>>chieurong;
   }

  int dien_tich()
   {
    return chieudai*chieurong;
   }

  int chuvi()
   {
    return 2*(chieudai+chieurong);
   }

  void in()
   {
    cout<<"\nchieu dai ="<<chieudai;
    cout<<"\nchieu rong="<<chieurong;
    cout<<"\nchu  vi  ="<<chuvi();
    cout<<"\ndien tich="<<dien_tich();
   }

};

void main()
 {
  clrscr();
  hcn H;
  cout<<"\nThuc Hanh Mon C++ \tBai 5\n";
  cout<<"\nnhap cac  tham so\n";
  H.nhapsl();
  H.in();
 getch();
 }


