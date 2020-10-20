#include<conio.h>
#include<iostream.h>

struct sophuc
 {
  int thuc;int ao;
 };

sophuc operator +(sophuc x, sophuc y)
 { sophuc z;
	z.thuc=x.thuc+y.thuc;
	z.ao=x.ao+y.ao;
	return z;
 };

sophuc operator -(sophuc x, sophuc y)
 { sophuc z;
	z.thuc=x.thuc-y.thuc;
	z.ao=x.ao-y.ao;
	return z;
 };

void main()
{
  clrscr();
  cout<<"\nThuc Hanh Mon C++ \tBai 3\n";
  sophuc a,b,c;
	cout<<"a.thuc=";cin>>a.thuc;
	cout<<"a.ao=";cin>>a.ao;

	cout<<"b.thuc=";cin>>b.thuc;
	cout<<"b.ao=";cin>>b.ao;

	c=a+b;
    cout<<"\na+b="<<c.thuc<<","<<c.ao;

	c=a-b;
    cout<<"\na-b="<<c.thuc<<","<<c.ao;
	cin>>a.thuc;
}
