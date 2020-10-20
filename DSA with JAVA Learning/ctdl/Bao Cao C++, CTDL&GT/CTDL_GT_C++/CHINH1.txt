#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream.h>
void main ()
{
clrscr();
struct sinhvien
{
char* ten,*diachi,*dienthoai;
long ngaysinh;
};
sinhvien a;
a.ten="tongvanchinh";
a.diachi="ninh binh";
a.ngaysinh=10121988;
cout<<"ten cua ban la :"<<a.ten<<"\n";

sinhvien danhsach[30];
long soluong;
int i,vitri;
for (i=1;i<=10;i++)
{
danhsach[i].ngaysinh=i;
cout<<"ngay sinh cua "<<i<<" la:"<<danhsach[i].ngaysinh<<"\n";
}

/*xoa phan tu trong danh sach
cout<<"nhap vao vi tri can xoa";
cin>>vitri;

for (i=vitri;i<=10;i++)
 {
 danhsach[i]=danhsach[i+1];
 }

for (i=1;i<=9;i++)
{
cout<<"ngay sinh cua "<<i<<" la:"<<danhsach[i].ngaysinh<<"\n";
} */

//chen vao danh sach 1 phan tu
sinhvien tam;
tam.ngaysinh=11;
cout<<"nhap vao vi tri can chen: ";
cin>>vitri;

for (i=10;i>=vitri;i--)
{
danhsach[i+1]=danhsach[i];
}
danhsach[vitri+1]=tam;

for (i=1;i<=11;i++)
{
cout<<"ngay sinh cua "<<i<<" la:"<<danhsach[i].ngaysinh<<"\n";
}
 getch();
}