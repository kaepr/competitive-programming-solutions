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

    int n, k;
    cin >> k;
    scanf("%d", &k);
    if (k > 36)
        printf("%d\n", -1);
    else
    {
        while (k > 0)
        {
            if (k >= 2)
            {
                printf("%d", 8);
                k -= 2;
            }
            else
            {
                printf("%d", 9);
                k -= 1;
            }
        }
        printf("\n");
    }

    return 0;
}