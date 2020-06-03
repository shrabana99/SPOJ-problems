#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define N 100005

ll a[N], dp[N];

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];

    ll m, pos[n],dp[n+1], last = 0;
    memset(dp, 0, sizeof(dp));
    memset(pos, 0, sizeof(pos));
    cin >> m;
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        pos[x-1] = y;
    }

    for(ll i = 0; i < n; i++){
        if(pos[i] != 0){
            ll sum = 0, l = max(last, i-pos[i]+1), r = min(n, l+pos[i]);
            for(ll j = l; j < r; j++)
                sum += a[j];
            dp[r-1] = sum + (l-1>=0? dp[l-1]: 0ll);
            last = r-1;
            for(ll j = r; j < min(n, pos[i]+i); j++){
                sum += a[j];
                sum -= a[j-pos[i]];
                dp[j] = max(dp[j-1], dp[j-pos[i]]+sum);
            }
        }
        else if(i > 0){
            dp[i] = max(dp[i], dp[i-1]);
        }
    }
    cout << dp[n-1];

}
