#include<bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q,k;
    cin>>n>>q>>k;
    int x=ceil(sqrt(n));        //number of elements per block
    int num=ceil(n/double(x));    //number of blocks
    int arr[n],brr[n];
    int upd[num][k];            //hashing in every block
    int p[num]={0};                //pointer in every block which points to the number corresponding to 0
    fl(i,0,num)
    {
        fl(j,0,k)
        {
            upd[i][j]=0;
        }
    }
    fl(i,0,n)
    {
        cin>>arr[i];
        arr[i]%=k;
        upd[i/x][(arr[i]+k)%k]++;
        brr[i]=arr[i];
    }
    while(q--)
    {
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1)
        {
            int b=l/x;
            int i=l;
            int cnt=0;
            while(i/x==b && i<=r)
            {
                if(arr[i]%k==p[b])
                {
                    cnt++;
                }
                i++;
            }
            b++;
            while(b<r/x)
            {
                cnt+=upd[b][p[b]];
                b++;
            }
        
            i=b*x;
            while(i<=r)
            {
                if(arr[i]%k==p[b])
                {
                    cnt++;
                }
                i++;
            }
            cout<<cnt<<endl;
        }
        else
        {
            int val;
            cin>>val;
            val=(val%k+k)%k;
            int b=l/x;
            int i=l;
            int cnt=0;
            while(i/x==b && i<=r)
            {
                upd[b][arr[i]]--;
                arr[i]=(arr[i]+val)%k;
                arr[i]=(arr[i]+k)%k;
                upd[b][arr[i]]++;
                i++;
            }
            b++;
            while(b<r/x)
            {
                p[b]=(p[b]-val)%k;
                p[b]=(p[b]+k)%k;
                b++;
            }
            i=b*x;
            while(i<=r)
            {
                upd[b][arr[i]]--;
                arr[i]=(arr[i]+val)%k;
                arr[i]=(arr[i]+k)%k;
                upd[b][arr[i]]++;
                i++;
            }
        }
    }
}