#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int top;
    cin >> top;
    vector<bool> v(7,0);
    bool ans = true;
    for(int i =0;i<n;i++){
        int x,y;
        cin >> x >> y;
        if(x == top || x == 7 - top){
            ans = false;
        }
        if(y == top || y == 7 - top){
            ans = false;
        }
    }
    if(ans){
        cout <<"YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
