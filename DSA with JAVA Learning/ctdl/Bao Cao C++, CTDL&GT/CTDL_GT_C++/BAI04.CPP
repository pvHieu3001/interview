#include<stdio.h>
#include<conio.h>
#include<iostream.h>

struct SinhVien
 {
   private:
     char ht[50];
     float toan,ly,hoa,tb;
   public:
     void nhap()
       {
	 toan=ly=hoa=tb=-1;
	 cout<<"\n Nhap thong tin Sinh Vien";
	 cout<<"\n Ho va ten: "; gets(ht);
	 while(toan<0||toan>10)
	  {cout<<"\n Diem Toan = ";cin>>toan;};
	 while(ly<0||ly>10)
	  {cout<<" Diem Ly = ";  cin>>ly;};
	 while(hoa<0||hoa>10){cout<<" Diem Hoa = "; cin>>hoa;};
	 tb=(toan+ly+hoa)/3;
       }
     void in()
       {
	 cout<<"\n Thong tin cua Sinh Vien";
	 cout<<"\n Ho va Ten: "<<ht;
	 cout<<"\n Diem cac mon: ";
	 cout<<"\n\tToan = "<<toan;
	 cout<<"\tLy = "<<ly;
	 cout<<"\tHoa= "<<hoa;
         cout<<"\tDiem TB = "<<tb;
	 getch();
       }
    float getTB()
      {return tb;}
 };

void main()
 {
  clrscr();
  cout<<"\nThuc Hanh Mon C++ \tBai 4\n";
  int i=0,j=0,n;
  SinhVien SV[10];
  for(i=1;i<=4;i++)
    SV[i].nhap();
  for(i=1;i<=4;i++)
    for(j=i+1;j<=4;j++)
       if(SV[i].getTB()<SV[j].getTB())
	 {
	  SV[0]=SV[i];	//SV[0] la SV trung gian
	  SV[i]=SV[j];
	  SV[j]=SV[0];
	 }

  cout<<"\n\tBa Sinh Vien co diem TrungBinh cao nhat: ";
  for(i=1;i<=3;i++)
    {
     cout<<"\n";
     SV[i].in();
    }
  getch();
 }