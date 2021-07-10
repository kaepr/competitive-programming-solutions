#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    int arr[4];
    for(int i=0; i<4; i++)
        cin>>arr[i];


    int cnt = 0;
    

    while(cnt < 4){
        int no=0,ne=0;
        for(int i=0; i<4; i++)
            if(arr[i]%2==0)
                ne++;
            else
                no++;
        
        if(ne==4 || (no==1 && ne==3)){
            cout<<"Yes\n";
            return;
        }else{
            int f = 1;
            for(int i=0; i<3; i++){
                if(arr[i] - 1 >= 0){
                    arr[i] = arr[i] - 1;
                }else{
                    f=0;
                }
            }
            if(f){
                arr[3] = arr[3] + 3;
            }else{
                cout<<"No\n";
                return;
            }
        }
        cnt++; 
    }
    cout<<"No\n";
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        testCase();
        t--;
    }

    return 0;
}