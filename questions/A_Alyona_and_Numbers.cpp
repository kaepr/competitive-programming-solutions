#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    ll n,m;
    cin>>n>>m;
    
    ll one=0,two=0,three=0,four=0,zero=0;
    for(ll i=1; i<=m; i++){
        if(i%5==0)
            zero++; 
        else if(i%5==1)
            one++;
        else if(i%5==2)
            two++;
        else if(i%5==3)
            three++;
        else if(i%5==4)
            four++;
        

    }

    ll ans =0;
    
    for(ll i=1; i<=n; i++){
        if(i%5==0)
            ans=ans+zero;
        else if(i%5==1)
            ans=ans+four;
        else if(i%5==2)
            ans=ans+three;
        else if(i%5==3)
            ans=ans+two;
        else if(i%5==4)
            ans=ans+one;
    }

    cout<<ans;
    return 0;
}