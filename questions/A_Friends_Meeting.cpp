#include <bits/stdc++.h>
#define MOD 1000000007
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void solve(){
    int a,b;
    cin>>a>>b;
    int diff = abs(a-b);
    int ans = 0;
    int cnt=1;
    int times=0;
    for(int i=1; i<=diff; i++){
        if(times==2){
            times = 0;
            cnt++;
        }
        ans+=cnt;
        times++;
    }
    cout << ans;
}

int main(){
  FAST
  int t=1;
  //cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
