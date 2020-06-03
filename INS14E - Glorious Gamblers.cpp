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
        ll n, m;
        cin >> n >> m;
        ll a[n][m];
        double dp[n+1][m+1];
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++)
                cin >> a[i][j];
        }
        for(ll i = 0; i <= n; i++){
            for(ll j = 0; j <= m; j++)
                dp[i][j] = 0;
        }
        for(ll i = n-1; i >= 0; i--){
            for(ll j = m-1; j >= 0; j--){
                double mx = max({dp[i+1][j], dp[i+1][j+1], dp[i][j+1]});
                double mn = min({dp[i+1][j], dp[i+1][j+1], dp[i][j+1]});
                dp[i][j] = (double)a[i][j];
                if(i == n-1) dp[i][j] += dp[i][j+1];
                else if(j == m-1) dp[i][j] += dp[i+1][j];
                else {dp[i][j] += (double) (mx+mn)/2.0;}
            }
        }
        /*for(ll i = 0; i <= n; i++){
            for(ll j = 0; j <= m; j++)
            {
                cout << dp[i][j] << " ";
            }cout << endl;
        }*/
        cout << fixed << setprecision(6) << dp[0][0] << endl;
    }
}
