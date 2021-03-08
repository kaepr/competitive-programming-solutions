#include <bits/stdc++.h>
using namespace std;

void add(int &subset, int x)
{
    subset = (subset ^ (1 << (x - 1)));
}

void remove(int &subset, int x)
{
    subset = (subset ^ (1 << (x - 1)));
}

void display(int subset)
{
    for (int bit_no = 0; bit_no <= 9; bit_no++)
    {
        if (subset & (1 << bit_no))
        {
            cout << bit_no + 1 << " ";
        }
    }
    cout << "\n";
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int set = 15;
    display(set);
    remove(set, 1);
    display(set);
    add(set, 1);
    display(set);

    return 0;
}