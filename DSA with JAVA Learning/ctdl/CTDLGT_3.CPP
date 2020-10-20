#include<conio.h>
#include<iostream.h>
struct node
 {int info;
  node *link;
 }
struct list
 {node pt;
  int n; //kich thuoc danh sach
 }
/*void create(list &l)
{l.n=0;
} */
void main()
{clrscr();
 list integer;
 integer.n=0;
 node *first=new node;
 first->link=NULL;

 getch();
}