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

struct time{
    int a,b;
};

bool visited[1005];

int main(){
    pair<int,int> t[55],t1[55];
    int p,q,l,r,nb=0,a,b,i,k,s,j;
    cin>>p>>q>>l>>r;
    for(i=0; i<p; i++){
        cin>>a>>b;
        t[i].F=a;
        t[i].S = b;
    }

    for(i=0; i<q; i++){
        cin>>a>>b;
        t1[i].F = a;
        t1[i].S = b;
    }

    for(i=0; i<q; i++){
        for(j=0; j<p; j++){
            for(k=l; k<=r; k++){
                for(s=t1[i].F; s<=t1[i].S; s++){
                    if(s+k>=t[j].F && s+k<=t[j].S && !visited[k]){
                        nb++;
                        visited[k] = 1;
                    }
                }
            }
        }
    }
    cout<<nb<<"\n";


    return 0;
}