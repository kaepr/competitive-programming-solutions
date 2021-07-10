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

    string l1, l2, l3;
    getline(cin, l1);
    getline(cin, l2);
    getline(cin, l3);
    int s1 = 0, s2 = 0, s3 = 0;
    for (int i = 0; i < l1.length(); i++)
    {
        if (l1[i] == 'a' || l1[i] == 'e' || l1[i] == 'i' || l1[i] == 'o' || l1[i] == 'u')
        {
            s1++;
        }
    }

    for (int i = 0; i < l2.length(); i++)
    {
        if (l2[i] == 'a' || l2[i] == 'e' || l2[i] == 'i' || l2[i] == 'o' || l2[i] == 'u')
        {
            s2++;
        }
    }

    for (int i = 0; i < l3.length(); i++)
    {
        if (l3[i] == 'a' || l3[i] == 'e' || l3[i] == 'i' || l3[i] == 'o' || l3[i] == 'u')
        {
            s3++;
        }
    }

    if(s1==5 && s2==7 && s3 == 5)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}