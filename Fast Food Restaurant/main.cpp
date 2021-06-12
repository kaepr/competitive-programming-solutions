#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

int main(){

    vector<int> v = {6,5,3,2,1};

    int x;
    cout<<"Enter variable x = "<<"\n";
    cin>>x;

    cout<<"You entered x = "<<x<<"\n";


    print(v);

    sort(v.begin(), v.end());

    print(v);

    sort(v.begin(), v.end(), [](int x, int y){
        return x>y;
    });

    print(v);
    

    return 0;
}