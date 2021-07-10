#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Point{
    long long int x, y;
};

 int comparator(const void *p, const void *q)  
{ 
    int l = ((struct Point *)p)->y; 
    int r = ((struct Point *)q)->y;  
    return (r - l); 
} 

int main(){
    long long int n,z,w,sum=0,i,p;
    scanf("%lld%lld%lld",&n,&z,&w);
    struct Point d[n];
    long long int a[n],b[n];
    for(i=0;i<n;i++){
        scanf("%lld", &a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%lld", &b[i]);
        d[i].x=i;
        d[i].y=abs(b[i]-a[i]);
    }
    
    qsort((void*)d, n, sizeof(d[0]), comparator);
    for(i=0;i<n;i++)
    {
        p=d[i].x;
        if(a[p]>=b[p] && z!=0)
        {
            sum=sum+a[p];
            z--;
        }
        else 
        {
            sum=sum+b[p];
            w--;
        }
    }
    printf("%lld\n",sum);
	return 0;
}