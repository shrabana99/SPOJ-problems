#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define ll long long
#define maxn 505

ll a[maxn][maxn], b[maxn][maxn], dp[maxn][maxn], row[maxn][maxn], col[maxn][maxn];

int main()
{
    ll n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            break;

        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < m; j++)
                cin >> a[i+1][j+1];
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < m; j++)
                cin >> b[i+1][j+1];
        for(ll i = 0; i <= n; i++)
            for(ll j = 0; j <= m; j++)
                row[i][j] = col[i][j] = 0,dp[i][j] = -1;

        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++)
                row[i][j] = row[i][j-1]+a[i][j];

        for(ll j = 1; j <= m; j++){
            for(ll i = 1; i <= n; i++){
                col[i][j] = col[i-1][j]+b[i][j];
            }
        }
        for(ll i = 0; i <= n; i++) dp[i][0] = 0;
        for(ll j = 0; j <= m; j++) dp[0][j] = 0;

        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i-1][j]+row[i][j], dp[i][j-1]+col[i][j]);
            }
        cout << dp[n][m] << endl;
    }
}
