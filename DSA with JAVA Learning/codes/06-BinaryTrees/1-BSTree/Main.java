class Node
 {int info;
  Node left,right;
  Node(int x) {info=x;left=right=null;}
 }
class BTree
 {Node root;
  BTree() {root=null;}
  boolean isEmpty() {return(root==null);}
  Node search(Node p, int x)
   {if(p==null) return(null);
    if(p.info==x) return(p);
    if(x<p.info) 
     return(search(p.left,x));
      else
       return(search(p.right,x));
   } 
  void insert(int x)
   {Node q = new Node(x);
    if(isEmpty()) {root=q;return;}
    Node f, p; f=null;p=root;
    while(p!=null)
     {if(p.info==x)
       {System.out.println("The key "+x+" already exists, no insertion");
        return;
       }
      f=p;
      if(x<p.info) p=p.left; else p=p.right;
     }
    if(x<f.info) f.left=q;else f.right=q;
   }
  void insertMany(int [] a)
   {for(int i=0;i<a.length;i++) insert(a[i]);
   }
  void visit(Node p)
   {System.out.print(p.info + " ");
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
   {BTree t = new BTree();
    int [] a = {25,10,30,5,20,10,15};
    t.insertMany(a);
    System.out.println("\nPre-order traverse:");
    t.preOrder(t.root);  
    System.out.println("\nIn-order traverse:");
    t.inOrder(t.root);  
    System.out.println("\nPost-order traverse:");
    t.postOrder(t.root);  
    System.out.println();  
   }
 }
