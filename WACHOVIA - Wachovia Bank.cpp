#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define ll long long

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int c, n, ans = 0;
        cin >> c >> n;
        int w[n+1], v[n+1];
        for(int i = 0; i < n; i++) cin >> w[i] >> v[i];

        int dp[n+1][c+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= c; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(j-w[i-1] >= 0){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1] );
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        cout << "Hey stupid robber, you can get " << dp[n][c] << "." << endl;
    }
}
