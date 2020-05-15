//https://www.spoj.com/problems/ACPC10D/
// idea - dfs+dp

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define mx 100005

int a[mx][5];
int dp[mx][5];
int Y[] = {1,1,0,-1};
int X[] = {0,1,1,1};
int n;

int dfs(int i, int j) { //cout << i << " " << j << endl;

    if(dp[i][j] != INF)return dp[i][j];
    if(i == n && j == 2) return a[i][j];
    int r = INF;
    for(int k = 0; k < 4; k++)
    {
        int x = i + X[k];
        int y = j + Y[k];
        if(x > 0 && x <= n && y > 0 && y <= 3)
            r = min(r, a[i][j] + dfs(x, y));
    }
    dp[i][j] = r;
    return r;
}
int main(){
    int tc = 1;
    while(true)
    {
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < 4; j++) {
                cin >> a[i][j];
                dp[i][j] = INF;
            }
        }
        cout << tc++ << ". " << dfs(1, 2) << endl;
    }

}
