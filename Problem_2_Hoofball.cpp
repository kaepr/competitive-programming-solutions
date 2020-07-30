#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
int x[100], pass[100], N;

int target(int i){
    int left = -1, ldist = 1000;
    int right = -1, rdist = 1000;
    
    //finding closest neighbours on left and right
    for(int j=0; j<N; j++)
        if(x[j] < x[i] && x[i] - x[j] < ldist)
            left = j, ldist = x[i] - x[j];
    
    for(int j=0; j<N; j++)
        if(x[j] > x[i] && x[j] - x[i] < rdist)
            right = j, rdist = x[j] - x[i];
        
    if(ldist <= rdist)
        return left;
    else
        return right;
    
}

int main()
{
    freopen("hoofball.in","r",stdin);
    freopen("hoofball.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=0; i<N; i++)
        cin>>x[i];
    
    for(int i=0; i<N; i++)
        pass[target(i)]++;
    
    int ans = 0;
    for(int i=0; i<N; i++){
        if(pass[i]==0)
            ans++;
        if(i<target(i) && target(target(i)) == i && pass[i] ==1 && pass[target(i)]==1)
            ans++;
    }
    cout<<ans<<"\n";
    
    



    return 0;
}