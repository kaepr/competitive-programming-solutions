#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int s1 = 0;
    int s2 = 1;
    int s3;
    int f=0;

    for(int i=2; i<n; i++){
        s3 = i;
        if(a[s1] + a[s2] > a[s3] ){
            continue;
        }else{
            f=1;
            break;
        }
    }
    if(f){
        cout<<s1+1<<" "<<s2+1<<" "<<s3+1<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}