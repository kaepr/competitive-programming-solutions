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

    int b,g,n;
    cin>>b>>g>>n;
    int ans=0;
    for(int i=0; i<=n; i++){
        //blue badges
        int blue = i;
        int red = n - i;
        if(g>=red && b>=blue){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}

/*
0th
0 3

1th
1 2

2nd 
2 1

3th
3 0
*/