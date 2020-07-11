#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}



void solve()
{
    int n;
    cin >> n;

    // for (int i = 1; i <= n / 2; i++)
    // {
    //     int j = n - i;
    //     cout << "i : " << i << ", j : " << j << ", lcm is : " << lcm(j, i) << ",\n";
    // }

    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << "\n";
    }
    else
    {
        vector<int> divs;
        for(int i=1; i<=sqrt(n); i++){
            if(n%i==0){
                if(n/i==i)
                    divs.push_back(i);
                else{
                    divs.push_back(i);
                    divs.push_back(n/i);
                }
            }
        }

        int a=0,b=0;
        int ans = 1e9;
        for(int x : divs){
            int t1=x,t2 = n-x;
            if(t2 >= t1){
                int l2 = lcm(t2,t1);
                if(l2 <= ans){
                    ans = l2;
                    a = t1;
                    b = t2;
                }
            }
        }
        cout<<a<<" "<<b<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

/*

if (isPrime(n))
        {
            cout << "1 " << n - 1 << "\n";
        }
        else
        {
            int ans = 1e9;
            int a = 1e9, b = 1e9;
            for (int i = 1; i <= n / 2; i++)
            {
                int j = n - i;
                int temp = lcm(j, i);
                if (temp <= ans)
                {
                    ans = temp;
                    a = i;
                    b = j;
                }
            }
            cout << a << " " << b << "\n";
        }

*/