#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int sum = 0;
        int len = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s = s + a[i];
            if (s % x != 0)
            {
                //cout<<"not divisble sum is "<<s<<"\n";
                len = max(len, i + 1);
            }
        }

        s = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            s = s + a[i];
            if (s % x != 0)
            {
                //cout<<"not divisble sum is "<<s<<"\n";
                len = max(len, n - i);
            }
        }

        if (len > 0)
        {
            cout << len << "\n";
        }
        else if (len == 0)
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}

/*
m = max(m,s);
        
            if (m % x != 0)
            {
                flag = 1;
                //printf("max till here is %d\n", m);
                //printf(" left = %d, right is %d\n", start, end);
                
            }

if ((s + a[i]) >= s)
            {
                s = s + a[i];
                cout<<" 1st s is  this here "<<s<<"\n";
                if (s % x != 0)
                    end = i;
            }
            else if (a[i] > s)
            {
                s = a[i];
                cout<<"2n s is  this here "<<s<<"\n";
                if (s % x != 0)
                {
                    start = i;
                    end = i;
                }
            }
            cout<<"ran\n";


int max_len = 0;
        int s = 0;
        int m = -20000000;
        int start = 0, end = 0;
        int flag = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if ((s + a[i]) % x != 0)
            {
                s = s + a[i];
                end = i;
            }
            else if (a[i] % x != 0)
            {
                s = a[i];
                start = i;
                end = i;
            }
            else
            {
                //start++;
            }

            m = max(m, s);
            if (m % x != 0)
            {
                flag = 1;
                //printf("max till here is %d\n", m);
                //printf(" left = %d, right is %d\n", start, end);
                ans = max(ans, end - start + 1);
            }

            //if (m % x != 0)
        }

        if (flag)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }int b

*/