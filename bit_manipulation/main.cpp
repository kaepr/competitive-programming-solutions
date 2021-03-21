#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

const int MOD = 1e9 + 7;

#define PB push_back
#define F first
#define S second
#define MP make_pair

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

int powmod(int x, int y, int mod)
{
    int res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

/*

Left Shift ( << )
It shifts some number of bits in the given pattern to the left and append 0 at the end.
It is equivalent to multiplying the number/bit pattern with 2^k

1 << 1 = 1 * (2^1) = 1 * 2 = 2
1 << 2 = 1 * (2^2)
2 << 2 = 2*(2^2)
1 << n = 2^n = 1 * (2*2*2 ... n times)


Right Shift ( >> )
It shifts some number of bits in the given bit pattern to the right and appends 1 at the end. Right shift is equivalent to dividing the bit pattern with 2k.

4 >> 1 = 4 / 2 = 2
16 >> 4 = 16 / (2*4) = 2

*/

/*

Check if given number is power of 2
Consider any number x.
Now consider x - 1, in the binary representation of x - 1, all the bits will be same as x except for the rightmost 1 in x, and all the bits to the right of the righmost 1.

Eg = 1010 = 10
10 - 1 = 9 = 1001

Thus binary representation of x - 1 can be obtained by simply flipping all the bits to the right of rightmost 1 in x, and also including the rightmost 1.

Now the number x & (x - 1) will have all bits equal to the x except for the rightmsot 1 in x.

1010
1001

1000
If the number was a power of two, ( which is of the form 1000...000 ), as the rightmost bit is the first one, thus everything is flipped, and so after and we should get 0. For numbers which are not powers of two, they can never have 0 as there always exist another 1 left to the rightmost 1. ( which would be flipped ).

Below code also checks for the case that x may be zero
*/

bool isPowerOfTwo(int x)
{
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}

/*

Count the number of ones in the binary representation of the given number.
As explained in the previous algorithm, the relationship between the bits of x and x-1. So as in x-1, the rightmost 1 and bits right to it are flipped, then by performing x&(x-1), and storing it in x, will reduce x to a number containing number of ones(in its binary form) less than the previous state of x, thus increasing the value of count in each iteration.

Basically it removes the rightmost 1 bit in every iteration.

Example:
n = 23 = {10111}2 .
1. Initially, count = 0.
2. Now, n will change to n&(n-1). As n-1 = 22 = {10110}2 , then n&(n-1) will be {101112 & {10110}2, which will be {10110}2 which is equal to 22. Therefore n will change to 22 and count to 1.
3. As n-1 = 21 = {10101}2 , then n&(n-1) will be {10110}2 & {10101}2, which will be {10100}2 which is equal to 20. Therefore n will change to 20 and count to 2.
4. As n-1 = 19 = {10011}2 , then n&(n-1) will be {10100}2 & {10011}2, which will be {10000}2 which is equal to 16. Therefore n will change to 16 and count to 3.
5. As n-1 = 15 = {01111}2 , then n&(n-1) will be {10000}2 & {01111}2, which will be {00000}2 which is equal to 0. Therefore n will change to 0 and count to 4.
6. As n = 0, the the loop will terminate and gives the result as 4.

*/

int count_one(int n)
{
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

/*

Check if the i'th bit is set in the binary form of the given number.
Self explanatory

*/

bool check(int N)
{
    if (N & (1 << i))
        return true;
    else
        return false;
}

/*

Generating all subsets

*/

void possibleSubsets(char A[], int N)
{
    for (int i = 0; i < (1 << N); ++i)
    {
        for (int j = 0; j < N; ++j)
            if (i & (1 << j))
                cout << A[j] << ‘ ‘;
        cout << endl;
    }
}

long largest_power(long N)
{
    //changing all right side bits to 1.
    N = N | (N >> 1);
    N = N | (N >> 2);
    N = N | (N >> 4);
    N = N | (N >> 8);

    //as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by
    2. return (N + 1) >> 1;
}

void solve()
{
    ll x = 124;

    //returns the rightmost 1 in binary representation of x
    ll a = x ^ (x & (x - 1));

    //returns rightmost 1 in binary representation of x
    a = x & (~x);

    //returns the number x with the n'th bit set
    a = x | (1 << n);
}

int main()
{
    // freopen("filename_input.txt","r",stdin);
    // freopen("filename_output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}