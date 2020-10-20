#include <iostream>
#include<fstream>
#include <string>
#include <new>
#include<list>
using namespace std;
//=================

class Book
 {public:
  string bcode, title;
  int quantity,lended;
  double price;
  Book() {setData("","",0,0,0);}
  Book(string xBCode, string xTitle, int xQuantity, int xLended, double xPrice)
   {
      bcode=xBCode;title = xTitle;quantity=xQuantity;lended=xLended;price=xPrice;
   }
  void setData(string xBCode, string xTitle, int xQuantity, int xLended, double xPrice)
   {
      bcode=xBCode;title = xTitle;quantity=xQuantity;lended=xLended;price=xPrice;
   } 
  friend ostream& operator<<(ostream & os, const Book &t)
  {
     os<<"("<<t.bcode<<","<<t.title<<","<<t.quantity<<","<<t.lended<<","<<t.price<<")"<<endl;
     return(os);
  }
 };
class BNode
 {public:
  Book info;
  BNode * left, *right;
  BNode(Book x) {info=x;left = right = NULL;}
 };
 class MyQueue
 {list<BNode *> t;
  public:
  MyQueue() {}
  bool isEmpty() {return(t.empty());}
  void clear() {t.clear();}
  void enqueue(BNode * x)
   {t.insert(t.end(),x);
   }
  BNode * dequeue()
   {assert(!isEmpty());
    BNode * x = t.front();
    t.pop_front();
    return(x);
   }
  BNode * front()
   {assert(!isEmpty());
    return(t.front());
   }
 };

class BookList
 {public:
  BNode *root;
  BookList() {root = NULL;}
  bool isEmpty() {return(root == NULL);}
 void clear(BNode *p)
   {if(p==NULL) return;
    BNode * q = p;
    clear(p->left);
    clear(p->right);
    delete q;
   }
  void clear()
   {clear(root);
    root = NULL;
   }
  // ham visit
  void visit(BNode *p){
	
    if(p == NULL) cout<<"The BookNode doesnt exist\n";
    else cout << left << setw(4) << p->info.bcode << "| " 
              << left << setw(14) <<  p->info.title << "| " 
              << left << setw(8) << p->info.quantity << "| " << left << setw(8) << p->info.lended << "| " 
              << left << setw(6) << p->info.price << " |" << left << setw(5) << p->info.quantity*p->info.price << endl;
	
  }
  
  //breadth
 void breadth(BNode *p)
   {if(p==NULL) return;
    MyQueue q; BNode *r;
    q.enqueue(p);
    while(!q.isEmpty())
     {r = q.dequeue();
      visit(r);
      if(r->left!=NULL) {q.enqueue(r->left);}
      if(r->right!=NULL) {q.enqueue(r->right);}
     }

    
   }
 void preOrder(BNode *p)
   {if(p==NULL) return;
    visit(p);
    preOrder(p->left);
    preOrder(p->right);
   }
  void inOrder(BNode *p)
   {if(p==NULL) return;
    inOrder(p->left);
    visit(p);
    inOrder(p->right);
   }
 void insert(string xBCode, string xTitle, int xQuantity, int xLended, double xPrice)
   {
    bool ok = true;
    BNode *q = search(root,xBCode);
    if(q != NULL) ok = false;
    if(xQuantity < xLended) ok = false;
    if(xPrice < 0) ok =false;
    if(!ok); //cout<<"Invaild input"<<endl;
    else{
       Book x = Book(xBCode,xTitle,xQuantity,xLended,xPrice);
       BNode * r = new BNode(x);
       if(isEmpty()) {root = r; return;}
       BNode *f,*p;
       f=NULL; p=root;
       while(p!=NULL)
       {if(p->info.bcode==x.bcode)
          {cout<<"The key "<<x.bcode<<" already exists, no insertion"<<endl;
          return;
          }
       f=p;
        if(x.bcode<p->info.bcode) p = p->left; else p=p->right;
       }
      //if(f==NULL) {root = r;return;}
       if(x.bcode<f->info.bcode) f->left = r; else f->right = r;
    }
    
   }

	
	//ham search by bCode
 BNode * search(BNode *p,string  x)
   {if(p==NULL) return(NULL);
    if(p->info.bcode == x) return(p);
    if(x<p->info.bcode) 
      return(search(p->left,x));
       else
        return(search(p->right,x));
   }


   // ham load data from file booklist.txt
   void loadFromFile(){
 
     ifstream fin("book.txt");
     string s,a[100]; int n = 0;
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
                 int p1 = 0;
                 int p2 = toDouble(a[3],2);
                 insert(a[0],a[1],q1,p1,p2);
             }
             
         }
         fin.close();
         cout<<"File is successfully loaded"<<endl;
     }
  }
  
  // add infomation of a book and push to the booklist
  void addInfo(){
     string bCode, bTitle;
     int bQuantity,bLended ; double bPrice;
     cout<<"Enter the infomation of book"<<endl;
     while(true){
        cout<<"Enter the code of the book: "; cin>>bCode;
        cout<<"Enter the title of the book: "; cin>>bTitle;
        cout<<"Enter the quantity of the book: "; cin>>bQuantity;
        cout<<"Enter the lended of the book: "; cin>>bLended;
        cout<<"Enter the price of the book: "; cin>>bPrice;
        if((search(root,bCode) == NULL) && (bQuantity >= bLended) && (bPrice > 0)) break;
        else cout<<"The infomation you entered is invaild! Plz reenter"<<endl;
     }
     insert(bCode,bTitle,bQuantity,bLended,bPrice);
  }
  //ham save to file
  void inOrder2(MyQueue &q, BNode *p)
 {
    if (p == NULL) return;
    inOrder2(q,p->left);
    q.enqueue(p);
    inOrder2(q,p->right);
 }
   
  void saveToFile(){
     MyQueue q;
     inOrder2(q,root);
     char fname[30];
     while(true){
        fflush(stdin);
        cout<<"Enter file name: "; cin.getline(fname,29,'\n');
        ofstream fout(fname);
        if(!fout.is_open()){
    	     cout<<"Can not open file. Make sure the file name exists. Plz reenter"<<fname<<endl;
        }
        else{
           
           while(!q.isEmpty()){
              BNode *p = q.dequeue();
              fout << left << setw(4) << p->info.bcode << "| " << left << setw(14) <<  p->info.title << "| "
                   << left << setw(8) << p->info.quantity << "| " << left << setw(8) << p->info.lended << "| " 
                   << left << setw(6) << p->info.price <<endl;
           }
           fout.close();
           cout<<"Saved to "<<fname<<endl;
           break;
        }   
     }
  }
  
  //ham check BCode co trong book list
  
  void checkBCode(){
     string pcode;
     cout<<"Enter Bcode that you want to search: ";cin>>pcode;
     if(search(root,pcode) == NULL) cout<<"Not found"<<endl;
     else {
        cout<<"Found"<<endl;
        visit(search(root,pcode));
     }
  }
  
  //ham delete by copying
   void deleByCopy(string xBCode)
   {BNode *f, *p, *r;
    f=NULL; p=root;
    while(p!=NULL)
     {if(p->info.bcode==xBCode) break;
      f=p;
      if(xBCode<p->info.bcode) p=p->left; else p=p->right;
     }
    if(p==NULL) return; // not found

    // p is a leaf node
    if(p->left==NULL && p->right==NULL)
     {if(f==NULL) // p=root
       {root = NULL;
       }
       else
        {if(f->left==p) f->left=NULL; else f->right=NULL;
        }
      delete p;
      return;
     }

    // p has a left son only
    if(p->left!=NULL && p->right==NULL)
     {if(f==NULL) // p=root
       {root = p->left;
       }
       else
        {if(f->left==p) f->left=p->left; else f->right=p->left;
        }
      delete p;
      return;
     }
 
    // p has a right son only
    if(p->left==NULL && p->right!=NULL)
     {if(f==NULL) // p=root
       {root = p->right;
       }
       else
        {if(f->left==p) f->left=p->right; else f->right=p->right;
        }
      delete p;
      return;
     }


    // p has both sons
    if(p->left!=NULL && p->right!=NULL)
     {// find the right most node on the left son
      BNode * q = p->left;
      BNode *frp, *rp; frp=NULL; rp=q;
      while(rp->right!=NULL) {frp=rp;rp=rp->right;}
      // rp is the rightmost node on the left son
      p->info = rp->info;
      if(frp==NULL) // q is the right most node
       {p->left = q->left;
       }
       else
        {frp->right = rp->left;
        } 
      delete rp;

     }

   }
  void dele(){
     string bCode;
     while(true){
        cout<<"Enter BCode to delete: "; cin >>bCode;
        if(search(root,bCode) == NULL) cout<<"The bcode doesnt exists, plz reenter"<<endl;
        else break;
     }
     deleByCopy(bCode);
  }
  //count number of books
  int count(BNode * p)
   {if(p==NULL) return(0);
    int k, h,r;
    k = count(p->left);
    h = count(p->right);
    r = k+h+1;
    return(r);
   }
  //balance
   void inOrder3(Book a[], BNode *p)
   {if(p==NULL) return;
    inOrder3(a,p->left);
    a[k++] = p->info;
    inOrder3(a,p->right); 
   }
  void balance(Book a[], int i, int j)
   {if(i>j) return;
    int h = (i+j)/2;
    insert(a[h].bcode,a[h].title,a[h].quantity,a[h].lended,a[h].price);
    balance(a,i,h-1);
    balance(a,h+1,j);
   }

  int k;
  void balance()
   {int n = count(root);
    Book * a = new Book[n];
    k=0;
    inOrder3(a,root);
    clear();
    balance(a,0,n-1);
   }
};
