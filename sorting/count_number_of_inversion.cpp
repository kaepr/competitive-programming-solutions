#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;

int count_inv = 0;

vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> res;
    int i = 0, j = 0;

    while (i < left.size() and j < right.size()) {
        if (left[i] <= right[j]) {
            res.push_back(left[i]);
            i++;
        } else {
            res.push_back(right[j]);
            j++;
            count_inv += left.size() - i;
        }
    }

    while (i < left.size()) {
        res.push_back(left[i]);
        i++;
    }

    while (j < right.size()) {
        res.push_back(right[j]);
        j++;
    }

    return res;
}

vector<int> merge_sort(vector<int> arr) {
    int n = arr.size();
    if (n <= 1) {
        return arr;
    }

    int half = n / 2;
    vector<int> left(arr.begin(), arr.begin() + half);
    vector<int> right(arr.begin() + half, arr.end());

    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
}

void solve() {
    vector<int> v{1, 2, 5, 4};

    merge_sort(v);
    cout << count_inv << "\n";
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
