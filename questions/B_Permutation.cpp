#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    map<int,int> elms;
    for(int i=0; i<n; i++)
        elms[a[i]]++;
    
    int total=0;
    for(auto i : elms){
        if(i.first > n){
            total+=i.second;
        }else{
            total += i.second - 1;
        }
    }
    cout<<total<<"\n";
    return 0;
}