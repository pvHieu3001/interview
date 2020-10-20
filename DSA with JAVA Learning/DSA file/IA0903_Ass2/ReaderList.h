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
   void visit(RNode *p){
      if(p == NULL) cout<<"The ReaderNode doesnt exist\n";
      else cout << left << setw(4) << p->info.rcode << "| " 
              << left << setw(14) <<  p->info.name << "| " 
              << left << setw(8) << p->info.byear << endl;
   }
   void traverse(){
      if(isEmpty())
		{
			cout << "The ReaderList is empty" << endl;
		}
		else
		{
			RNode *p = head;
			while (p!=NULL)
			{
				visit(p);
				p=p->next;
			}		
		}	
   }
   
  RNode *searchR(string rCode){
     	RNode *p = head;
		while (p != NULL)
		{
			if(p->info.rcode == rCode)
				return (p);
			p = p->next;
		}
		return NULL;
  }
  void addLast(string xRCode, string xName, int xByear)
   {
      bool ok = true;
      RNode *q = searchR(xRCode);
      if(q != NULL) ok = false;
      if(xByear > 2010 || xByear < 1900) ok = false;
      if(!ok) cout<<"Invaild input"<<endl;
      else
      {
      Reader x = Reader(xRCode,xName,xByear);
      RNode *q = new RNode(x, NULL);
		if(isEmpty())
		{
			head = tail = q;
		}
		else
		{
			tail -> next = q;
			tail = q;
		}
	  }
   }
   // ham load data from file userlist.txt
   void loadFromFile(){
 
     ifstream fin("userlist.txt");
     string s,a[100]; int n = 1;
     int i = 0;
     if(!fin.is_open()){
         cout<<"File doesn't exist!";
         return;
     }
     else{
         while(fin.good()){
             s = "";
             getline(fin,s,'\n');i++;
             if(i==1) continue;
             else{
                 s = trim(s);
                 if(s.size() == 0) continue;
                 split(s,a,n,'|');
                 int q1 = toInteger(a[2]);
                 addLast(a[0],a[1],q1);
             }
             
         }
         fin.close();
         //cout<<"File is successfully loaded"<<endl;
     }
  }
  //ham save to file
  void saveToFile(){
     char fname[30];
     while(true){
        fflush(stdin);
        cout<<"Enter file name: "; cin.getline(fname,29,'\n');
        ofstream fout(fname);
        if(!fout.is_open()){
    	     cout<<"Can not open file. Make sure the file name exists. Plz reenter"<<fname<<endl;
        }
        else{
           RNode *p = head;
           while(p){
              fout << left << setw(4) << p->info.rcode << "| " << left << setw(14) <<  p->info.name << "| "
                   << left << setw(8) << p->info.byear <<endl;
              p = p->next;
           }
           fout.close();
           cout<<"Saved to "<<fname<<endl;
           break;
        }   
     }
  }
  
  // input and add data to tail
    void addInfoToTail(){
     string rCode, rName;
     int rByear;
     cout<<"Enter the infomation of book"<<endl;
     while(true){
        cout<<"Enter the code of the Reader: "; cin>>rCode;
        cout<<"Enter the name of the Reader: "; cin>>rName;
        cout<<"Enter the birthyear of the Reader: "; cin>>rByear;
        if((searchR(rCode) == NULL) && rByear < 2010 && rByear > 1900) break;
        else cout<<"The infomation you entered is invaild! Plz reenter"<<endl;
     }
     addLast(rCode,rName,rByear);
  }
  
  void deteR(RNode *p){
     if(p == NULL) return;
     if(isEmpty()) return;
     RNode *f = NULL, * q = head, *r;
     while (p != NULL){
        if(q == p) break;
        f = q;
        q = q->next;
     }
     if(f == NULL) //p is head
     {
        head = head ->next;
        delete p;
     }
     r = p->next;
     f->next = r;
     delete p;
     if (f->next == NULL) tail = f;
  }
  
  void deleR(){
     string rCode;
     cout<<"Enter the readercode to delete: "; cin>>rCode;
     deteR(searchR(rCode));
  }

};
