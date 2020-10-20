/* This program contains 2 parts: (1) and (2)
   YOUR TASK IS TO COMPLETE THE PART  (2)  ONLY
 */
//(1)==============================================================
import java.io.*;
import java.util.*;
class Book
 {String bcode, title;
  int quantity,lended;
  double price;
  Book(String xBCode, String xTitle, int xQuantity, int xLended, double xPrice)
   {bcode=xBCode;title = xTitle;quantity=xQuantity;lended=xLended;price=xPrice;
   }
  public String toString()
   {return("(" + bcode+","+title + "," + quantity + ","+lended + "," + price +")");
   }
 }

class BNode
 {Book info;
  BNode next;
  BNode(Book x, BNode p)
   {info=x;next=p;
   }
  BNode(Book x)
   {this(x,null);
   }
 }
class BookList
 {BNode head,tail;

  BookList() {head=tail=null;}

  boolean isEmpty()
   {return(head==null);
   }

  void clear() {head=tail=null;}

  int size()
   {int k=0;
    BNode p = head;
    while(p!=null)
     {k++;
      p = p.next;
     }
    return(k);
   }

  void visit(BNode p)
   {System.out.println(p.info);
   }

  void fvisit(BNode p, RandomAccessFile f) throws Exception
   {f.writeBytes(p.info + "\r\n");
   }

  void traverse()
   {BNode p=head;
    while(p!=null)
     {visit(p);
      p=p.next;
     }
    System.out.println();
   }

  void ftraverse(RandomAccessFile f) throws Exception
   {BNode p = head;
    while(p!=null)
      {fvisit(p,f); // You will use this statement to write information of the node p to the file
       p=p.next;
      }
    f.writeBytes("\r\n");
   }

  void loadData(int k)  //do not edit this function
   {String [] a = Lib.readLineToStrArray("data.txt", k);
    String [] b = Lib.readLineToStrArray("data.txt", k+1);
    int [] c = Lib.readLineToIntArray("data.txt", k+2);
    int [] d = Lib.readLineToIntArray("data.txt", k+3);
    double [] e = Lib.readLineToDoubleArray("data.txt", k+4);

    int n = a.length;
    for(int i=0;i<n;i++) addLast(a[i],b[i],c[i],d[i],e[i]);
   }

//(2)====================YOU SHOULD COMPLETE THE FOLLOWING FUNCTIONS=========
  /*
    Conditions for addLast:
   ==================
    bcode must be unique
    quantity>0
    lended>=0
    quantity >= lended
    price>0
  */
  void addLast(String xBCode, String xTitle, int xQuantity, int xLended, double xPrice)
   {xBCode=xBCode.trim(); xTitle=xTitle.trim();

   }

//=====================================================================
// Test add to the end
  void f1() throws Exception
    {/* You do not need to edit this function. Your task is to complete addLast  function
        above only.
     */
     clear();
     loadData(2);
     String fname = "f1.txt";
     File g = new File(fname);
     if(g.exists()) g.delete();
     RandomAccessFile  f = new RandomAccessFile(fname, "rw"); 
     ftraverse(f);
     f.close();
    }  

//=====================================================================
// Test load data from file
  void f2() throws Exception
    {clear();
     String fname = "f2.txt";
     File g = new File(fname);
     if(g.exists()) g.delete();
     RandomAccessFile  f = new RandomAccessFile(fname, "rw"); 
    //--------------------------------------------------------
    /* You should write here statements  to read data from the file book.txt
        and using the addLast function to add data to the list.
        The book.txt file contains 4 items: bcode, title, quantity, price
         (lended is absent and set to 0)
     */


    //--------------------------------------------------------
     ftraverse(f);
     f.close();
    }  


//=====================================================================
// Test search by title
  void f3() throws Exception 
   {clear();
    loadData(14);
    String fname = "f3.txt";
    File g = new File(fname);
    if(g.exists()) g.delete();
    RandomAccessFile  f = new RandomAccessFile(fname, "rw"); 
    ftraverse(f);
    String xTitle = new String("T9");
    BookList  h = new BookList();
    //--------------------------------------------------------
    /* You should write here statements 
       to add to the list h all elements having title = xTitle */


    //--------------------------------------------------------
    h.ftraverse(f);
    f.close();
   }
//=====================================================================
// Test save to file
 void f4() throws Exception
    {
     String fname = "f4.txt";
     File g = new File(fname);
     if(g.exists()) g.delete();
     clear();
     loadData(8); // This statement load data from data.txt file. You do not need to load again

    //--------------------------------------------------------
    /* You should write here statements to complete the following task:
        traverse the list from head to tail and write data to the file f3.txt in format:
        bcode  ||  title  ||  quantity   ||   lended   ||   price  
     */


    //--------------------------------------------------------
    }  


//=====================================================================
// Test delete by title
  void f5() throws Exception
   {
    clear();
    loadData(14);
    String fname = "f5.txt";
    File g = new File(fname);
    if(g.exists()) g.delete();
    RandomAccessFile  f = new RandomAccessFile(fname, "rw"); 
    ftraverse(f);
    String xTitle = new String("T9");
    //--------------------------------------------------------
    /* You should write here statements 
       to delete the first node having title = xTitle */


    //--------------------------------------------------------
    ftraverse(f);
    f.close();
   }

//=====================================================================
// Test sort by bcode
  void f6() throws Exception 
   {
    clear();
    loadData(2);
    String fname = "f6.txt";
    File g = new File(fname);
    if(g.exists()) g.delete();
    RandomAccessFile  f = new RandomAccessFile(fname, "rw"); 
    ftraverse(f);
    //--------------------------------------------------------
    /* You should write here statements 
       to sort the list ascendingly by bcode */


    //--------------------------------------------------------
    ftraverse(f);
    f.close();
   }

//=====================================================================
// Test insert after position  k
  void f7() throws Exception
   {
    clear();
    loadData(2);
    String fname = "f7.txt";
    File g = new File(fname);
    if(g.exists()) g.delete();
    RandomAccessFile  f = new RandomAccessFile(fname, "rw"); 
    ftraverse(f);
    int k = 2;
    Book x = new Book("B11","X",5,6,1);
    //--------------------------------------------------------
    /* You should write here statements 
       to insert the book x after position k
       (head's position is 0)   */


    //--------------------------------------------------------
    ftraverse(f);
    f.close();
   }

//=====================================================================
// Test delete position k
  void f8() throws Exception
   {
    clear();
    loadData(2);
    String fname = "f8.txt";
    File g = new File(fname);
    if(g.exists()) g.delete();
    RandomAccessFile  f = new RandomAccessFile(fname, "rw"); 
    ftraverse(f);
    int k = 4;
    //--------------------------------------------------------
    /* You should write here statements 
       to delete the node at position k
       (head's position is 0)   */


    //--------------------------------------------------------
    ftraverse(f);
    f.close();
   }

 }

