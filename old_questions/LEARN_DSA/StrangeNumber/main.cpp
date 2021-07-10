#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll const MAX = 1000000010;
vector<ll> arr;

bool prime[MAX];


void SieveOfEratosthenes() 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // make all entries of boolean array 'prime' 
    // as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
  
    memset(prime, true, sizeof(prime)); 
  
    for (int p = 2; p * p < MAX; p++) { 
        // If prime[p] is not changed, then it is a prime 
  
        if (prime[p] == true) { 
  
            // Update all multiples of p 
            for (int i = p * 2; i < MAX; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // store all prime numbers 
    // to vector 'arr' 
    for (int p = 2; p < MAX; p++) 
        if (prime[p]) 
            arr.push_back(p); 
} 
  
// Function to check the number for Primorial prime 
bool isPrimorialPrime(long n) 
{ 
    // If n is not prime Number 
    // return flase 
    if (!prime[n]) 
        return false; 
  
    long long product = 1; 
    int i = 0; 
  
    while (product < n) { 
  
        // Multiply next prime number 
        // and check if product + 1 = n or Product-1 =n 
        // holds or not 
        product = product * arr[i]; 
  
        if (product + 1 == n || product - 1 == n) 
            return true; 
  
        i++; 
    } 
  
    return false; 
} 

ll floorSqrt(ll x) 
{ 
    // Base cases 
    if (x == 0 || x == 1) 
    return x; 
  
   
    ll i = 1, result = 1; 
    while (result <= x) 
    { 
      i++; 
      result = i * i; 
    } 
    return i - 1; 
} 

bool isPrime(ll n) 
{ 
     
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

int main(){
    int t;
    cin>>t;
    while(t>0){
        ll x,k;
        cin>>x>>k;
        if(k*k > x){
            cout<<0<<"\n";
            continue;
        }
        if(x==1){
            cout<<0<<"\n";
            continue;
        }
        if(k==1){
            cout<<1<<"\n";
        }else if(k==2){
            if(isPrime(x)){
                cout<<0<<"\n";
            }else{
                cout<<1<<"\n";
            }
        }else if(k>2){
            if(isPrime(x)){
                cout<<0<<"\n";
            }else{
                cout<<1<<"\n";
            }
        }
        t--;
    }
    return 0;
}