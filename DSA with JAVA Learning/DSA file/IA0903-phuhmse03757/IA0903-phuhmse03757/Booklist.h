/* This program contains 2 parts: (1) and (2)
   YOUR TASK IS TO COMPLETE THE PART  (2)  ONLY
 */
//(1)==============================================================
#include <iostream>
#include <string>
#include <new>
using namespace std;
//=================
class Book
 {public:
  string bcode, title;
  int quantity,lended;
  double price;
  Book() {}
  Book(string xBCode, string xTitle, int xQuantity, int xLended, double xPrice)
   {bcode=xBCode;title = xTitle;quantity=xQuantity;lended=xLended;price=xPrice;
   }
  void setData(string xBCode, string xTitle, int xQuantity, int xLended, double xPrice)
   {bcode=xBCode;title = xTitle;quantity=xQuantity;lended=xLended;price=xPrice;
   }
   
 friend ostream& operator<<(ostream & os, const Book &t)
  {os<<"("<<t.bcode<<","<<t.title<<","<<t.quantity<<","<<t.lended<<","<<t.price<<")"<<endl;
   return(os);
  } 
 };
class BNode
 {public:
  Book info;
  BNode * next;
  BNode(Book x, BNode *p) {info=x;next=p;}
  BNode(Book x) {info=x;next=NULL;}
 };

class BookList
 {public:
  BNode * head, *tail;
  BookList() {head=tail=NULL;}
  bool isEmpty() {return(head==NULL);}
  void clear()
   {BNode * p, *q; p = head;
     while(p!=NULL)
      {q=p;p=p->next;delete q;
      }
    head=tail=NULL;
   }

 void fvisit(BNode * const &p, ofstream & fou)
   {Book x;
     if(p!=NULL) 
      {x=p->info;
       fou<<"("<<x.bcode<<","<<x.title<<","<<x.quantity<<","<<x.lended<<","<<x.price<<")"<<endl;
      }
   }

 void ftraverse(ofstream & fou)
   {BNode * p = head;
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
    readLineToIntArray("data.txt", k+3,d,q);
    readLineToIntArray("data.txt", k+4,e,r);
    for(i=0;i<m;i++) addLast(a[i],b[i],c[i],d[i],e[i]);
   }


//===========================================================================
//(2)===YOU CAN EDIT OR EVEN ADD NEW FUNCTIONS IN THE FOLLOWING PART========
//===========================================================================
  /*
    Conditions for addLast:
   ==================
    bcode must be unique
    quantity>0
    lended>=0
    quantity >= lended
    price>0
  */
  void addFirst(Book x)
    {
        BNode *p = new BNode(x);
        if(isEmpty())
        {
            head = tail = p;
        }
        else
        {
            p->next = head;
            head = p;
        }
    }
    void addLast(Book x)
    {
        if(isEmpty()) addFirst(x);
        else
        {
            BNode *p = new BNode(x);
            tail->next = p;
            tail = p;
        }
    }
  void addLast(string xBCode, string xTitle, int xQuantity, int xLended, double xPrice)
   {
	Book x;
	if(xBCode!=x.bcode && xQuantity > 0 && xLended>=0 && xQuantity>=xLended && xPrice>0){
		x= Book(xBCode, xTitle, xQuantity, xLended, xPrice);
	if(isEmpty()) addFirst(x);
        else
        {
            BNode *p = new BNode(x);
            tail->next = p;
            tail = p;
        }
	}
	
   }

//=====================================================================
// Test add to the end
  void f1()
    {/* You do not need to edit this function. Your task is to complete the addLast  function
        above only.
     */
     clear();
     loadData(1);
     char * fname = "f1.txt";
     if(exist(fname)) remove(fname);
     ofstream fou; fou.open(fname,ios::app);
     ftraverse(fou);
     fou.close();
    }  

//=====================================================================
// Test load data from file
  void f2()
    {
     clear();
     char * fname = "f2.txt";
     if(exist(fname)) remove(fname);
     ofstream fou; fou.open(fname,ios::app);
    //--------------------------------------------------------
    /* You should write here statements  to read data from the file book.txt
        and using the addLast function to add data to the list.
        The book.txt file contains 4 items: bcode, title, quantity, price
         (lended is absent and set to 0)
     */
    string s,r;
    ifstream fin;
	fin.open("book.txt");
	char a[200], b[20],c[20],d[20],e[20];
	fin.getline(a,200);
		while(fin.good()){
		Book x;
		strcpy(d,"");
		fin.getline(a,20,'|');
		fin.getline(b,20,'|');
		fin.getline(c,20,'|');
		fin.getline(d,20,'\n');
		if(strlen(d)==0) break;
		x.bcode=a; x.title = b; x.quantity = atoi(c); x.price = atof(d); 
		x.bcode.erase(remove(x.bcode.begin(), x.bcode.end(), ' '), x.bcode.end() ); 
		x.title.erase(remove(x.title.begin(), x.title.end(), ' '), x.title.end() );
		addLast(x.bcode,x.title,x.quantity,0,x.price); 	
	}
	fin.close();

    //--------------------------------------------------------
     ftraverse(fou);
     fou.close();
    }

//=====================================================================
// Test save to file
 void f3()
    {
     clear();
     char * fname = "f3.txt";
     if(exist(fname)) remove(fname);
     loadData(7); // This statement load data from data.txt file. You do not need to load again

    //--------------------------------------------------------
    /* You should write here statements to complete the following task:
        traverse the list from head to tail and write data to the file f3.txt in format:
        bcode  ||  title  ||  quantity   ||   lended   ||   price  
     */
	ofstream fou (fname);
		BNode* p = head;
		while (p!=NULL){
			fou<<p->info.bcode<<"  ||  "<<p->info.title<<"  ||  "<<p->info.quantity<<"  ||  "
			<<p->info.lended<<"  ||  "<<p->info.price<<endl;
			p = p->next;
		}
		fou.close();

    //--------------------------------------------------------
    }  

//=====================================================================
// Test search by title
  void f4() 
   {
    clear();
    char * fname = "f4.txt";
    if(exist(fname)) remove(fname);
    loadData(13);
    ofstream fou; fou.open(fname,ios::app);
    ftraverse(fou);
    string xTitle = "T9";
    BookList  h;
    //--------------------------------------------------------
    /* You should write here statements 
       to add to the list h all elements having title = xTitle */
	BNode* p = head;
			while (p!=NULL)
			{
				if (p->info.title == xTitle)
				{
					fvisit(p,fou);
				}
				p = p->next;
			}

    //--------------------------------------------------------
    h.ftraverse(fou);
    fou.close();
   }

//=====================================================================
// Test delete by title
BNode * searchByTitle(string xTitle)
	{
		BNode* p = head;
		while (p!=NULL){
			if (p->info.title == xTitle)
			return(p);
			p = p->next;
		}
		return (NULL);
	}	
	void dele(BNode * q)
	{ 
		if(isEmpty()) return;
		BNode *f,*p; f=NULL;p=head;
		while(p!=NULL)
		{ 
			if(p==q) break;
			f=p; p=p->next;
		}
		if(p==NULL) return;
		if(f==NULL){ 
			head = head->next;
			if(head==NULL) tail=NULL;
			return;
		}
		f->next = p->next;
		if(f->next == NULL) tail=f;
	}
  void f5()
   {
    clear();
    char * fname = "f5.txt";
    if(exist(fname)) remove(fname);
    loadData(13);
    ofstream fou; fou.open(fname,ios::app);
    ftraverse(fou);
    string xTitle = "T9";
    //--------------------------------------------------------
    /* You should write here statements 
       to delete the first node having title = xTitle */
BNode* q = searchByTitle(xTitle);
			dele(q);

    //--------------------------------------------------------
    ftraverse(fou);
    fou.close();
   }

//=====================================================================
// Test sort by bcode
  void f6() 
   {
    clear();
    char * fname = "f6.txt";
    if(exist(fname)) remove(fname);
    loadData(1);
    ofstream fou; fou.open(fname,ios::app);
    ftraverse(fou);
    //--------------------------------------------------------
    /* You should write here statements 
       to sort the list ascendingly by bcode */
		BNode * pi, *pj;
        pi=head;
        while(pi!=NULL)
        {
            pj = pi->next;
            while(pj!=NULL)
            {
                if(pj->info.bcode < pi->info.bcode)
                {
                    Book x;
                    x = pi->info; pi->info = pj->info; pj->info = x;
                }
                pj = pj->next;
            }
            pi = pi->next;
        }	

    //--------------------------------------------------------
    ftraverse(fou);
    fou.close();
   }

//=====================================================================
// Test insert after position  k
BNode *position(int k)
    {
        BNode *p = head;
        while(p != NULL && k)
        {
            k--;
            p = p->next;
        }
        return p;
    }
void addAfterK(Book x, BNode *p)
    {

        if(tail == p) addLast(x);
        else
        {
            BNode *q = new BNode(x);
            q->next = p->next;
            p->next = q;
        }
    }
  void f7()
   {
    clear();
    BNode *p;
    char * fname = "f7.txt";
    if(exist(fname)) remove(fname);
    loadData(1);
    ofstream fou; fou.open(fname,ios::app);
    ftraverse(fou);
    int k = 2;
    Book x("B11","X",5,6,1);
    //--------------------------------------------------------
    /* You should write here statements 
       to insert the book x after position k
       (head's position is 0)   */
       p=position(k);
	addAfterK(x,p);

    //--------------------------------------------------------
    ftraverse(fou);
    fou.close();
   }

//=====================================================================
// Test delete position k
void delFirst()
    {
        BNode *p = head;
        head = head->next;
        delete p;
    }
void delLast()
    {
        if(isEmpty()) return;
        if(head == tail) delFirst();
        else
        {
            BNode *p = head;
            while(p != tail)
            {
                p = p->next;
            }
            delete p->next;
            tail = p;
        }
    }
void delBNode(BNode *p)
    {
        if(p == head) delFirst();
        else if(p == tail) delLast();
        else
        {
            BNode *q = head;
            while(q->next != p)
            {
                q = q->next;
            }
            q->next = p->next;
            delete p;
        }
    }
  void f8()
   {
    clear();
    char * fname = "f8.txt";
    if(exist(fname)) remove(fname);
    loadData(1);
    ofstream fou; fou.open(fname,ios::app);
    ftraverse(fou);
    int k = 4;
    //--------------------------------------------------------
    /* You should write here statements 
       to delete the node at position k
       (head's position is 0)   */
	delBNode(position(k));

    //--------------------------------------------------------
    ftraverse(fou);
    fou.close();
   }

 };
//===================================================
