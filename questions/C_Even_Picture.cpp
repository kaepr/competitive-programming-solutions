#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    int x = 1000000;
    int y = 1000000;

    vector<pair<int, int>> points;
    points.push_back({x, y});
    points.push_back({x + 1, y});
    points.push_back({x, y - 1});
    points.push_back({x + 1, y - 1});
    x++;
    y--;

    while (k--)
    {
        points.push_back({x + 1, y});
        points.push_back({x, y - 1});
        points.push_back({x + 1, y - 1});
        x++;
        y--;
    }

    cout<<points.size()<<"\n";
    for(int i=0; i<points.size(); i++){
        cout<<points[i].first<<" "<<points[i].second<<"\n";
    }

    return 0;
}