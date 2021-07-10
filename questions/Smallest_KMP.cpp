#include <bits/stdc++.h>
using namespace std;

void testCase()
{
    map<char, int> mp;
    string s, pattern;
    cin >> s >> pattern;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < pattern.size(); i++)
    {
        mp[pattern[i]]--;
    }
    string s1 = "";
    string s2 = "";
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        for (int j = 0; j < it->second; j++)
        {
            s1.push_back(it->first);
            s2.push_back(it->first);
        }
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int flag = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] > pattern[0])
        {
            s1.insert(i, pattern);
            flag = 1;
            break;
        }

        if (flag == 1)
            break;
    }
    int flag2 = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] >= pattern[0])
        {
            s2.insert(i, pattern);
            flag2 = 1;
            break;
        }

        if (flag2 == 1)
            break;
    }
    if (flag == 0)
    {
        s1.append(pattern);
    }
    if (flag2 == 0)
    {
        s2.append(pattern);
    }
    cout << min(s1, s2) << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        testCase();
        t--;
    }
    return 0;
}
