class Person
 {String name; int age;
   Person() {}
   Person(String xName, int xAge) {name=xName;age=xAge;}
   public String toString() {return("("+name+", " + age+") ");}
 }
class Node
 {Person info;
   Node next;
   Node() {}
   Node(Person x, Node q) {info=x;next=q;}
   Node(Person x) {this(x,null);} 
 }
class MyList
 {Node head, tail;
   MyList() {head=tail=null;}
   boolean isEmpty() {return(head==null);}
   void clear() {head=tail=null;}

   // (1) 
   void addLast(Person x)
     {Node q = new Node(x);
       if(isEmpty()) {head=tail=q;return;}
       tail.next = q;
       tail = q;
     }

    void visit(Node p) {if(p!=null) System.out.print(p.info);}
    void traverse()
     {Node p=head;
       while(p!=null)
         {visit(p);
           p=p.next;
         }
      System.out.println();
     }
   void addMany(String [] a, int [] b)
     {int n,i; n=a.length;
       for(i=0;i<n;i++) addLast(new Person(a[i],b[i]));
     }

   // (2)
   Node search(String xName)
     {Node p=head;
       while(p!=null)
        {if(p.info.name.equals(xName)) return(p);
          p=p.next;
        }
       return(null);
     }

   // (3)
   void addFirst(Person x)
     {head = new Node(x,head);
       if(tail==null) tail = head;
     }

   // (4)
   void insertAfter(Node q, Person x)
     {if(q==null);
       Node p1 = q.next;
       Node p = new Node(x,p1);
       q.next = p;
       if(q==tail) tail = p;
     }

   // (5)
   void insertBefore(Node q, Person x)
     {if(q==null) return;
       if(q==head)
         {addFirst(x);
           return;
         }
       Node f = head;
       while(f!=null && f.next != q) f = f.next;
       if(f==null) return;
       insertAfter(f,x);
     }

   // (6)
   void dele(Node q)
     {if(q==null || isEmpty()) return;
       if(q==head)
         {head = head.next;
           if(head == null) tail = null;
           return;
         }
       Node f = head;
       while(f!=null && f.next != q) f = f.next;
       if(f==null) return;
       Node p1 = q.next;
       f.next = p1;
       if(f.next == null) tail = f;
     }

   // (7)
   void dele(String xName)
     {Node q = search(xName);
       dele(q);
     }

   // (8)
   Node searchByAge(int xAge)
     {Node p = head;
       while(p!=null)
         {if(p.info.age == xAge) return(p);
           p = p.next;
         }
       return(null);
     }
   void dele(int xAge)
     {Node q = searchByAge(xAge);
       dele(q);
     }

   // (9)
   void deleAll(int xAge)
     {Node q;
       while(true)
         {q = searchByAge(xAge);
           if(q==null) break;
           dele(q);
         }
     }

   // (10)
   Node pos(int k)
     {int i=0;
       Node p = head;
       while(p!=null)
         {if(i==k) return(p);
           i++;
           p = p.next;
         }
       return(null);
     }

   // (11)
   void delePos(int k)
     {Node q = pos(k);
       dele(q);
     }

   // (12)
   void sortByName()
     {Node pi,pj; Person x;
       pi = head;
       while(pi!=null)
         {pj = pi.next;
           while(pj!=null)
              {if(pj.info.name.compareTo(pi.info.name)<0)
                  {x = pi.info;pi.info = pj.info; pj.info = x;
                  }
                pj = pj.next;
              }
           pi = pi.next;
         }
     }

   // (13)
   void sortByAge()
     {Node pi,pj; Person x;
       pi = head;
       while(pi!=null)
         {pj = pi.next;
           while(pj!=null)
              {if(pj.info.age < pi.info.age)
                  {x = pi.info;pi.info = pj.info; pj.info = x;
                  }
                pj = pj.next;
              }
           pi = pi.next;
         }
     }


   // (14)
   Person [] toArray()
     {int i,n; n = size();
       Person [] a = new Person[n];
       Node p = head;
       i = 0;
       while(p!=null)
         {a[i++] = new Person(p.info.name, p.info.age);
           p = p.next;
         }
       return(a);
     }

   // (15)
   void reverse()
     {MyList t = new MyList();
       Node p = head;
       while(p!=null)
         {t.addFirst(new Person(p.info.name, p.info.age));
           p = p.next;
         }
        head = t.head;
        tail = t.tail;
     }

   // (16)
   int size()
     {int i = 0;
       Node p = head;
       while(p!=null)
          {p = p.next;
            i++;
          }
       return(i);
     }

 }

public class Main
 {public static void main(String [] args)
   {MyList t = new MyList();
     Node p,q; Person x; int k;
     String [] a = {"A","C","B","E","D"};
     int [] b = {9,5,7,5,8};
 
     System.out.println("\n1. Test addLast");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); //  (A,9) (C,5) (B,7) (E,5) (D,8)
 
     System.out.println("\n2. Test search");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); //  (A,9) (C,5) (B,7) (E,5) (D,8)
     p = t.search("B");
     if(p==null)
      System.out.println("Not found");
      else
      {System.out.println("The person found is");
        t.visit(p); System.out.println();
      }

     System.out.println("\n3. Test addFirst");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); //  (A,9) (C,5) (B,7) (E,5) (D,8)
     x = new Person("X",30);
     t.addFirst(x);  
     t.traverse(); // (X,30) (A,9) (C,5) (B,7) (E,5) (D,8)

     System.out.println("\n4. Test insertAfter");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     x = new Person("X",30);
     q = t.search("B");
     t.insertAfter(q,x);  
     t.traverse(); // (A,9) (C,5) (B,7) (X,30) (E,5) (D,8)

     System.out.println("\n5. Test insertBefore");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     x = new Person("X",30);
     q = t.search("B");
     t.insertBefore(q,x);  
     t.traverse(); // (A,9) (C,5) (X,30) (B,7) (E,5) (D,8)

     System.out.println("\n6. Test dele(Node q)");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     q = t.search("B");
     t.dele(q);  
     t.traverse(); // (A,9) (C,5) (E,5) (D,8)

     System.out.println("\n7. Test dele(String xName)");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     t.dele("B");  
     t.traverse(); // (A,9) (C,5) (E,5) (D,8)

     System.out.println("\n8. Test dele(int xAge)");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     t.dele(5);  
     t.traverse(); // (A,9) (B,7) (E,5) (D,8)

     System.out.println("\n9. Test deleAll(int xAge)");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     t.deleAll(5);  
     t.traverse(); // (A,9) (B,7) (D,8)

     System.out.println("\n10. Test pos(int k)");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     p = t.pos(2);
     System.out.println("The person at position 2 is ");
     t.visit(p); // The person at position 2 is  (B,7)
     System.out.println();

     System.out.println("\n11. Test delePos(int k)");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     t.delePos(2);  
     t.traverse(); // (A,9) (C,5) (E,5) (D,8)

     System.out.println("\n12. Test sortByName()");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     t.sortByName();
     t.traverse(); // (A,9) (B,7) (C,5) (D,8) (E,5)

     System.out.println("\n13. Test sortByAge()");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     t.sortByAge();
     t.traverse(); // (C,5) (E,5) (B,7) (D,8) (A,9)

     System.out.println("\n14. Test toArray()");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     Person [] u = t.toArray();
     if(u!=null)
      {for(int i=0;i<u.length;i++) 
               System.out.print(u[i]); // (A,9) (C,5) (B,7) (E,5) (D,8)
        System.out.println();
      }

     System.out.println("\n15. Test reverse()");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     t.reverse();
     t.traverse(); // (D,8) (E,5) (B,7) (C,5) (A,9)

     System.out.println("\n16. Test size()");
     t.clear();
     t.addMany(a,b);  
     t.traverse(); // (A,9) (C,5) (B,7) (E,5) (D,8)
     k = t.size();
     System.out.println("Size = " + k);  

     System.out.println();  
   }
 }
