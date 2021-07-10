#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    char S[1100];
    for (int i = 0; i < n; i++)
    {
        cin >> S;
        for (int j = 0; j < m; j++)
        {
            if (S[j] == '.')
            {
                if ((i + j) & 1)
                    S[j] = 'W';
                else
                {
                    S[j] = 'B';
                }
            }
        }
        printf("%s\n", S);
    }

    return 0;
}