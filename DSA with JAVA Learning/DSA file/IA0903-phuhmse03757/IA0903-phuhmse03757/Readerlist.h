#include <iostream>
#include <string>
#include <new>
using namespace std;

class Reader{public:
		string rcode;
		string name;
		int byear;
		Reader(){
		}
		Reader(string a, string b, int c){
			rcode = a;
			name = b;
			byear = c;
		}
		void setDataReader(string a, string b, int c){
			rcode = a;
			name = b;
			byear = c;
		}
};

class ReaderNode{public:
		Reader info;
		ReaderNode *next;
	
		ReaderNode(){}
		ReaderNode(Reader x, ReaderNode *p){
			info = x;
			next = p;
		}
};

class ReaderList{public:
	ReaderNode *head; ReaderNode *tail;	
	ReaderList(){
		head = tail = NULL;
	}
	bool rIsEmpty(){
		return (head == NULL);
	}
	
	void rLoadFromFile(){
		ifstream fin("userlist.txt");
        if(!fin.is_open()){
            cout<<"File doesn't exist!";
            return;
        }
        else{
            while(fin.good()){
                int n = 0;  string temp[3],s;
                getline(fin,s,'\n');
                split(s,temp,n,'|');
                Reader x(temp[0], temp[1], toInteger(temp[2]));
                if (temp[0] != "") rAddToTail(x);
            }
            cout << "Loaded!" << endl;
            fin.close();
        }
    }
    
    void rSaveToFile(){		
        ofstream fin("userlist.txt");
        if(!fin.is_open()){
            cout<< "Get error while opening!\n";
            return;
        }
        else{
            ReaderNode *p = head;
            while(p){
                fin <<setw(4)<<p->info.rcode<<" | "<<setw(14)<<p->info.name<<" | "
                    <<setw(10)<<p->info.byear<<endl;
                p = p->next;
            }
            cout << "Saved!" << endl;
            fin.close();
        }
    }
	ReaderNode * rSearch(string s){
		ReaderNode *p = head;
		while (p != NULL){
			if(p->info.rcode == s)
				return (p);
			p = p->next;
		}
		return NULL;
	}
	//delete
	void rDele(ReaderNode *q){
		ReaderNode *f, *p;f=NULL; p=head;
     	while(p!=NULL){
		   if(p==q) break;
        	f=p;p=p->next;
    	}
    	delete q;
    	if(p==NULL) return;
    	if(f==NULL){
			head=head->next;
        	if(head==NULL) tail=NULL;
        	return;
    	}
    	f->next = p->next;
    	if(f->next==NULL) tail=f;
	}
	//delete by code
	void rDele(string s){
		ReaderNode *p = rSearch(s);
		rDele(p);
	}
    
	void rVisit(ReaderNode *p){
		cout << left << setw(4) << p->info.rcode << "| " << left << setw(14) <<  p->info.name << "| " << left << setw(8) << p->info.byear << endl;
	}
	
	void rTraverse(){
		if(rIsEmpty()){
			cout << "Empty reader list!" << endl;
		}
		else{
			ReaderNode *p = head;
			while (p!=NULL){
				rVisit(p);
				p=p->next;
			}		
		}	
	}
		//add to tail
	void rAddToTail(Reader x){
		ReaderNode *q = new ReaderNode(x,NULL);
		if(rIsEmpty()){
			head = tail = q;
		}
		else{
			tail -> next = q;
			tail = q;
		}
	}	
};

