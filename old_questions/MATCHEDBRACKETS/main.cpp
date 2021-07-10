#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0; i<n; i++){
        cin >> a[i];
    }
    int t,curr=0,s=1,mcurr=0,len=0,mlen=0,mpos=0,mlpos=0;
    for(long long i=0; i<n; i++){
        t = a[i];
        if(t==1){
            curr++;
            len++;
            if(curr>mcurr){
                mcurr = curr;
                mpos = i+2;
            }

            if(t==2){
                curr--;
                len=1;
                if(curr==0){
                    if(len > mlen){
                        mlen = len;
                        len=0;
                        s=i+2;
                    }else if(len < mlen){
                        len=0;
                        s=i+2;
                    }
                }
            }

        }
    }
    return 0;
}