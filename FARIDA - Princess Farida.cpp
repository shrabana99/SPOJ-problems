#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000



int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        long long a[n+5], dp[n+5][2];
        a[0] = 0;
        for(int j = 1; j <= n; j++) cin >> a[j];
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j <= n; j++)
        {
            dp[j][0] = max(dp[j-1][0], dp[j-1][1]);
            dp[j][1] = dp[j-1][0]+a[j];
        }
        cout << "Case " << i << ": " << max(dp[n][0], dp[n][1]) << endl;
    }
}
