/* This program contains 2 parts: (1) and (2)
   YOUR TASK IS TO COMPLETE THE PART  (2)  ONLY
 */
//(1)==============================================================
#include <iostream>
#include <string>
#include <new>
using namespace std;
//=================
class Reader
 {public:
  string rcode, name;
  int byear;
  Reader() {}
  Reader(string xRCode, string xName, int xByear)
   {rcode=xRCode;name = xName;byear=xByear;
   }
  void setData(string xRCode, string xName, int xByear)
   {rcode=xRCode;name = xName;byear=xByear;
   }
 friend ostream& operator<<(ostream & os, const Reader &t)
  {os<<"("<<t.rcode<<","<<t.name<<","<<t.byear<<")"<<endl;
   return(os);
  } 
 };
class RNode
 {public:
  Reader info;
  RNode * next;
  RNode(Reader x, RNode *p) {info=x;next=p;}
  RNode(Reader x) {info=x;next=NULL;}
 };

class ReaderList
 {public:
  RNode * head, *tail;
  ReaderList() {head=tail=NULL;}
  bool isEmpty() {return(head==NULL);}
  void clear()
   {RNode * p, *q; p = head;
     while(p!=NULL)
      {q=p;p=p->next;delete q;
      }
    head=tail=NULL;
   }

 void fvisit(RNode * const &p, ofstream & fou)
   {Reader x;
     if(p!=NULL) 
      {x=p->info;
       fou<<"("<<x.rcode<<","<<x.name<<","<<x.byear<<")"<<endl;
      }
   }

 void ftraverse(ofstream & fou)
   {RNode * p = head;
    while(p!=NULL)
      {fvisit(p,fou); // this statement writes information of the node p to the file
       p=p->next;
      }
    fou<<"\r\n";
   }

  void loadData(int k)  //do not edit this function
   {string a[100],b[100];int c[100],d[100],e[100],m,n,p,q,r,i;
    readLineToStrArray("data.txt", k,a,m);
    readLineToStrArray("data.txt", k+1,b,n);
    readLineToIntArray("data.txt", k+2,c,p);
    for(i=0;i<m;i++) addLast(a[i],b[i],c[i]);
   }


//===========================================================================
//(2)===YOU CAN EDIT OR EVEN ADD NEW FUNCTIONS IN THE FOLLOWING PART========
//===========================================================================
  /*
    Conditions for addLast:
    ======================
    rcode must be unique
    byear must be in the interval [1900,2010] 
  */
  void addLast(string xRCode, string xName, int xByear)
   {

   }

//=====================================================================
// Test add to the end
  void f9()
    {/* You do not need to edit this function. Your task is to complete the addLast  function
        above only.
     */
     clear();
     loadData(19);
     char * fname = "f9.txt";
     if(exist(fname)) remove(fname);
     ofstream fou; fou.open(fname,ios::app);
     ftraverse(fou);
     fou.close();
    }  

 };
//===================================================
