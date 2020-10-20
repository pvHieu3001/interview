/*
You cannot modify or add new statement to the main() function.
However you can disable statements in the main() method if you
cannot complete the corresponding function(s).
Except the main() method, you can modify or add new members to
other class(es) or even you can create new class(es), e.g. you
can delete or modify a given statement(s).
*/
import java.util.*;
class Student
 {String code, name;// code is used as a key of the tree
  int age; double mark;
  Student(String code1, String name1, int age1, double mark1)
   {code=code1;name=name1;age=age1;mark=mark1;
   }
  boolean isValid() {return(false);}
  public String toString()
   {return("(" +code + "," + name+","+age + ","+ mark + ")");
   }
  public boolean equals(Student x) {return(false);}
  public int compareTo(Student x) {return(0);}
 }
//--------------------------
class Node
 {Student info;
  Node left,right;
 }
//==========================
class MyQueue
 {LinkedList<Node> t;
  MyQueue() {t = new LinkedList<Node>();}
  void clear() {t.clear();}
  boolean isEmpty() {return(t.isEmpty());}
  void enqueue(Node q) {}
  Node dequeue() {return(null);}
  Node front() {return(null);}
 }
//==========================
class BSTree
 {Node root;
  BSTree() {root=null;}
  boolean isEmpty()
   {return(root==null);
   }
  void clear()
   {root=null;
   }
  void insert(Student x) {} // x.code is used as a key of the tree
  void insert(String code1, String name1, int age1, double mark1) {}
  void visit(Node p) {}
  void preOrder(Node p) {}
  void inOrder(Node p) {}
  void breadthTraverse() {}
  void insertMany(String [] a, String [] b, int [] c, double [] d,int n) {}
  Node search(String xCode) {return(null);}
  int countNodes(Node p) {return(0);}
  int height(Node p) {return(0);}
  void copyDele(String xCode) {}
 }

//======================================================
class Main
 {public static void main(String [] args)
   {BSTree t = new BSTree(); int n;

    {System.out.println("\n1. Test insert (2 marks)-2:");
     t.insert(new Student("A05","HOA",20,7.5));
     t.insert(new Student("A02","LA",21,6.0));
     t.insert(new Student("A06","CANH",19,7.0));
     t.insert(new Student("A01","QUA",22,8.5));
     t.insert(new Student("A03","CAY",22,10.5));
     t.insert(new Student("A04","VUON",22,8.5));
     System.out.println(" Pre-order traverse:");
     t.preOrder(t.root);
     System.out.println("\n In-order traverse:");
     t.inOrder(t.root);
     System.out.println("\n Breadth-first traverse:");
     t.breadthTraverse();
    }

    {System.out.println("\n2. Test insertMany (2 marks)-4");
     t.clear();
     String [] a = {"A5","A2","A9","A1","A4","A6","B3","A3","A8","A7"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","QUIT","CAM"};
     int [] c = {29,30,27,28,26,27,34,35,19,18};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,7.8,5.5};
     n = a.length;
     t.insertMany(a,b,c,d,n);
     System.out.println(" Pre-order traverse:");
     t.preOrder(t.root);
     System.out.println("\n In-order traverse:");
     t.inOrder(t.root);
     System.out.println("\n Breadth-first traverse:");
     t.breadthTraverse();
    }

    {System.out.println("\n3. Test search (1 mark)-5");
     t.clear();
     String [] a = {"A5","A2","A9","A1","A4","A6","B3","A3","A8","A7"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","QUIT","CAM"};
     int [] c = {29,30,27,28,26,27,34,35,19,18};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,7.8,5.5};
     n = a.length;
     t.insertMany(a,b,c,d,n);
     System.out.println(" Pre-order traverse:");
     t.preOrder(t.root);
     String xCode;
     Node p;
     xCode = new String("A4");
     p = t.search(xCode);
     if(p!=null)
       System.out.println(" " + xCode + " is found");
        else       
         System.out.println(" " + xCode + " is not found");

     xCode = new String("A11");
     p = t.search(xCode);
     if(p!=null)
       System.out.println(" " + xCode + " is found");
        else       
         System.out.println(" " + xCode + " is not found");
    }

    {System.out.println("\n4. Test count (2 marks)-7:");
     t.clear();
     String [] a = {"A5","A2","A9","A1","A4","A6","B3","A3","A8","A7"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","QUIT","CAM"};
     int [] c = {29,30,27,28,26,27,34,35,19,18};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,7.8,5.5};
     n = a.length;
     t.insertMany(a,b,c,d,n);
     System.out.println("\n In-order traverse:");
     t.inOrder(t.root);
     int k = t.countNodes(t.root);
     System.out.println(" Number of nodes is: " + k);
    }

    {System.out.println("\n5. Test height (1 mark)-8");
     t.clear();
     String [] a = {"A5","A2","A9","A1","A4","A6","B3","A3","A8","A7"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","QUIT","CAM"};
     int [] c = {29,30,27,28,26,27,34,35,19,18};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,7.8,5.5};
     n = a.length;
     t.insertMany(a,b,c,d,n);
     System.out.println(" Pre-order traverse:");
     t.preOrder(t.root);
     int k = t.height(t.root);
     System.out.println(" The height of a tree is: " + k);
    }


    {System.out.println("\n6. Test delete by copying (2 marks)-10");
     t.clear();
     String [] a = {"A5","A2","A9","A1","A4","A6","B3","A3","A8","A7"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","QUIT","CAM"};
     int [] c = {29,30,27,28,26,27,34,35,19,18};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,7.8,5.5};
     n = a.length;
     t.insertMany(a,b,c,d,n);
     System.out.println(" Pre-order traverse:");
     t.preOrder(t.root);
     String xCode = new String("A5");
     t.copyDele(xCode);
     System.out.println("\n After deleting " + xCode + ":");
     System.out.println(" Pre-order traverse:");
     t.preOrder(t.root);
    }

    System.out.println();       
   }
 }
