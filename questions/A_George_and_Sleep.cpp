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

    int h[2],m[2];
    for(int i=0; i<2; i++){
        scanf("%d:%d", &h[i], &m[i]);
    }
    h[0] -= h[1];
    m[0] -= m[1];
    if(m[0] < 0)
        m[0] += 60, h[0]--;
    
    if(h[0] < 0)
        h[0] += 24;
    
    printf("%02d:%02d\n", h[0], m[0]);
    
      
    return 0;
}