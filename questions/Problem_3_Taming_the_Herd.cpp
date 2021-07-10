#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[0] = 0;
    int f = 1;
    int ptr = n - 1;
    while (1)
    {
        if(ptr <= 0){
            break;
        }else if (a[ptr] == -1)
        {
            ptr--;
        }
        else if (a[ptr] > 0)
        {
            int day = a[ptr];
            
            for (int i = 0; i < day; i++)
            {
                if(a[ptr - i - 1] == -1){
                    a[ptr - i - 1] = day - 1 - i;
                }else if(a[ptr -i - 1] != day - 1 -i){
                    f = 0;
                }
            }
            ptr = ptr - day - 1;
        }else if(a[ptr]==0){
            ptr--;
        }
    }

    if(f==0){
        cout<<-1<<"\n";
    }else{
        int ans_min=0, ans_max=0;
        for(int i=0; i<n; i++)
            if(a[i]==0)
                ans_min++;
            
        for(int i=0; i<n; i++)
            if(a[i]==0 || a[i]==-1)
                ans_max++;
            
        cout<<ans_min<<" "<<ans_max<<"\n";
    }

    return 0;
}