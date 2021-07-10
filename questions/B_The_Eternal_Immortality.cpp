#include <bits/stdc++.h>
using namespace std;

int computeLastDigit(long long int A, long long int B) 
{ 
  
    int variable = 1; 
    if (A == B)
        return 1; 
  
    
    else if ((B - A) >= 5)  
        return 0; 
  
    else { 
        for (long long int i = A + 1; i <= B; i++) 
            variable = (variable * (i % 10)) % 10; 
  
        return variable % 10; 
    } 
} 
  
// driver function 
int main() 
{ 
    long long a,b;
    cin>>a>>b;
    long long ans = computeLastDigit(a,b);
    cout<<ans;
    return 0; 
} 