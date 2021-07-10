#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
    int lastTime[2001][2001];
    for (int i = 0; i < 2001; i++)
        for (int j = 0; j < 2001; j++)
            lastTime[i][j] = -1;

    int currX = 1000, currY = 1000;
    lastTime[currX][currY] = 0;
    int currentTime = 0;
    int answer = 1001;
    int n;
    cin >> n;
    // cout<<n<<"\n";
    for (int i = 0; i < n; i++)
    {
        char c;
        int x;
        cin >> c >> x;
        // cout<<c<<" "<<x<<"\n";
        int dirX = 0, dirY = 0;

        if (c == 'N')
            dirX = -1;
        else if (c == 'S')
            dirX = 1;
        else if (c == 'W')
            dirY = -1;
        else if (c == 'E')
            dirY = 1;

        for (int j = 1; j <= x; j++)
        {
            currX += dirX;
            currY += dirY;
            currentTime++;
            if (lastTime[currX][currY] >= 0 && currentTime - lastTime[currX][currY] < answer)
            {
                answer = currentTime - lastTime[currX][currY];
            }
            lastTime[currX][currY] = currentTime;
        }
    }
    if (answer == 1001)
        answer = -1;

    cout << answer << "\n";

    return 0;
}