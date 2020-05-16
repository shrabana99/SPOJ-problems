//https://www.spoj.com/problems/ADARAIN/

// idea - scanline ?

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define maxn 100005


int main(){

    int n, m, w;
    cin >> n >> m >> w;
    int dp[w+5];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x]++;
        dp[y+1]--;
    }

    for(int i = 1; i <= w; i++)
    {
        dp[i] += dp[i-1];
    }

    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cout << dp[x] << endl;
    }

}
