#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;
#include"AssLib.h"
#include"Booklist.h"
#include"Readerlist.h"
#include"Lendinglist.h"

int main(){
	int choiceBook, choiceList, choiceReader, choiceLending, state;
	BooksList b;
	ReaderList c;
	LendingList d;
	string Bcode, Rcode;
	Books x("B06", "Facebook Marketing", 14, 7, 15);
	Books z("B21", "Blood and War", 14,7,15);
	while(1){
		cout<<"1- BOOKLIST\n2-READERLIST\n";
		cout<<"Enter your choice: ";
		cin>>choiceList;
		if(choiceList==0) break;
		switch(choiceList){
			case 1:
				cout<<"BOOKLIST"<<endl;
        		cout<< "1.1   Load data from file\n";
        		cout<< "1.2   Input & add to the end\n";
        		cout<< "1.3   Display data\n";
        		cout<< "1.4   Save book list to file\n";
        		cout<< "1.5   Search by bcode\n";
        		cout<< "1.6   Delete by bcode\n";
        		cout<< "1.7   Sort by bcode\n";
        		cout<< "1.8   Input & add to beginning\n";
        		cout<< "1.9   Add after position k\n";
        		cout<< "1.10  Delete position k\n";
				while(1){
    				fflush(stdin);
        			cout<< "Enter your choice: ";
        			cin >> choiceBook;
        			if(choiceBook==0) break;
        			switch(choiceBook){
        				case 1:
        					b.loadFromFile();
        					break;
        				case 2:
        					cout << "Test add to tail" <<endl;
          					b.addToTail(x);
          					b.traverse();
        					break;
        				case 3:
        					b.traverse();
        					break;
        				case 4:
        					b.saveToFile();
        					break;
        				case 5:
        					cout << "Test search code B04" << endl;
        					b.visit(b.search("B04"));
        					break;
        				case 6:
        					cout << "Test delete code B04" << endl;
        					b.dele("B04");
        					b.traverse();
        					break;
        				case 7:
        					b.sort();
        					b.traverse();
        					break;
        				case 8:
        					cout << "Test add to head" << endl;
        					b.addToHead(z);
        					b.traverse();
        					break;
        				case 9:
        					cout << "Test add after 3rd position" << endl;
        					b.addAfter(3,z);
        					b.traverse();
        					break;
        				case 10:
        					cout << "Test delete 4th position " << endl;
        					b.delel(4);
        					b.traverse();
        					break;
        				default:
        					cout << "Please enter 1->10 only!" << endl;
        					break;
        				system("pause");
        			}
        		}
        	case 2: 
        		cout<<"READERLIST"<<endl;
        		cout<< "2.1.   Input & add to the end\n";
        		cout<< "2.2.   Display data\n";
        		cout<< "2.3.   Save reader list to file\n";
        		cout<< "2.4.   Search by rcode\n";
        		cout<< "2.5.   Delete by rcode\n";
				while(1){
    				fflush(stdin);
        			//system("cls");
        			cout<< "Enter your choice: ";
        			cin >> choiceReader;
        			if(choiceReader==0) break;
        			switch(choiceReader){
        				case 1:
        					c.rLoadFromFile();
        					cout << "Test add to tail" <<endl;
          					c.rAddToTail(y);
          					c.rTraverse();
        					break;
        				case 2:
        					c.rTraverse();
        					break;
        				case 3:
        					c.rSaveToFile();
        					break;
        				case 4:
        					cout << "Test search code R50" << endl;
        					c.rVisit(c.rSearch("R50"));
        					break;
        				case 5:
        					cout << "Test delete code R50" << endl;
        					c.rDele("R50");
        					c.rTraverse();
        					break;
        				default:
        					cout << "Please enter 1->5 only!" << endl;
        					break;
        				system("pause");
        			}
        		}
        	case 3:
        		cout<<"LENDINGLIST\n";
        		cout<<"3.1.   Input data\n";
        		cout<<"3.2.   Display data\n";
        		cout<<"3.3.   Sort by book code\n";
        		cout<<"3.4.   Sort by reader code\n";
        		while(1){
        			fflush(stdin);
        			cout<<"Enter your choice: ";
        			cin>> choiceLending;
        			if(choiceLending==0) break;
        			switch(choiceLending){
        				case 1: while(1){
        					cout<<"Enter book code: ";
        					cin>>Bcode;;
							cout<<"Enter reader code: ";
							cin>>Rcode;
							cout<<"Enter state (only 0, 1 or 2 ): ";
							cin>>state;
							if(b.search(Bcode)==NULL||c.rSearch(Rcode)==NULL){
								cout<<"Not found. Re-enter!\n";
								break;
								}
							else{
								if(state==1){
									cout<<"The book is still at the reader, not given back. Re-enter!\n";
									}
								if(b.search(Bcode)->info.lended==b.search(Bcode)->info.quantity){
									state = 0;
									Lending l = Lending(Bcode,Rcode,state);
									d.lAddToTail(l);
									}
								if(b.search(Bcode)->info.lended<b.search(Bcode)->info.quantity){
									state = 1;
									Lending l = Lending(Bcode,Rcode,state);
									++b.search(Bcode)->info.lended;
									d.lAddToTail(l);
									}
								}
							}
							break;
						case 2:
							d.lTraverse();
							break;
						case 3:	
							d.lSortByBcode();
							break;
						case 4:
							d.lSortByRcode();
							break;
							}		
						} 
					}		
        		}
			
	return 0;
}
