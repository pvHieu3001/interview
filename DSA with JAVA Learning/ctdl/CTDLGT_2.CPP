#include<conio.h>
#include<iostream.h>
int n,m1[100],m2[100];
void nhap1(int n)
{cout<<"\n  nhap vao "<<n<<" phan tu cua mang m1\n";
 for(int i=1;i<=n;i++)
 {cout<<"\t";cin>>m1[i];}
 cout<<"\nmang m1 da duoc nhap xong\n";
}

void nhap2(int n)
{cout<<"\n  nhap vao "<<n<<" phan tu cua mang m2 (Luu dao nguoc)\n";
 for(int i=1;i<=n;i++)
 {cout<<"\t";cin>>m1[n-i+1];}
 cout<<"\nmang m1 da duoc nhap xong\n";
}
void xuat(int &mang[])
{for(int i=1;i<=n;i++)
  cout<<"  "<<mang[i];
}

void main()
{clrscr();
 cout<<"\n\tnhap vao so phan tu cua mang n= ";cin>>n;
 nhap1(n);
 nhap2(n);
 xuat(*m2[])
 getch();
}