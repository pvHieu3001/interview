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
class MyQueue
 {Node head, tail;
  MyQueue() {head=tail=null;}
  void clear() {}
  boolean isEmpty() {return(true);}
  void enqueue(Student x) {}
  void enqueueMany(String [] a, String [] b, int [] c) 
   {int n = a.length;
    for(int i=0;i<n;i++) enqueue(new Student(a[i],b[i],c[i]));
   }
  void traverse() {}
  void dequeueAll() {}
  Student dequeue() {return(null);}
  void checkEmpty()
   {if(isEmpty())
      System.out.println("The queue is empty!");
       else
         System.out.println("The queue is not empty!");
   }
 }
public class Main
 {public static void main(String [] args)
   {String [] a = {"Hoa","La","Canh","Cay","Qua"};
    String [] b = {"01","02","03","04","05"};
    int [] c = {7,8,5,9,6};
    MyQueue t = new MyQueue(); t.enqueueMany(a,b,c);
    t.traverse(); //(1)
    t.dequeue();
    t.traverse(); //(2)
    t.checkEmpty(); //(3)
    t.dequeueAll(); //(4)
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
La    02 8
Canh  03 5
Cay   04 9
Qua   05 6

(3)
The queue is not empty

(4)
La    02 8
Canh  03 5
Cay   04 9
Qua   05 6

(5)
The queue is empty

*/