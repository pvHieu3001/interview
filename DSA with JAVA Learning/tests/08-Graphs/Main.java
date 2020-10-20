/*
You cannot modify or add new statement to the main() function.
However you can disable statements in the main() method if you
cannot complete the corresponding function(s).
Except the main() method, you can modify or add new members to
other class(es) or even you can create new class(es), e.g. you
can delete or modify a given statement(s).
*/
import java.io.*;
import java.util.*;
class MyStack
 {LinkedList t;
  MyStack() {t = new LinkedList();}
  boolean isEmpty() {return(t.isEmpty());}
  void push(int k) {}
  int pop() {return(-1);}
  int viewtop() {return(-1);}
 }

class MyQueue
 {LinkedList t;
  MyQueue() {t = new LinkedList();}
  boolean isEmpty() {return(t.isEmpty());}
  void enqueue(int k) {}
  int dequeue(){return(-1);}
  int front(){return(-1);}
 }

class Graph
 {int [][] a; int n;
  char [] v; static int INF = 99; // 99 is considered as infinity value 
  Graph()
   {String s = "ABCDEFGHIJKLMN";
    v = s.toCharArray();//v[0]='A', v[1]='B',...
   }
  void setDataFromFile(String filename) throws IOException
   {int i,j;
    String s="", s1="";
    StringTokenizer t;
    RandomAccessFile f; 
    f = new RandomAccessFile(filename, "r");
    s = f.readLine();// The first line contains number of vertices
    n = Integer.parseInt(s.trim());
    a = new int[n][n];
    for(i=0;i<n;i++)
     {s = f.readLine();
      t = new StringTokenizer(s);
      for(j=0;j<n;j++)
       {s1 = t.nextToken();
        a[i][j]=Integer.parseInt(s1.trim());
       }
     }

    f.close();
   }
  void setDataFromArray(int [][] b)
   {int i,j,t;
    n = b.length;
    a = new int[n][n];
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
           a[i][j]=b[i][j];
   }
  void visit(int i)
   {System.out.print(" " + v[i]);
   }
  void dispAdj() {}
  void dispDegrees() {}
  void depthFirst(int k) {}
  boolean isConnected() {return(false);}
  void breadthFirst(int k) {}
  void dijkstra(int p, int q) {}
 }

//========================================================
class Main 
 {public static void main(String [] args) throws Exception
   {int [][] b = {
                 {0,1,0,0,1},
                 {1,0,0,1,1},
                 {0,0,0,1,0},
                 {0,1,1,0,0},
                 {1,1,0,0,0}
                };

    Graph g =new Graph();

    {System.out.println("\n1. Test depth first traverse (2 marks)-2");
     System.out.println(" Connected graphs:");
     g.setDataFromArray(b);
     g.dispAdj();
     g.depthFirst(0);
     g.setDataFromFile("graph2.txt");
     g.dispAdj();
     g.depthFirst(0);
     System.out.println("\n Non-connected graphs:");
     g.setDataFromFile("graph3.txt");
     g.dispAdj();
     g.depthFirst(0);
    }   

    {
     System.out.println("\n2. Calculate degrees of vertices (2 marks)-4");
     g.setDataFromFile("graph2.txt");
     g.dispAdj();
     g.dispDegrees();
    }

    {System.out.println("\n3. Check connectivity (2 marks)-6");
     System.out.println(" Connected graphs:");
     g.setDataFromArray(b);
     g.dispAdj();
     if(g.isConnected())
       System.out.println(" The graph above is connected.");
        else
         System.out.println(" The graph above is not connected.");
     System.out.println("\n Non-connected graphs:");
     g.setDataFromFile("graph3.txt");
     g.dispAdj();
     if(g.isConnected())
       System.out.println(" The graph above is connected.");
        else
         System.out.println(" The graph above is not connected.");
    }   

    {System.out.println("\n4. Test breadth first traverse (2 marks)-8");
     System.out.println(" Connected graphs:");
     g.setDataFromArray(b);
     g.dispAdj();
     g.breadthFirst(0);
     System.out.println("\n Non-connected graphs:");
     g.setDataFromFile("graph3.txt");
     g.dispAdj();
     g.breadthFirst(0);
    }   

    {System.out.println("\n5. Test Dijkstra shortest path algorithm (2 marks)-10");
     g.setDataFromFile("graph4.txt");
     g.dispAdj();
     g.dijkstra(0,5); // Shortest path from vertex 1 to vertex 6
    }   

    System.out.println();
   }
  }
