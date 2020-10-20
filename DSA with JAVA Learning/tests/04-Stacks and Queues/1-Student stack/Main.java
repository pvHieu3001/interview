/*
Complete the following program
*/
class Student
 {String name, rollno; int mark;
  Student(String name1, String rollno1, int mark1) {} 
 }
class Node
 {Student info;
  Node next;
 }
class MyStack
 {Node head;
  MyStack() {head=null;}
  void clear() {}
  boolean isEmpty() {return(true);}
  void push(Student x) {}
  void pushMany(String [] a, String [] b, int [] c) 
   {int n = a.length;
    for(int i=0;i<n;i++) push(new Student(a[i],b[i],c[i]));
   }
  void traverse() {}
  void popAll() {}
  Student pop() {return(null);}
  void checkEmpty()
   {if(isEmpty())
      System.out.println("The stack is empty!");
       else
         System.out.println("The stack is not empty!");
   }
 }
public class Main
 {public static void main(String [] args)
   {String [] a = {"Hoa","La","Canh","Cay","Qua"};
    String [] b = {"01","02","03","04","05"};
    int [] c = {7,8,5,9,6};
    MyStack t = new MyStack(); t.pushMany(a,b,c);
    t.traverse(); //(1)
    t.pop();
    t.traverse(); //(2)
    t.checkEmpty(); //(3)
    t.popAll(); //(4)
    t.checkEmpty(); //(5)
    System.out.println();  
   }
 }

/* Output:

(1)
Hoa   01 7
La    02 8
Canh  03 5
Cay   04 9
Qua   05 6

(2)
Hoa   01 7
La    02 8
Canh  03 5
Cay   04 9

(3)
The stack is not empty

(4)
Cay   04 9
Canh  03 5
La    02 8
Hoa   01 7

(5)
The stack is empty

*/