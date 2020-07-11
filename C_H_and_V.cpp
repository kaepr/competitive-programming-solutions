#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int black_sqaures(int *arr, int h, int w)
{

    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (arr[i][j] == 1)
                ans++;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w, k;
    cin >> h >> w >> k;
    int arr[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                arr[i][j] = 0;
            else
                arr[i][j] = 1;
        }
    }

    int arr_copy1[h][w];



    return 0;
}