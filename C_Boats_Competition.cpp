#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

typedef struct w
{
    int weight;
    int used;
} w;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int max_weight = a[n - 2] + a[n - 1];
    int elm = *min_element(a, a + n);
    // vector<int> b;
    // b.push_back(1);
    // cout<<b[0]<<"\n";

    int ans = 0;
    //vector<pair<int, int> b;
    for (int i = elm; i <= max_weight; i++)
    {
        w ws[n];
        for (int i = 0; i < n; i++)
        {
            ws[i].weight = a[i];
            ws[i].used = 0;
        }

        vector<int> pairs;
        for(int i=0; i<n; i++)
            pairs.push_back(a[i]);

        while()    
    
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int first = ws[j].weight;

            int l = j + 1;
            int r = n;
            int f = 0;
            while (r >= l)
            {
                int mid = l + (r - l) / 2;
                if (ws[mid].weight + ws[j].weight == i && ws[j].used == 0 && ws[mid].used == 0 && j != mid)
                {
                    f = 1;
                    ws[j].used = 1;
                    ws[mid].used = 1;
                }
                else if (ws[mid].weight + ws[j].weight > i)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }

            if (f)
                cnt++;

            // for (int k = 0; k < n; k++)
            // {
            //     if (ws[k].weight + ws[j].weight == i && ws[j].used == 0 && ws[k].used == 0 && j != k)
            //     {
            //         ws[k].used = 1;
            //         ws[j].used = 1;
            //         cnt++;
            //     }
            // }
        }
        ans = max(ans, cnt);
        //b.clear();
    }
    cout << ans << "\n";
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