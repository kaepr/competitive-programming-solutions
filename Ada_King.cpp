#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
0 - .
1 - O
2 - X
*/

void solve()
{
    int k;
    cin >> k;
    int obs = 64 - k;
    int col = 0, row = 0;
    int board[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = 3;
        }
    }
    board[0][0] = 0;
    for (int i = 0; i < 8; i++)
    {
        int till;
        if (k >= 8)
        {
            till = 8;
            k = k - 8;
        }
        else
        {
            till = k;
            k = 0;
        }
        for (int j = 0; j < till; j++)
        {
            if (board[i][j] != 0)
            {
                board[i][j] = 1;
            }
        }
    }

    int ptr1 = 100, ptr2 = 100;
    int flag = 1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (flag)
            {
                if (board[i][j] == 3)
                {
                    ptr1 = i, ptr2 = j;
                    flag = 0;
                }
            }
        }
    }

    for(int j = ptr2; j<8; j++)
        board[ptr1][j] = 2;
    
    if (ptr1 != 100 && ptr2 != 100)
    {
        for (int i = ptr1+1; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = 2;
            }
        }
    }

    //print board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 0)
            {
                cout << "O";
            }
            else if (board[i][j] == 1)
            {
                cout << ".";
            }
            else if (board[i][j] == 2)
            {
                cout << "X";
            }
        }
        cout << "\n";
    }
    cout<<"\n";
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