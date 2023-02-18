#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

ll powmod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

const ll MOD = 1e9 + 7;

// print occurences of a small pattern
// inside a bigger string
//
//  kmp[i] = s[0...i] length of longest suffix
//  that is also a prefix
//
//  kmp array values only ever increase by 1 ( if its increasing )
//  kmp[i+1] <= kmp[i] + 1
//
vector<int> calc_kmp(string s) {
    // treat string as 0 indexed
    int n = s.length();

    // treat kmp as 1 indexed
    vector<int> kmp(n + 1);

    int i = 0, jump = -1;
    kmp[0] = -1;

    while (i < n) {
        while (jump != -1 and s[i] != s[jump]) {
            jump = kmp[jump];
        }
        jump++;
        i++;
        kmp[i] = jump;
    }

    return kmp;
}

// pattern match
// P = "aba", T = "aabababa"
// find all occurences of P in T in linear time
//
// create a new string S = P#T
// and then directly apply KMP
//
//
// minimum number of characters to make palindrome
//
// S = "asdascxxc"
// T = rev(S)#S
// apply KMP, at last position, we get the value
// which tells us which largest suffix is equal to largest prefix
// ( and bcoz the way we constructed string T, we get the largest palindrome
// ending at the last position)
// just subtract from total to get minimum characters required to make
// entire palindrome
//
// period of a string
// smallest monomer that can be concatenated 'n' no. of times
//
// extendible period
// again use monomers, but allowed to cut some extra part at the end
//
// find the smallest period
// extendible period -> |S| - kmp(|S|)

/*
Period Code
   if( N % ( N - kmp[N]) == 0) {
        cout<<N - kmp[N]
   } else  {
        N
   }
*/

/*
    Manacher Algorithm
    Uses palindrome center
 
    finds out maximum length palindrome at each center
    adds # in b/w characters
 
 
    helps find longest palindrome string
    helps find # of palindromic substrings

*/

void solve() {
    string s;
    cin >> s;
    auto v = calc_kmp(s);

    for (auto x : v) {
        cout << x << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
