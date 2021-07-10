#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = st.upper_bound(x);
        if (it != st.end())
        {
            //cout << "element erased is " << *it << "\n";
            st.erase(it);
        }

        //cout << "element added is " << x << "\n";
        st.insert(x);
    }
    cout << st.size();

    return 0;
}