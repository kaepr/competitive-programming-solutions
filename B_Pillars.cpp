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
    vector<int> a(n);
    for(int i=0; i<n; i++)  
        cin>>a[i];
    
    int pos = max_element(a.begin(), a.end()) - a.begin();

    bool res = 1;
    for(int i=0; i<pos; i++)
        res &= (a[i] < a[i+1]);
    
    for(int i=pos; i<n-1; i++){
        res &= (a[i] > a[i+1]);
    }

    if(res)
        cout<<"YES\n";
    else
        cout<<"NO\n";
      
    return 0;
}