class Node
 {int info;
  Node next;
 }
class MyList
 {Node head,tail;
  MyList() {head=tail=null;}
  boolean isEmpty() {return(head==null);}
  void clear() {head=tail=null;}
  void add(int x)
   {Node q = new Node(); q.info=x;q.next=null;
    if(isEmpty()) {head=tail=q;return;}
    tail.next=q;tail=q;
   }
  void visit(Node p) 
   {System.out.print(p.info+ " ");}
  void traverse()
   {Node p = head;
    System.out.print(" ");
    while(p!=null)
     {visit(p);
      p = p.next;
     }
    System.out.println();  
   }
  Node search(int x)
   {Node p = head;
    while(p!=null)
     {if(p.info==x) return(p);
      p=p.next;
     }
    return(null);
   }
  void dele(Node q)
   {if(q==null) return;
    Node f,p; f=null;p=head;
    while(p!=null)
     {if(p==q) break;
      f=p;p=p.next;
     }
    if(p==null) return;
    if(f==null) // head=q;
     {head=head.next;
      if(head==null) tail=null;
      return;
     }
    f.next=q.next;
    if(q==tail) tail=f;

   }
  void addMany(int [] a) 
   {int n,i; n = a.length;
    for(i=0;i<n;i++) add(a[i]);
   }
  void sort()
   {Node i,j; int x;
    i=head;
    while(i!=null)
     {j=i.next;
      while(j!=null)
       {if(j.info<i.info) {x=i.info;i.info=j.info;j.info=x;}
        j=j.next;
       }
      i = i.next;
     }
   }
  void addFirst(int x) {} // Inserts the given element at the beginning of this list.
  int get(int index) {return(0);} // Returns the element at the specified position in this list.
  int getFirst() {return(0);} //Returns the first element in this list.
  int getLast() {return(0);} //Returns the last element in this list.
  int remove(int index) {return(0);} //Removes the element at the specified position in this list.
  int removeFirst() {return(0);} //Removes and returns the first element from this list.
  int removeLast() {return(0);} //Removes and returns the last element from this list.
  int size() {return(0);} //Returns the number of elements in this list.
  int [] toArray() {return(null);} // Returns an array containing all of the elements in this list in the correct order.
 } 
public class Main
 {public static void main(String [] args)
   {MyList t = new MyList();
    int [] a = {7,9,15,8,6,21,13,14};
    t.addMany(a);
    t.traverse();
    System.out.println("\n 1. Test addFirst():");  
    t.addFirst(5);
    t.traverse();//5,7,9,15,8,6,21,13,14
    System.out.println("\n 2. Test getFirst():");  
    System.out.println(" The first element is " + t.getFirst()); // 5  
    System.out.println("\n 3. Test getLast():");  
    System.out.println(" The last element is " + t.getLast()); // 14  
    System.out.println("\n 4. Test get(k):");
    int k = 3;
    System.out.println(" The element at position " + k + " is " + t.get(k)); // 15  
    System.out.println("\n 5. Test remove(k):");
    t.remove(k);  
    t.traverse();//5,7,9,8,6,21,13,14
    System.out.println("\n 6. Test removeFirst():");
    t.removeFirst();  
    t.traverse();//7,9,8,6,21,13,14
    System.out.println("\n 7. Test removeLast():");
    t.removeLast();  
    t.traverse();//7,9,8,6,21,13
    System.out.println("\n 8. Test size():");  
    System.out.println(" The number of elements is " + t.size()); // 6  
    System.out.println("\n 9. Test toArray():");
    int [] b = t.toArray();  
    for(int i=0;i<b.length;i++) System.out.print(b[i] + " ");
    //7,9,8,6,21,13
    System.out.println();  
   }
 }
