#include <bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;

int t,n,k;

struct node{
    int s,f,p;
};

void fs(int &number) 
{ 
    //variable to indicate sign of input number 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = gc(); 
     
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=gc()) 
        number = number *10 + c - 48; 
} 

bool operator<(node const &a,node const &b)
{
    return(a.p!=b.p)?(a.p<b.p):(a.f<b.f);
}

int main() {
	// your code goes here
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(0);
	
	fs(t);
	while(t--){
	    fs(n);
	    fs(k);
	    node v[n];
	    int c=1,q=0;
	    
	    for(int i=0;i<n;i++){
	        fs(v[i].s);
	        fs(v[i].f);
	        fs(v[i].p);
	    }
	    if(n==0 || n==1)
	        cout<<n<<"\n";
	   else{
	       sort(v,v+n);
	    
	    for(int i=1;i<n;i++){
	        if((v[i].p != v[i-1].p) || (v[i].p == v[i-1].p && v[i].s >= v[q].f)){
	            c++;
	            q=i;
	        }
	    }
	    
	    cout<<c<<"\n";
	   }
	    
	    
	}
	return 0;
}
/* Display
	    for(int i=0;i<n;i++){
	        for(int j=0;j<3;j++)
	            cout<<v[i][j]<<" ";
	       cout<<endl;
	    }
	    */