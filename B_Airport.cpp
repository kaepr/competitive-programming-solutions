#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    int a[1000];
    for(int i=0; i<m; i++)
        cin>>a[i];
    
    sort(a, a+m);
    int minimum=0, num = a[0], k = 0;
    for(int i=0; i<n; i++){
        minimum += num;
        num = num - 1;
        if(num==0){
            num = a[++k];
        }
    }

    sort(a, a+m, greater<int>());
    int maximum = 0;
    while(n--){
        maximum += a[0];
        a[0] = a[0] - 1;
        for(int i=1; i<m; i++){
            if(a[i] <= a[i-1])
                break;
            swap(a[i], a[i-1]);
        }
    }
    cout<<maximum<<" "<<minimum<<"\n";


    
    return 0;
}