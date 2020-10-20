/*
You cannot modify or add new statement to the main() function.
However you can disable statements in the main() method if you
cannot complete the corresponding function(s).#
Except the main() method, you can modify or add new members to
other class(es) or even you can create new class(es), e.g. you
can delete or modify a given statement(s).//#
*/
import java.util.*;
class SNode
 {String info;
  SNode next;
 }
class QNode
 {int info;
  QNode next;
 }

class MyStack
 {SNode head;
  MyStack() {head=null;}
  boolean isEmpty()
   {//#
    return(head==null);
   }
  void clear()
   {//#
    head=null;
   }
  void push(String x) 
   {
   }
  //#
  String pop()
   {//#
    return(null);
   }
  void popAll()
   {//#
   }
 }
class MyQueue
 {QNode head,last;
  MyQueue() {head=last=null;}
  boolean isEmpty()
   {//#
    return(head==null);
   }
  void clear()
   {//#
    head=last=null;
   }
  void enqueue(int x)
   {
   }
  //#
  int dequeue()//#
   {return(0);
   }
  void dequeueAll()//#
   {
   }
 }

public class Main	// 6 marks
 {static void proc(String [] a)
   {
   }
  public static void main(String args[])
   {
    {System.out.println("\n 1. Test Stack (2 marks)-cumulative marks: 2");
     MyStack t = new MyStack();
     t.push("AB");t.push("CD");t.push("EF");t.push("GH");
     while(!t.isEmpty()) System.out.print(" " + t.pop());
     System.out.println();
    }

    {System.out.println("\n 2. Test Queue (2 marks)-cumulative marks: 4");
     MyQueue t = new MyQueue();
     t.enqueue(12);t.enqueue(34);t.enqueue(56);t.enqueue(789);
     while(!t.isEmpty()) System.out.print(" " + t.dequeue());
     System.out.println();
    }

    {System.out.println("\n 3. Test proc(only stack) (2 marks)");
     System.out.println("    cumulative marks: 6");
     String [] a = {"ab","bc","cd","*","x1","x2","*","*","ef","gh","#"};
     System.out.println();
     proc(a);
     System.out.println();
    }

    {System.out.println("\n 4. Test proc(only queue) (2 marks)");
     System.out.println("    cumulative marks: 8");
     String [] a = {"12","23","$","25","34","45","$"};
     System.out.println();
     proc(a);
     System.out.println();
    }


    {System.out.println("\n 5. Test proc(both stack & queue) (2 marks)");
     System.out.println("    cumulative marks: 10");
     String [] a = {"12","23","ab","bc","cd","*",
     "$","x1","x2","25","34","45","*","*","ef","gh"};
     System.out.println();
     proc(a);
    }
    System.out.println();
   }
 }
