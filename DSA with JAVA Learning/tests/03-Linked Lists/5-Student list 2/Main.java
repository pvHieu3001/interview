/*
Before starting:
replace all # with your roll number (e.g. 00425)
replace all $ with your shorted name + birth day
Fore example if your name is Nguyen Van Hung, your birth day is
22/10/1989 then you replace all $ with HungNV891022

Notes:
You cannot modify or add new statement to the main() function.
However you can disable statements in the main() method if you
cannot complete the corresponding function(s).
Except the main() method, you can modify or add new members to
other class(es) or even you can create new class(es), e.g. you
can delete or modify a given statement(s).
*/
class Student // #$
 {String code, name;
  int age; double mark;
  Student(String code1, String name1, int age1, double mark1) // #$
   {code=code1;name=name1;age=age1;mark=mark1;
   }
  public String toString() // #$
   {return("(" +code + "," + name+","+age + ","+ mark + ")");
   }
  public boolean equals(Student x)
   {return(false);
   }
  public int compareTo(Student x)
   {return(0);
   }
 }

class Node // #$
 {Student info;
  Node next;
 }

class MyList // #$
 {Node head,last;
  MyList() {head=last=null;} // #$
  boolean isEmpty() // #$
   {return(head==null);
   }
  void clear() {head=last=null;} // #$
  void add(Student x)
   {
   }
  void add(String code1, String name1, int age1, double mark1)
   {
   }
  void addMany(String [] a, String [] b, int [] c, double [] d,int n)
   {
   }
  void display()
   {
   }
  Node search(String xCode)
   {return(null);
   }
  void deleLast()
   {
   }
  void deleFirst()
   {
   }
  void dele(String xCode)
   {
   }
  void dele(Node q)
   {
   }
  void sort()
    {
    }
 }

public class Main	// 6 marks
 {public static void main(String args[])
   {MyList t = new MyList();
    int n;

    {System.out.println("\n 1. Test add (2 marks)-cumulative marks: 2");
     t.add(new Student("A01","HOA",20,7.5));
     t.add(new Student("A05","LA",21,6.0));
     t.add(new Student("A04","CANH",19,7.0));
     t.add(new Student("A02","QUA",22,-8.5));
     t.add(new Student("A06","CAY",22,10.5));
     t.add(new Student("#","$",20,10));
     t.display();
    }

    {System.out.println("\n 2. Test addMany (2 marks)-cumulative marks: 4");
     t.clear();
     String [] a = {"A3","A2","A1","A4","A5","A6","B6","A7","#"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","$"};
     int [] c = {26,21,19,22,24,23,18,25,20};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,10};
     n = a.length;
     t.addMany(a,b,c,d,n);
     t.display();
    }
   
    {System.out.println("\n 3. Test deleFirst (1 mark)-cumulative marks: 5");
     t.clear();
     String [] a = {"A3","A2","A1","A4","A5","A6","B6","A7","#"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","$"};
     int [] c = {26,21,19,22,24,23,18,25,20};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,10};
     n = a.length;
     t.addMany(a,b,c,d,n);
     t.display();
     t.deleFirst();
     t.display();
    }

    {System.out.println("\n 4. Test deleLast (1 mark)-cumulative marks: 6");
     t.clear();
     String [] a = {"A3","A2","A1","A4","A5","A6","B6","A7","#"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","$"};
     int [] c = {26,21,19,22,24,23,18,25,20};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,10};
     n = a.length;
     t.addMany(a,b,c,d,n);
     t.display();
     t.deleLast();
     t.display();
    }

    {System.out.println("\n 5. Test search(String xCode) (1 mark)-cumulative marks: 7");
     t.clear();
     String [] a = {"A3","A2","A1","A4","A5","A6","B6","A7","#"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","$"};
     int [] c = {26,21,19,22,24,23,18,25,20};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,10};
     n = a.length;
     t.addMany(a,b,c,d,n);
     t.display();
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

    {System.out.println("\n 6. Test dele(String xCode) (1 mark)-cumulative marks: 8");
     t.clear();
     String [] a = {"A3","A2","A1","A4","A5","A6","B6","A7","#"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","$"};
     int [] c = {26,21,19,22,24,23,18,25,20};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,10};
     n = a.length;
     t.addMany(a,b,c,d,n);
     t.display();
     String xCode = "A4";
     System.out.println(" After deleting " + xCode + ":");
     t.dele(xCode);
     t.display();
     xCode = new String("A3");
     System.out.println(" After deleting " + xCode + ":");
     t.dele(xCode);
     t.display();
     xCode = new String("A7");
     System.out.println(" After deleting " + xCode + ":");
     t.dele(xCode);
     t.display();
    }

    {System.out.println("\n 7. Test dele(Node q) (1 mark)-cumulative marks: 9");
     t.clear();
     String [] a = {"A3","A2","A1","A4","A5","A6","B6","A7","#"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","$"};
     int [] c = {26,21,19,22,24,23,18,25,20};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,10};
     n = a.length;
     t.addMany(a,b,c,d,n);
     t.display();
     String xCode = "A4";
     System.out.println(" After deleting " + xCode + ":");
     t.dele(t.search(xCode));
     t.display();
     xCode = new String("A3");
     System.out.println(" After deleting " + xCode + ":");
     t.dele(t.search(xCode));
     t.display();
     xCode = new String("A7");
     System.out.println(" After deleting " + xCode + ":");
     t.dele(t.search(xCode));
     t.display();
    }

    {System.out.println("\n 8. Test sorting (1 mark)-cumulative marks: 10");
     t.clear();
     String [] a = {"A3","A2","A1","A4","A5","A6","B6","A7","#"};
     String [] b = {"LAN","CUC","HONG","DAO","MAN","LE","TAO","CHANH","$"};
     int [] c = {26,21,19,22,24,23,18,25,20};
     double [] d = {6.9,3.0,2.7,8.2,6.1,7.5,3.4,5.1,10};
     n = a.length;
     t.addMany(a,b,c,d,n);
     t.display();
     System.out.println(" After sorting:");
     t.sort();
     t.display();
    }

    System.out.println();       
   }
 }
