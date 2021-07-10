#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
    cin>>n;
    int x[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cout<<abs(x[i]-x[i+1])<<" "<<abs(x[0]-x[n-1])<<endl;
        }
        else if(i==n-1)
        {
            cout<<abs(x[i]-x[i-1])<<" "<<abs(x[i]-x[0])<<endl;
        }
        else{
            cout<<min(abs(x[i]-x[i-1]),abs(x[i]-x[i+1]))<<" "<<max(abs(x[i]-x[0]),abs(x[i]-x[n-1]))<<endl;
        }
    }
    return 0;
	
}	
