import java.util.*;
class Node
 {int info;
   Node left,right;
   Node() {}
   Node(int x)
    {info = x;
      left = right = null;
    }
 }
class MyQueue
 {ArrayList<Node> t;
   MyQueue() {t = new ArrayList<Node>();}
   void clear() {t.clear();}
   boolean isEmpty() {return(t.isEmpty());}
   void enqueue(Node p) {t.add(p);}
   Node dequeue() {return(t.remove(0));}
   Node front() {return(t.get(0));}
 }
class BSTree
 {Node root;
   BSTree() {root = null;}
   void clear() {root = null;}
   boolean isEmpty() {return(root == null);}
   Node search(Node p, int x)
    {if(p==null) return(null);
      if(p.info==x) return(p);
      if(x<p.info)
        return(search(p.left,x));
         else
          return(search(p.right,x));
    }
   void insert(int x)
    {if(isEmpty()) {root = new Node(x); return;}
      Node f, p;
      f = null; p = root;
      while(p!=null)
        {if(p.info == x)
           {System.out.println("The key already exists, no insertion.");
             return;
           }
          f = p;
          if(x<p.info) p = p.left; else p = p.right;
        }
       if(x<f.info) f.left = new Node(x); else f.right = new Node(x);
    }
   void insertMany(int [] a)
    {int i, n; n = a.length;
      for(i=0;i<n;i++) insert(a[i]);
    }
   void visit(Node p)
    {if(p==null) return;
     System.out.print(p.info + "  ");
    }
   void breadth(Node p)
    {MyQueue q = new MyQueue();
      q.enqueue(p); Node r;
      while(!q.isEmpty())
       {r = q.dequeue();
         visit(r);
         if(r.left != null) q.enqueue(r.left);
         if(r.right != null) q.enqueue(r.right);
       }
    }
   void preOrder(Node p)
    {if(p==null) return;
      visit(p);
      preOrder(p.left);
      preOrder(p.right);
    }

   void inOrder(Node p)
    {if(p==null) return;
      inOrder(p.left);
      visit(p);
      inOrder(p.right);
    }

   void postOrder(Node p)
    {if(p==null) return;
      postOrder(p.left);
      postOrder(p.right);
      visit(p);
    }
 }
public class Main
 {public static void main(String [] args)
   {int [] a = {12,4,14,2,10,6,8};
     BSTree t = new BSTree();
     t.insertMany(a);

     System.out.println("\n1. Test breadth-first traversal:");
     t.breadth(t.root);  
     System.out.println();  

     System.out.println("\n2. Test pre-order traversal:");
     t.preOrder(t.root);  
     System.out.println();  

     System.out.println("\n3. Test in-order traversal:");
     t.inOrder(t.root);  
     System.out.println();  

     System.out.println("\n4. Test post-order traversal:");
     t.postOrder(t.root);  
     System.out.println();  
   }
 }
