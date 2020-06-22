#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int move = 1;
    /*
    
    if move is odd, ashish turns, cannot play then loses
    if move is even, fastesat finger turns, cannot play then loses

    */

    int flag = 1;

    while (flag)
    {
        if (n == 1)
        {
            flag = 0;
        }
        else
        {
            if (n % 2 != 0)
            {
                n /= n;
                move++;
            }
            else if (n % 2 == 0)
            {
                int min_odd_divisor = INT_MAX;
                int smallest_4_multiple = INT_MAX;
                for (int i = 2; i <= sqrt(n); i++)
                {
                    if (n % i == 0)
                    {
                        if (i % 2 != 0)
                        {
                            min_odd_divisor = min(min_odd_divisor, i);
                            if (n / i % 4 == 0)
                            {
                                smallest_4_multiple = min(smallest_4_multiple, n / i);
                            }
                        }

                        int other = n / i;
                        if ((n / i) % 2 != 0)
                        {
                            min_odd_divisor = min(min_odd_divisor, n / i);
                            int num = n / (n / i);
                            if (num % 4 == 0)
                            {
                                smallest_4_multiple = min(smallest_4_multiple, num);
                            }
                        }
                    }
                }

                if (smallest_4_multiple > 1 && smallest_4_multiple < n)
                {
                    n = smallest_4_multiple;
                    //cout<<"new n is "<<n<<"\n";
                    move++;
                }
                else if (min_odd_divisor > 1 && min_odd_divisor < n)
                {
                    //cout << "min odd divisor was " << min_odd_divisor << "\n";
                    n = n / min_odd_divisor;
                    move++;
                }
                else
                {
                    n--;
                    move++;
                }
                //cout<<"new n is "<<n<<"\n";
            }
        }
    }

    if (move % 2 != 0)
    {
        cout << "FastestFinger\n";
    }
    else
    {
        cout << "Ashishgup\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}