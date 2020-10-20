#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
using namespace std;
#include <conio.h>
//==================
#include "lib.h"
#include "marking.h"
#include "BookList.h"
#include "ReaderList.h"
//--------------------------------
int main()
  {system("cls");
    char choice;
    int nTestCases = 9;
    Marking w(nTestCases);
    BookList t; 
    ReaderList h;
    while(true)
     {cout<<endl;
      cout<<" 1. Test f1 (1 mark)"<<endl;
      cout<<" 2. Test f2 (1 mark)"<<endl;
      cout<<" 3. Test f3 (1 mark)"<<endl;
      cout<<" 4. Test f4 (1 mark)"<<endl;
      cout<<" 5. Test f5 (1 mark)"<<endl;
      cout<<" 6. Test f6 (1 mark)"<<endl;
      cout<<" 7. Test f7 (1 mark)"<<endl;
      cout<<" 8. Test f8 (1 mark)"<<endl;
      cout<<" 9. Test f9 (1 mark)"<<endl;
      cout<<" a. Test all cases & view marks"<<endl;
      cout<<" 0. Exit "<<endl;
      cout<<"    Your selection (0 -> a): ";
      choice = getche();
      choice = toupper(choice);
      if(choice=='0') break;
      switch(choice)
       {
        case '1': cout<<"\n 1. Test f1:"<<endl;
                    t.f1();
                    cout<<"Your output:"<<endl;
                    viewFile("f1.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f1.txt");
                    if(w.isEqual("f1.txt","R_f1.txt"))
                      cout<<"Mark = "<<w.mark[1]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '2': cout<<"\n 2. Test f2:"<<endl;
                    t.f2();
                    cout<<"Your output:"<<endl;
                    viewFile("f2.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f2.txt");
                    if(w.isEqual("f2.txt","R_f2.txt"))
                      cout<<"Mark = "<< w.mark[2]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '3': cout<<"\n 3. Test f3:"<<endl;
                    t.f3();
                    cout<<"Your output:"<<endl;
                    viewFile("f3.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f3.txt");
                    if(w.isEqual("f3.txt","R_f3.txt"))
                      cout<<"Mark = "<<w.mark[3]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '4': cout<<"\n 4. Test f4:"<<endl;
                    t.f4();
                    cout<<"Your output:"<<endl;
                    viewFile("f4.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f4.txt");
                    if(w.isEqual("f4.txt","R_f4.txt"))
                      cout<<"Mark = "<<w.mark[4]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '5': cout<<"\n 5. Test f5:"<<endl;
                    t.f5();
                    cout<<"Your output:"<<endl;
                    viewFile("f5.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f5.txt");
                    if(w.isEqual("f5.txt","R_f5.txt"))
                      cout<<"Mark = "<<w.mark[5]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '6': cout<<"\n 6. Test f6:"<<endl;
                    t.f6();
                    cout<<"Your output:"<<endl;
                    viewFile("f6.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f6.txt");
                    if(w.isEqual("f6.txt","R_f6.txt"))
                      cout<<"Mark = "<<w.mark[6]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '7': cout<<"\n 7. Test f7:"<<endl;
                    t.f7();
                    cout<<"Your output:"<<endl;
                    viewFile("f7.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f7.txt");
                    if(w.isEqual("f7.txt","R_f7.txt"))
                      cout<<"Mark = "<<w.mark[7]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '8': cout<<"\n 8. Test f8:"<<endl;
                    t.f8();
                    cout<<"Your output:"<<endl;
                    viewFile("f8.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f8.txt");
                    if(w.isEqual("f8.txt","R_f8.txt"))
                      cout<<"Mark = "<<w.mark[8]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case '9': cout<<"\n 9. Test f9:"<<endl;
                    h.f9();
                    cout<<"Your output:"<<endl;
                    viewFile("f9.txt");
                    cout<<"Correct output:"<<endl;
                    viewFile("R_f9.txt");
                    if(w.isEqual("f9.txt","R_f9.txt"))
                      cout<<"Mark = "<<w.mark[9]<<endl;
                        else
                          cout<<"Mark =  0"<<endl;
                    break;

        case 'A': 
                    t.f1();
                    t.f2();
                    t.f3();
                    t.f4();
                    t.f5();
                    t.f6();
                    t.f7();
                    t.f8();
                    h.f9();
                    w.doMarking();
                    break;
       }
     }
    cout<<endl;
    return(0);
   }

