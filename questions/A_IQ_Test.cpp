#include <bits/stdc++.h>
    #define int long long unsigned int
    #define ff first
    #define ss second
    #define pb push_back
    using namespace std; 
     
     
    signed main()
    {
     
    	#ifndef ONLINE_JUDGE
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
     
    	int t=1;
    	//cin>>t;
    	while(t--)
    	{
    		int n;
    		cin>>n;
 
    		int a[n];
    		for(int i=0;i<n;i++)
    			cin>>a[i];
    		sort(a,a+n);
    		int cnt=1,mx=0;
    		for(int i=1;i<n;i++)
    		{
    			if(a[i]==a[i-1])
    				cnt++;
    			else
    				cnt=1;
 
    			mx=max(cnt,mx);
    		}
    		if(mx > (n+1)/2)
    			cout<<"NO";
    		else
    			cout<<"YES";
    	}
    	return 0;
    }