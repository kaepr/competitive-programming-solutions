#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
  
int lcm(int a, int b) 
{ 
    return (a * b) / gcd(a, b); 
} 

int findlcm(int arr[], int n) 
{ 
     
    int ans = arr[0];  
    for (int i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        int lcm_old = findlcm(a,n);

        int max=lcm_old;
        int ans_ind=1;

        for(int i=1; i<=m; i++){
            int new_lcm = lcm(lcm_old,i);
            if(new_lcm>max){
                ans_ind=i;
                max = new_lcm;
            } 
        }
        cout<<ans_ind<<"\n";
        t--;
    }
   return 0;
}