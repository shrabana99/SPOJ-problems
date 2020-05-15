//https://www.spoj.com/problems/ABCPATH/

// idea - dfs and store maximum length reached in dp table

#include<bits/stdc++.h>

using namespace std;

#define N 52
#define ll int // long long
#define INF 100000

int n, m, dp[N][N];
char a[N][N];
int X[]={+0,+0,+1,-1,-1,+1,-1,+1};
int Y[]={-1,+1,+0,+0,+1,+1,-1,-1};

int dfs(int i, int j)
{
    if(dp[i][j] != -1) return dp[i][j];
    int r = 1;
    for(int k = 0; k < 8; k++)
    {
        int x = i + X[k];
        int y = j + Y[k];
        if( x >= 0 && x < n && y >= 0 && y < m && a[i][j]+1 == a[x][y] ){
            r = max(r, dfs(x, y)+1);
        }
    }
    dp[i][j] = r;
    return r;
}
int main(){
    int tc = 1;
    while(true)
    {
        memset(dp, -1, sizeof(dp));

        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin>>a[i][j];

        int mx =0 ;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'A'){
                    mx = max(mx, dfs(i, j));
                }
            }
        }
        cout << "Case " << tc << ": " << mx << endl; tc++;
    }

}
