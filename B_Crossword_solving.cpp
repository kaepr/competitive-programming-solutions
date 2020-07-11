#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    int diff = 1e9;
    vector<int> newPos;
    for (int i = 0; i < m - n + 1; i++)
    {
        int ptr = i;
        vector<int> newPos2;
        for (int j = 0; j < n; j++)
        {

            if (s[j] != t[ptr])
            {
                newPos2.push_back(j + 1);
            }

            ptr++;
        }
        if (newPos2.size() < diff)
        {
            newPos.clear();
            for (int i = 0; i < newPos2.size(); i++)
            {
                newPos.push_back(newPos2[i]);
            }
            diff = newPos2.size();
        }
    }
    cout << newPos.size() << "\n";
    for (int i = 0; i < newPos.size(); i++)
    {
        cout << newPos[i] << " ";
    }
    return 0;
}