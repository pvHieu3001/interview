/* This program contains 2 parts: (1) and (2)
   YOUR TASK IS TO COMPLETE THE PART  (2)  ONLY
 */
//(1)==============================================================
import java.io.*;
import java.util.*;
class Reader
 {String rcode, name;
  int byear;
  Reader(String xRCode, String xName, int xByear)
   {rcode=xRCode;name = xName;byear=xByear;;
   }
  public String toString()
   {return("(" + rcode+","+name + "," + byear  +")");
   }
 }

class RNode
 {Reader info;
  RNode next;
  RNode(Reader x, RNode p)
   {info=x;next=p;
   }
  RNode(Reader x)
   {this(x,null);
   }
 }
class ReaderList
 {RNode head,tail;

  ReaderList() {head=tail=null;}

  boolean isEmpty()
   {return(head==null);
   }

  void clear() {head=tail=null;}

  int size()
   {int k=0;
    RNode p = head;
    while(p!=null)
     {k++;
      p = p.next;
     }
    return(k);
   }

  void visit(RNode p)
   {System.out.println(p.info);
   }

  void fvisit(RNode p, RandomAccessFile f) throws Exception
   {f.writeBytes(p.info + "\r\n");
   }

  void traverse()
   {RNode p=head;
    while(p!=null)
     {visit(p);
      p=p.next;
     }
    System.out.println();
   }

  void ftraverse(RandomAccessFile f) throws Exception
   {RNode p = head;
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

    int n = a.length;
    for(int i=0;i<n;i++) addLast(a[i],b[i],c[i]);
   }

//(2)====================YOU SHOULD COMPLETE THE FOLLOWING FUNCTIONS=========
  /*
    Conditions for addLast:
   ==================
    rcode must be unique
    byear must be in the interval [1900,2010] 
  */
  void addLast(String xRCode, String xName, int xByear)
   {xRCode=xRCode.trim(); xName=xName.trim();
   }

//=====================================================================
// Test save to file
 void f9() throws Exception
    {
     String fname = "f9.txt";
     File g = new File(fname);
     if(g.exists()) g.delete();
     clear();
     loadData(24); // This statement load data from data.txt file. You do not need to load again

    //--------------------------------------------------------
    /* You should write here statements to complete the following task:
        traverse the list from head to tail and write data to the file f9.txt in format:
        rcode  ||  name  ||  byear  
     */


    //--------------------------------------------------------
    }  

//=====================================================================
 }

