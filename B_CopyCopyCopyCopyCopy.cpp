#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int lis(int arr[], int n){
    int lis[n];
    lis[0]=1;
    for(int i=1; i<n; i++){
        lis[i]=1;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j]+1;
        }
    }
    return *max_element(lis, lis+n);
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    cout<<st.size()<<"\n";
    

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }   
    return 0;
}


/*\

3 1 4 1 5 9

3 1 4 1 5 9 3 1 4 1 5 9

*/