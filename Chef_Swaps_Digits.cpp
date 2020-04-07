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
    int t;
    cin>>t;
    while(t>0){
        int A,B;
        cin>>A>>B;
        int Ac=A,Bc=B;
        int y = A%10;
        Ac=A/10;
        int x = Ac%10;

        int a = B%10;
        Bc=B/10;
        int b = Bc%10;

        int ans=A+B;

        if(A<10&&B<10){
            ans = A+B;
        }else if(A < 10 && B >= 10){
            ans = max(ans, y + a*10 +b);
            ans = max(ans, a + y*10 + b);
            ans = max(ans,b + a*10 + y);
        }else if(B<10 && A>= 10){
            ans = max(ans, b + x*10 +y);
            ans = max(ans, x + b*10 + y);
            ans = max(ans,y + x*10 + b);
        }else{
            ans = max(ans, a*10 + y + x*10 + b);
            ans = max(ans, b*10 + y + a*10 + x);
            ans = max(ans, x*10 + a + y*10 + b);
            ans = max(ans, x*10 + b + a*10 + y);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}