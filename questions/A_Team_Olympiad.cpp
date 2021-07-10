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
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<n+1; i++)
        cin>>a[i];

    int t1=0;
    int t2=0;
    int t3=0;

    for(int i=1; i<n+1; i++){
        if(a[i]==1){
            t1++;
        }else if(a[i]==2){
            t2++;
        }else if(a[i]==3){
            t3++;
        }
    }
    int total = min(t1,t2);
    total = min(total,t3);

    cout<<total<<"\n";

    int t1count=1;
    int t2count=1;
    int t3count=1;

    for(int i=0; i<total; i++){
        for(int j=t1count; j<n+1; j++){
            if(a[j]==1){
                cout<<j<<" ";
                t1count=j+1;
                break;
            }
        }

        for(int j=t2count; j<n+1; j++){
            if(a[j]==2){
                cout<<j<<" ";
                t2count=j+1;
                break;
            }
        }

        for(int j=t3count; j<n+1; j++){
            if(a[j]==3){
                cout<<j<<"\n";
                t3count=j+1;
                break;
            }
        }
    }
    
    return 0;
}