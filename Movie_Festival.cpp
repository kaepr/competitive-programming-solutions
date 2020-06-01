#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n, x, y, maxMovies = 0, currMovies = 0;
    cin >> n;
    vector<pair<int, int>> arr;
    while (n--)
    {
        cin >> x >> y;
        arr.push_back(make_pair(x, y));
    }

    sort(arr.begin(), arr.end(), compare);
    int movStart = arr[0].first;
    int movEnd = arr[0].second;
    maxMovies = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i].first >= movEnd)
        {
            maxMovies++;
            movStart = arr[i].first;
            movEnd = arr[i].second;
        }
    }
    cout << maxMovies;

    return 0;
}
