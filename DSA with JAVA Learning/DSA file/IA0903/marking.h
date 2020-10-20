// ======= DO NOT EDIT THIS FILE ============
class Foo
 {public:
  string u[100];int  n;
  void set(string v[], int m) 
   {n = m;
   for(int i=0;i<n;i++) u[i] = v[i];
   }
  void setTrim() 
   {for(int i=0;i<n;i++) u[i]=trim(u[i]);
   }
  bool equal(Foo y)
   {if(n != y.n) return(false);
    setTrim(); y.setTrim();
    for(int i=0;i<n;i++)
     if(u[i] != y.u[i]) return(false);
    return(true); 
   }
  void display()
   {for(int i=0;i<n;i++) cout<<u[i]<<" ";
    cout<<endl;
   }
 };
void display(Foo a[], int n)
 {for(int i=0;i<n;i++) a[i].display();
  cout<<endl;
 }
class Marking 
 {public:
  int nOuFi;// Number of files containing output  
  double mark[20];  
  Marking(int k) 
   {nOuFi=k;
    for(int i = 1; i<= nOuFi; i++) mark[i] = 1.0;
    if(nOuFi==4) mark[3] = mark[4] = 1.5;
   }

  void loadFile(char * fname ,Foo a[], int &n) // Read lines in a file to the array of  Foo objects
   {ifstream fin(fname);
    string s,b[100];int k,m,i; Foo  x;
    k = 0;
    while(fin.good())
      {s="";
       getline(fin,s,'\n');
       s = trim(s); 
       if(s.size()==0) continue;
       split(s,b,m);
       for(i=0;i<m;i++) 
         {if(isDouble(b[i])) b[i] = toDoubleStr(b[i]);// Neu la so thuc thi chi lay 2 chu so le
         }
       x.set(b,m);
       a[k++] = x;
      }
      n=k;
      fin.close();
    }

  bool isEqual(char * fname1, char * fname2)
    {int m,n,i; Foo a[100], b[100];
     loadFile(fname1,a,m);
     loadFile(fname2,b,n);
     if(m != n) return(false);
     for(i=0;i<n;i++)
       {if(!a[i].equal(b[i])) return(false);
       }
     return(true);
    }

bool checkResultFile()
   {char fname[30];char x[10];int i;
    for(i=1;i<=nOuFi;i++)
     {itoa(i,x,10);
      strcpy(fname,"R_f");
      strcat(fname,x);
      strcat(fname,".txt");
      if(!exist(fname)) return(false); 
     }
    return(true);
   }

  void doMarking()
   {if(!checkResultFile())
      {cout<<"\n This option cannot be done because correct-output files are missing!"<<endl;
       return;
      }
    char * fname = "result.txt";
    if(exist(fname)) remove(fname);
    ofstream fou(fname);
    int i; double mar,sum;
    char  fa[20], fb[20], x[10];;
    sum = 0;
    for(i=1;i<=nOuFi;i++)
     {itoa(i,x,10);
      strcpy(fa,"f");
      strcat(fa,x);
      strcat(fa,".txt");
      strcpy(fb,"R_f");
      strcat(fb,x);
      strcat(fb,".txt");
      if(!exist(fa) || !isEqual(fa,fb)) mar=0; else mar = mark[i];
      sum += mar;
      if(mar == 1)
        fou<<"  f"<<i<<" : "<<mar<<" mark"<<endl;
         else
          fou<<"  f"<<i<<" : "<<mar<<" marks"<<endl;
     }
    fou<<"  Total marks: "<<sum <<endl;
    fou.close();
    viewFile(fname);
   }
 };
