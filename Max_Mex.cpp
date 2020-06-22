#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int findMax(set<int> my_set) 
{ 
  
    // Get the maximum element 
    int max_element; 
    if (!my_set.empty()) 
        max_element = *(my_set.rbegin()); 
  
    // return the maximum element 
    return max_element; 
} 

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int curr_len=0;
    //checking if exists or not
    int l=INT_MAX;
    int r=-1;
    int m_exists=0;
    int min_range=INT_MAX;
    int max_range=-1;
    set<int> lengths;
    lengths.insert(0);
    for(int i=0; i<n; i++){
        if(a[i]!=m){
            curr_len++;
            l = min(l,i);
            r = max(r,i);
            min_range = min(min_range, a[l]);
            max_range = max(max_range, a[r]);
            if( m > min_range && m < max_range){
                lengths.insert(r - l +1);
            }
        }else if(a[i]==m){
            curr_len=0;
            l = INT_MAX;
            r = -1;
            min_range = INT_MAX;
            max_range = -1;
        }
    }
    int size = findMax(lengths);
    if(size == 0){
        cout<<-1<<"\n";
    }else{
        cout<<size<<"\n";
    }

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