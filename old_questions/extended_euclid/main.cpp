#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b > a)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        cout << "GCD is " << a << "\n";
        return a;
    }
    cout << "New values are a : " << b << " b : " << a % b << "\n";
    return gcd(b, a % b);
}

int main()
{
    int a = 198, b = 243;
    int val = gcd(a, b);

    

    return 0;
}