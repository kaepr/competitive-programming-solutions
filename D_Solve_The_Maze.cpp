#include <bits/stdc++.h>
using namespace std;

char grid[52][52];
int n,m;
int dir[4][2] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};

bool isValid(int i,int j){
    return i>=1 && i<=n && j>=1 && j<=m;
}

void solve(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; i++){
            cin>>grid[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid[i][j]=='B'){
                for(int k=0; k<4; k++){
                    int newX = i + dir[k][0];
                    int newY = j + dir[k][1];

                    if(isValid(newX, newY) && grid[newX][newY]=='.')
                        grid[newX][newY] = '#';

                }
            }
        }
    }

    queue> que;
    bool visited[n+5][m+5];
    memset(visited, false, sizeof(visited));

    if(grid[n][m]=='.'){
        que.push({n,m});
    }

}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}