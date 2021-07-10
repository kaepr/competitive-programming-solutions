#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_queue(T q)
{
    while (!q.empty())
    {
        cout << q.top() << ' ';
        q.pop();
    }
    cout << "\n";
}

int main()
{
    priority_queue<int> q;
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    for (int n : data)
    {
        q.push(n);
    }
    print_queue(q);

    priority_queue<int, vector<int>, greater<int>> q2(data.begin(), data.end());

    print_queue(q2);

    auto cmp = [](int left, int right) {
        return (left ^ 1) < (right ^ 1);
    };

    priority_queue<int, vector<int>, decltype(cmp)>
        q3(cmp);

    for (int n : data)
    {
        q3.push(n);
    }
    print_queue(q3);

    return 0;
}