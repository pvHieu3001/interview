#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include"assert.h"
using namespace std;
#include"lib.h"
#include"BookList.h"
#include"ReaderList.h"
#include"LendingList.h"

int InputInt(int Max, int Min);

int main()
{
	int choiceBook, choiceList, choiceReader, choiceLending, state;
	BookList b;
	ReaderList c;
	LendingList d;
	string Bcode, Rcode;string a;
	while(1){
		
				cout<<"=====B O O K L I S T====="<<endl;
        		cout<< "1.1.   Load data from file\n";
        		cout<< "1.2.   Input & insert data\n";
        		cout<< "1.3.   In-order traverse\n";
        		cout<< "1.4.   Breadth-first traverse\n";
        		cout<< "1.5.   In-order traverse to file\n";
        		cout<< "1.6.   Search by BCode\n";
        		cout<< "1.7.   Delete by bcode by copying\n";
        		cout<< "1.8.   Simply balancing\n";
        		cout<< "1.9.   Count number of books\n";
				while(1)
    			{
    				fflush(stdin);
        			//system("cls");
        			cout<< "Enter your choice( 0 -> 9): ";
        			choiceBook = InputInt(0,9);
        			if(choiceBook==0) break;
        			switch(choiceBook)
        			{
        				case 1:
        				   cout << "Load data from file" <<endl;
        					b.loadFromFile();
        					b.breadth(b.root);
        					break;
        				case 2:
        				   cout<<"In-order "<<endl;
        					b.inOrder(b.root);
        					break;
        				case 3:
        				   cout<<"deleByCopy"<<endl;
        					b.deleByCopy("B04");
        					b.preOrder(b.root);
        					break;
        				case 4:
        					cout << "In-order traverse to file  " << endl;
       					b.saveToFile();
        					break;
        				case 5:
        					cout << "Simply balance" << endl;
        					b.balance();
        					b.breadth(b.root);
        					break;
        				case 6:
        					cout << "breadth " << endl;
        					b.breadth(b.root);
        					break;
        				case 7:
        					cout << "Simply balance" << endl;
        					b.balance();
        					b.breadth(b.root);
        					break;
        				case 8:
        					cout << "Count number of books" << endl;
        					cout<<"The number of books is: "<<b.count(b.root)<<endl;
        					b.breadth(b.root);
        					break;
        				default:
        					cout << "Please enter 1->10 only!" << endl;
        					break;
        				system("pause");
        			}
        		}
 
	} 

	return 0;
}
int InputInt(int Min,int Max)
{
	bool keepgoing = true;
	int n = 0;
	while(keepgoing)
	{
      cin>>n;
		if(cin.fail())
		{
			cout<<"     Entered value is invalid, plz re-enter: ";
			cin.clear();
			cin.ignore(2000,'\n');
		}
		else if(char(cin.get()) != '\n')
		{
			cout<<"     Entered value is invalid, plz re-enter: ";
			cin.clear();
			cin.ignore(2000,'\n');
		}
		else if(n < Min || n > Max)
		{
			cout<<"     Entered value is invalid, plz re-enter: ";
		}
		else keepgoing = false;
	}
	return n;
}
