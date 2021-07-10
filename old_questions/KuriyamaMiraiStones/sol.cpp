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

void fillPrefixSum(int arr[], int n, int prefixSum[]) 
{ 
    prefixSum[1] = arr[1]; 
  
    // Adding present element  
    // with previous element 
    for (int i = 1; i < n; i++) 
        prefixSum[i] = prefixSum[i-1] + arr[i]; 
} 


int main(){
    int n;
    cin>>n;
    n=n+1;
    int arr[n],sum1[n],sum2[n];

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        
    }
    
    fillPrefixSum(arr,n,sum1);

    sort(arr,arr+n);
    fillPrefixSum(arr,n,sum2);

    int m;
    cin>>m;
    while(m>0){
        int l,r,t;
        cin>>t>>l>>r;
        int sum=0;
        if(t==1){  
            sum=sum1[r] - sum1[l-1];
        }else if(t==2){
            sum=sum2[r] - sum2[l-1];
        }
        cout<<sum<<"\n";
        m--;
    }

    return 0;
}