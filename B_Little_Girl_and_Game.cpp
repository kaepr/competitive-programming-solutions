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

    char ch[10001];
    int amt[30];
    int tot;
    int count_odd = 0;
    cin >> ch;
    int L = strlen(ch);
    for (int i = 0; i < L; i++)
    {
        amt[ch[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (amt[i] % 2 == 1)
            count_odd++;
    }
    if (count_odd == 0)
    {
        cout << "First\n";
    }
    else if (count_odd % 2 != 0)
    {
        cout << "First\n";
    }
    else
    {
        cout << "Second\n";
    }

    return 0;
}