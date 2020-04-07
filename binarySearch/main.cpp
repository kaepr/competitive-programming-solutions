#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=9, val=5;
    int array[] = {2,3,5,6,7,8,10,12,15};
    int low=0, high=n, mid=0;
    while(low < high){
        mid = (low + high)/2;
        if(array[mid] < val)
            low = mid + 1;
        else
            high = mid;
    }
    cout << "Value " << val << "found at index " << high << endl;
    return 0;
}