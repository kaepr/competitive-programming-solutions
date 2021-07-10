#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> q;
    int t;
    cin >> t;
    int f = 1;
    while (t--)
    {
        string s;
        cin >> s;
        //cout<<"s is "<<s<<"\n";
        if (s == "toFront")
        {
            int x;
            cin >> x;
            if (f)
            {
                q.push_front(x);
            }
            else
            {
                q.push_back(x);
            }
        }
        else if (s == "front")
        {
            if (q.size() == 0)
            {
                cout << "No job for Ada?\n";
            }
            else if (f)
            {
                cout << q.front() << "\n";
                q.pop_front();
            }
            else
            {
                cout << q.back() << "\n";
                q.pop_back();
            }
        }
        else if (s == "back")
        {
            if (q.size() == 0)
            {
                cout << "No job for Ada?\n";
            }
            else if (f)
            {
                cout << q.back() << "\n";
                q.pop_back();
            }
            else
            {
                cout << q.front() << "\n";
                q.pop_front();
            }
        }
        else if (s == "push_back")
        {
            if (f)
            {
                int x;
                cin >> x;
                q.push_back(x);
            }
            else
            {
                int x;
                cin >> x;
                q.push_front(x);
            }
        }
        else if (s == "reverse")
        {
            if(f){
                f=0;
            }else
            {
                f=1;
            }
            
        }
    }

    return 0;
}