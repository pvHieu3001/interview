#include <iostream>
#include <string>
#include <new>
using namespace std;

class Lending{
	public:
	string lBcode, lRcode;
	int state;
	Lending(){}
	Lending(string a, string b, int c){
		lBcode = a;
		lRcode = b;
		state = c;
	}
	void setDataLending(string a, string b, int c){
		lBcode = a;
		lRcode = b;
		state = c;
	}
};

class LendingNode{
	public:
	Lending info;
	LendingNode *next;
	LendingNode(){}
	LendingNode(Lending x, LendingNode *p){
		info = x;
		next = p;
	}	
};

class LendingList{
	public:
	LendingNode *head; LendingNode *tail;
	LendingList()
	{
		head = tail = NULL;
	}
	
	bool lIsEmpty()
	{
		return (head == NULL);
	}
	void lVisit(LendingNode *p)
	{
		cout << left << setw(4) << p->info.lBcode << "| " << left << setw(14) <<  p->info.lRcode << "| " << left << setw(8) << p->info.state << endl;
	}
	void lTraverse()
	{
		if(lIsEmpty())
		{
			cout << "Empty book list!" << endl;
		}
		else
		{
			LendingNode *p = head;
			while (p!=NULL)
			{
				lVisit(p);
				p=p->next;
			}		
		}	
	}
  
   void lAddToTail(Lending x)
	{
	   
		LendingNode *q = new LendingNode(x,NULL);
		if(lIsEmpty())
		{
			head = tail = q;
		}
		else
		{
			tail -> next = q;
			tail = q;
		}
	}
	void sortByBcode(){
     LendingNode *pi, *pj;
     Lending x;
     pi = head;
     while(pi != NULL){
        pj = pi->next;
        while(pj != NULL){
           if(pi->info.lBcode > pj->info.lBcode){
              x = pi->info; pi->info = pj->info; pj->info  = x;
           }
           pj = pj->next;
        }
        pi = pi->next;
     }
   }
  	void sortByRcode(){
      LendingNode *pi, *pj;
      Lending x;
      pi = head;
      while(pi != NULL){
         pj = pi->next;
         while(pj != NULL){
            if(pi->info.lRcode > pj->info.lRcode){
               x = pi->info; pi->info = pj->info; pj->info  = x;
            }
            pj = pj->next;
         }
         pi = pi->next;
      }
     }
	
	
};
