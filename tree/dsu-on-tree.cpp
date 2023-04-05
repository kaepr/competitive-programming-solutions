#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

#define fst first
#define snd second

/*

Find Summation of all nodes (min (abs(val[x] - val[y]))
x is all nodes from 1 .. n
y belongs to subtree(x)

basically for any node x
find the node which is closest in value inside its subtree

so it becomes a problem of 'querying on subtree'

disjoint set union
merge solutions of smaller subtrees
to get solution for parent
find the child which is the largest
and merge all the others into it

*/

void solve() {}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
}
