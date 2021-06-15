#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const int MOD = 1e9 + 7;


void solve()
{
    int n,m;
    cin>>n>>m;
    char grid[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    char grid1[n][m];
    char grid2[n][m];

    char R = 'R';
    char W = 'W';
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i+j)%2==0){
                grid1[i][j] = 'R';
            }else{
                grid1[i][j] = 'W';
            }
        }
    }

     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i+j)%2==0){
                grid2[i][j] = 'W';
            }else{
                grid2[i][j] = 'R';
            }
        }
    }

    bool f1 = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='.'){
                // grid[i][j] = grid1[i][j];
            }else{
                if(grid[i][j]!=grid1[i][j]){
                    f1 = false;
                    break;
                }
            }
        }
    }

    if(f1){
        cout<<"YES\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<grid1[i][j];
            }
         cout<<"\n";
        }
     return;
    }

    bool f2 = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='.'){

            }else{
                if(grid[i][j]!=grid2[i][j]){
                    f2 = false;
                    break;
                }
            }
        }
    }

    if(f2){
        cout<<"YES\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<grid2[i][j];
            }
         cout<<"\n";
        }
     return;
    }
    
    cout<<"NO\n";
   




}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
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