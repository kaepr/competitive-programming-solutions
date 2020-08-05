#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve()
{
    int n;
    cin >> n;

    int f = 0;

    vector<int> p;
    for (int i = 1; i <= n; i++)
    {
        if (isPrime(i))
            p.push_back(i);
    }
    set<int> np;
    for (int i = 0; i < min(10, (int)p.size()); i++)
    {
        for (int j = 0; j < min(10, (int) p.size()); j++)
        {
            if(i!=j){
                int x = p[i]*p[j];
                np.insert(x);
            }
        }
    }

    // for(auto x : np){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";

    vector<int> nps;
    for(auto x : np)
        nps.push_back(x);

    int a1, a2, a3, a4;
    
    for(int i=0; i<nps.size(); i++){
        for(int j=0; j<nps.size(); j++){
            for(int k=0; k<nps.size(); k++){
                if(i!=j && j!=k && k!=i){
                    int np1 = nps[i];
                    int np2 = nps[j];
                    int np3 = nps[k];
                    int n4;
                    n4 = n - (np1 + np2 + np3);
                    if (n4 <= 0 || n4 == np1 || n4 == np2 || n4 == np3 || np1 <= 0 || np2 <= 0 || np3 <= 0)
                    {
                        continue;
                    }
                    else
                    {
                        a1 = np1;
                        a2 = np2;
                        a3 = np3;
                        a4 = n4;
                        f = 1;
                        break;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < p.size() - 100; i++)
    // {
    //     cout << p[i] << " ";
    // }
    // cout << "\n";

    // int a1, a2, a3, a4;

    // for (int i = 0; i < p.size(); i++)
    // {
    //     if (f == 0)
    //     {
    //         for (int j = 0; j < p.size(); j++)
    //         {
    //             if (i != j || i != j + 1 || i != j + 2)
    //             {
    //                 int np1 = p[i] * p[j];
    //                 int np2 = p[i] * p[j + 1];
    //                 int np3 = p[i] * p[j + 2];
    //                 int n4;
    //                 n4 = n - (np1 + np2 + np3);
    //                 if (n4 <= 0 || n4 == np1 || n4 == np2 || n4 == np3 || np1 <= 0 || np2 <= 0 || np3 <= 0)
    //                 {
    //                     continue;
    //                 }
    //                 else
    //                 {
    //                     a1 = np1;
    //                     a2 = np2;
    //                     a3 = np3;
    //                     a4 = n4;
    //                     f = 1;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    // }

    

    if (f)
    {
        cout << "YES\n";
        cout << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    // freopen("filename.in","r",stdin);
    // freopen("filename.out","w",stdout);
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