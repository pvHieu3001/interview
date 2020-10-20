string trim(string s);
void split(string s, string a[], int &n, char ch);
double toDouble(string u, int k);
int toInteger(string u);
 
 
 
 	//string handler
    string trim(string s){
    	string x="";
    	char a[100]; strcpy(a,s.c_str());
    	int i,j,r;i=0;j=strlen(a)-1;
    	while(a[i]==' ' || a[i]=='\r' || a[i]=='\n') i++;
    	while(a[j]==' ' || a[j]=='\r' || a[j]=='\n') j--;
    	for(r=i;r<=j;r++) x += a[r];
    	return(x);
	}
		
		
	// Chuyen ve so thuc co k so le sau dau cham thap phan
	double toDouble(string u, int k){
		u = trim(u);int n,i,j;
		n = u.size();
		char x[20]; strcpy(x,u.c_str());
		i=0;
		while(x[i] != '.') i++;
		j = i+k+1;
		if(j<n) n = j;
		x[n] = '\0';
		return(atof(x));
	}
	
    void split(string s, string a[], int &n, char ch){
    	int i,j,m; string x;
    	s = trim(s);
    	m = s.length();
    	i=0;j=0;
    	while(i<m){
        	while(i<m && s.at(i) ==ch) i++;
        	x="";
        	while(i<m && s.at(i) !=ch)  x += s.at(i++);
        	a[j++]=trim(x);
    	}
    	n = j;
	}
	
	int toInteger(string u){
		u = trim(u);
		char x[20]; strcpy(x,u.c_str());
		return(atoi(x));
	}
