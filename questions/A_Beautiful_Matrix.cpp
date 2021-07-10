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

    int arr[5][5];
    int x=0,y=0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            int a;
            cin>>a;
            if(a==1){
                x = i;
                y = j;
            }
        }
    }

    int ans = abs(x - 2) + abs(y - 2);
    cout<<ans<<"\n";

    
    return 0;
}