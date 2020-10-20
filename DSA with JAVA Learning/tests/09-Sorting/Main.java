/*
You cannot modify or add new statement to the main() function.
However you can disable statements in the main() method if you
cannot complete the corresponding function(s).
Except the main() method, you can modify or add new members to
other class(es) or even you can create new class(es), e.g. you
can delete or modify a given statement(s).
*/
class Person 
 {String name; int age;  ;
  Person(String name1, int age1) 
   {name=name1;age=age1;
   }
  public String toString() 
   {return("(" + name+","+age + ")");
   }
  public boolean equals(Person x)
   {return(name.equals(x.name));
   }
  public int compareTo(Person x)
   {return(name.compareTo(x.name));
   }
//simple selection sort
 }

class MyList 
 {Person [] a;
  MyList() {a=null;} 
  void clear() {a=null;} 
  void setData(String [] p, int [] q)
    {int n = p.length;
     a = new Person[n];
     for(int i=0;i<n;i++)
       a[i] = new Person(p[i],q[i]);
    }
   void display()
    {for(int i=0;i<a.length;i++)
        System.out.print(" " + a[i]);
     System.out.println();
    }
//---------selection sort----------------------------------
  /*
  The following is the main part of selection sort pseudocode:
  for i := 0 to n-2 // large loop
  find a[k], where a[k] = min {a[i], a[i+1],...,a[n-1]}
  if k # i then swap a[i] with a[k]
  end for
  */
  //Sort the array a and display the array at each of first r steps (i=0,1,...,r-1)
  void selectSort(int r)
   {
   }
//---------insertion sort----------------------------------
  /*
  The following is the main part of insertion sort pseudocode:
  for i := 1 to n-1 
    insert a[i] into sorted sublist {a[0],...,a[i-1]}
    so that the sortedness is still kept. 
  end for
  */
  //Sort the array a and display the array at each of first r steps (i=0,1,...,r-1)
  void insertSort(int r)
   {
   }
//---------bubble sort----------------------------------
  /*
  The following is the main part of bubble sort pseudocode:
  do
    swapped := false
    for i := 0 to n-2 
      if a[i] > a[i+1] then
        swap(a[i],a[i+1])
        swapped := true
      end if
    end for
  while swapped
  */
  //Sort the array a and display the array at each of first r steps (i=0,1,...,r-1)
  void bubbleSort(int r)
   {
   }
//---------partition technique----------------------------------
  /*
  Partitioning is a technique used in quicksort. The following is a partition pseudocode: 
  partition the array  a  from index low to index up
   x := a[low], i=low, j=up
   do 
    increase i and stop at i, where  a[i]>x 
    decrease j and stop at j, where  a[j]<=x 
    if(i<j) swap a[i] with a[j]
   while(i<j)
   swap  a[0] with a[j]
  */
  int partition(int low,int up) // return pivot index
   {int pivot=0;
    return(pivot);
   }
  //--------Quick sort--------------------------------------------
  void quickSort(int low,int up)
   {
   }
//----------Heap sort---------------------------------------------
  void createHeap()
   {/*Chuyen danh sach thanh HEAP bang cach xem khoi dau heap gom nut
      a[0], sau do lan luot chuyen cac nut a[1],a[2],..., a[n-1] vao heap*/
   }
  void heapSort()
   {
   };
 }

//=====================================
public class Main	// 6 s
 {public static void main(String args[])
   {MyList t = new MyList();
    String [] p = {"A44","A75","A23","A43","A55","A12","A64","A77","A33"};
    int [] q = {20,21,19,18,22,24,17,25,16};
    int r = 3;

    {System.out.println("\n 1. Test simple selection sort (2 marks) - 2");
     t.clear();
     t.setData(p,q);
     System.out.println("\n Before sorting:");
     t.display();
     System.out.println("\n While sorting:");
     t.selectSort(r);
     System.out.println("\n After sorting:");
     t.display();
    }

    {System.out.println("\n 2. Test insertion sort (2 marks) - 4");
     t.clear();
     t.setData(p,q);
     System.out.println("\n Before sorting:");
     t.display();
     System.out.println("\n While sorting:");
     t.insertSort(r);
     System.out.println("\n After sorting:");
     t.display();
    }

    {System.out.println("\n 3. Test bubble sort (2 marks) - 6");
     t.clear();
     t.setData(p,q);
     System.out.println("\n Before sorting:");
     t.display();
     System.out.println("\n While sorting:");
     t.bubbleSort(r);
     System.out.println("\n After sorting:");
     t.display();
    }

    {System.out.println("\n 4. Test partitioning (1 mark) - 7");
     t.clear();
     t.setData(p,q);
     System.out.println("\n Before partitioning:");
     t.display();
     System.out.println("\n After partitioning:");
     t.partition(0,t.a.length-1);
     t.display();
    }


    {System.out.println("\n 5. Test quick sort (1 mark) - 8");
     t.clear();
     t.setData(p,q);
     System.out.println("\n Before sorting:");
     t.display();
     System.out.println("\n After sorting:");
     t.quickSort(0,t.a.length-1);
     t.display();
    }

    {System.out.println("\n 6. Test heap sort (2 marks) - 10");
     t.clear();
     t.setData(p,q);
     System.out.println("\n Before sorting:");
     t.display();
     System.out.println("\n The list after organized to heap:");
     t.createHeap();
     t.display();
     System.out.println("\n After sorting:");
     t.heapSort();
     t.display();
    }

    System.out.println();       
   }
 }
