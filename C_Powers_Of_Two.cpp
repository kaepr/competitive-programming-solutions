#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    priority_queue<int> p;
    int j = 0;
    while(n){
        if(n & 1){
            p.push(pow(2,j));
            k--;
        }
        j++;
        n>>=1;
    }
    if(k < 0){
        cout<<"NO\n";
    }else{
        while(k){
            int x = p.top();
            p.pop();
            x>>=1;
            if(x >= 1){
                p.push(x);
                p.push(x);
                k--;
            }
            else{
                break;
            }
        }
        if(k)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            while(!p.empty()){
                cout<<p.top()<<" ";
                p.pop();
            }
        }
    }

    return 0;
}