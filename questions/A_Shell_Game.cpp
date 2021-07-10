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

    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

    int ball_ind;
    cin >> ball_ind;
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        if (ball_ind == a)
            ball_ind = b;
        else if (ball_ind == b)
            ball_ind = a;
    }
    cout << ball_ind << "\n";
    return 0;
}