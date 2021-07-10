#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, b, m;
    cin >> n >> b >> m;
    int access[m];
    for (int i = 0; i < m; i++)
        cin >> access[i];

    set<array<int, 2>> blocks;
    int l = 0;
    int r = 0;

    int type[n] = {0};
    int data=1;
    for(int r=0; r<n; r++){
        if(r-l==b-1){
            for(int i=l; i<=r; i++){
                type[i]=data;
            }
            data++;
            l=r+1;
        }
    }
    if(n%b!=0){
        for(int i=l; i<r; i++){
            type[i] = data;
        }
    }

    ///for(int i=0; i<n; i++){
    //    cout<<i<<"  --  "<<type[i]<<"\n";
    //}


    // for (r = 0; r < n; r++)
    // {
    //     if (r - l == b - 1)
    //     {
    //         blocks.insert({l, r});
    //         l = r + 1;
    //     }
    // }
    // if (n % b != 0)
    // {
    //     blocks.insert({l, r - 1});
    // }

    // while(right <= b){
    //     change = right - left;
    //     if(change == b -1){
    //         blocks.insert({left, right});
    //         left = right+1;
    //     }
    //     right++;
    // }
    // right--;
    // blocks.insert({left, right});

    // cout << "all blocks \n";
    // for (auto itr = blocks.begin(); itr != blocks.end(); itr++)
    // {
    //     auto cur = *itr;
    //     cout << cur[0] << " " << cur[1] << "\n";
    // }
    // cout << "\n";

    int pLeft = -1;
    int pRight = -1;
    int cnt = 0;
    int li = 0;
    int ri = b - 1;
    int sample=-1;
    for (int i = 0; i < m; i++)
    {
        int elm = access[i];
        int newSample = type[elm];
        if(newSample==sample){

        }else{
            cnt++;
            sample = newSample;
        }

        
    }
    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}