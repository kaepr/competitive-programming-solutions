#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int getClosest(int val1, int val2, int target)
{
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

int findClosest(int arr[], int n, int target)
{
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];

    int i = 0, j = n, mid = 0;
    while (i < j)
    {
        mid = (i + j) / 2;
        if (arr[mid] == target)
            return arr[mid];

        if (target < arr[mid])
        {
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1], arr[mid], target);

            j = mid;
        }
        else
        {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid], arr[mid + 1], target);

            i = mid + 1;
        }
    }
    return arr[mid];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
 
    int s[n+1];
    s[0] = 0;
    for(int i=1; i<=n; i++){
        int c,t;
        cin>>c>>t;
        s[i] = s[i-1] + c*t;
    }
    int song = 1;
    while(m--){
        int v;
        cin>>v;
        while(v > s[song]){
            song+=1;
        }
        cout<<song<<"\n";
    }

    return 0;
}