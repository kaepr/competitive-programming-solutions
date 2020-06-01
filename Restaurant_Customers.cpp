#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x, y, people = 0, curr_people = 0;
    cin >> n;
    vector<pair<int, bool>> arr;
    while (n--)
    {
        cin >> x >> y;
        arr.push_back(make_pair(x, true));
        arr.push_back(make_pair(y, false));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        curr_people += arr[i].second ? 1 : -1;
        people = max(people, curr_people);
    }
    cout << people;
    return 0;
}
// start <= i <= end
/*

2 3 5
4 8 9

*/