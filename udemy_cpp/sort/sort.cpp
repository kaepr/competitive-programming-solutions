#include <bits/stdc++.h>
using namespace std;

bool cmp(int X, int Y){
    return X > Y; // descending order
}

int main(){
    int A[] = {1, 4, 2, 0, 5, 10, 9};

    sort(A+0, A+7);
    for(int i=0; i<=6; ++i){
        cout<<A[i]<<" ";
    }

    sort(A+0, A+7, cmp);
    for(int i=0; i<=6; ++i){
        cout<<A[i]<<" ";
    }

    return 0;
}