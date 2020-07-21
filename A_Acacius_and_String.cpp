#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

//abacaba

void solve()
{
    string t = "abacaba";
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = 0;
    int occur = 0;
    for (int i = 0; i < n - 6; i++)
    {
        //cout<<"the stirn is "<<s<<"\n";
        f = 1;
        //int possible = 1;
        for (int j = 0; j < 7; j++)
        {
            if(s[i+j] != t[j]){
                if(s[i+j]=='?'){
                    //cout<<s[i+j]<<" is str and t is "<<t[j]<<"\n";
                    f=0;
                    break;
                }
            }
        }

        if (f == 0)
            continue;

        //<<"substring exists from "<<i<<"\n";
        //cout<<s<<"\n";

        int ptr = 0;
        for (int j = i; j < i + 7; j++)
        {
            if (s[j] != t[ptr])
            {
                if (s[j] == '?')
                {
                    if (ptr == 0)
                        s[j] = 'a';
                    if (ptr == 1)
                        s[j] = 'b';
                    if (ptr == 2)
                        s[j] = 'a';
                    if (ptr == 3)
                        s[j] = 'c';
                    if (ptr == 4)
                        s[j] = 'a';
                    if (ptr == 5)
                        s[j] = 'b';
                    if (ptr == 6)
                        s[j] = 'a';
                }
            }
            ptr++;
        }

        //counting occurences
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '?')
                s[j] = 'd';
        }

        int times = 0;

        for (int j = 0; j < n - 6; j++)
        {
            int ptr = j;
            int same = 1;
            for (int k = 0; k < 7; k++)
            {
                if (s[ptr] != t[k])
                    same = 0;
                ptr++;
            }
            if (same)
                times++;
        }
        if (times == 1)
        {
            f = 1;
            cout << "Yes\n";
            cout << s << "\n";
            break;
        }
        else
        {
            f = 0;
        }
    }
    if (f == 0)
    {
        cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}