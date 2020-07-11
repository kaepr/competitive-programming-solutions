#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int isPossibe(int arr[], int n)
{
    int pos = 1;
    if (arr[n - 1] == 0 || arr[0] == 0)
    {
        pos = 0;
        return pos;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 0 && arr[i + 1] == 0)
            pos = 0;
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int days = 0;
    int f = 1;
    while(f){
        if(isPossibe(a,n)){
            days++;
            for(int i=0; i<n; i++){
                a[i]--;
                if(a[i] < 0)
                    a[i] = 0;
            }
        }else{
            f=0;
        }
    }
    cout<<days<<"\n";
    return 0;
}