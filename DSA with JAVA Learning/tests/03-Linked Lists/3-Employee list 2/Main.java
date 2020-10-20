/*
Complete the following program
*/
class Employee
 {String name, code; int salary;
  Employee(String name1, String code1, int salary1) {} 
 }
class Node
 {Employee info;
  Node next;
 }
class MyList
 {Node head, tail;
  MyList() {head=tail=null;}
  void clear() {}
  boolean isEmpty() {return(true);}
  void addLast(Employee x) {}
  void addFirst(Employee x) {}
  void dele(int i) {} // delete position i, i=1,2,3,..
  int size() {return(0);} // return number of employees
  void addMany(String [] a, String [] b, int [] c) 
   {int n = a.length;
    for(int i=0;i<n;i++) addLast(new Employee(a[i],b[i],c[i]));
   }
  void traverse() {}
  void addUnique(Employee x) {} // add employee if code does not exists
 }
public class Main
 {public static void main(String [] args)
   {String [] a = {"Hoa","La","Canh","Cay","Qua"};
    String [] b = {"01","02","03","04","05"};
    int [] c = {7,8,5,9,6};
    MyList t = new MyList(); t.addMany(a,b,c);
    t.traverse(); //(1)
    t.addFirst(new Employee("Quang","11",7));
    t.traverse(); //(2)
    t.dele(3);
    t.traverse(); //(3)
    System.out.println(" Number of employees: " + t.size());//(4)
    t.addUnique(new Employee("Cong","04",8));
    t.traverse();//(5)
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
Quang 11 7
Hoa   01 7
La    02 8
Canh  03 5
Cay   04 9
Qua   05 6

(3)
Quang 11 7
Hoa   01 7
Canh  03 5
Cay   04 9
Qua   05 6

(4)
 Number of employees: 5

(5)
Quang 11 7
Hoa   01 7
Canh  03 5
Cay   04 9
Qua   05 6
*/