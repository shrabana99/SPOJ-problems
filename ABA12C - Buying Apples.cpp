//https://www.spoj.com/problems/ABA12C/

// idea - knapsack problem

#include<bits/stdc++.h>

using namespace std;

#define N 100005
#define ll int // long long
#define INF 100000
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[k];
    for(ll i = 0; i < k; i++)cin >> a[i];

    ll dp[k+1];
    for(ll i = 0; i <= k; i++) dp[i] = INF;

    dp[0] = 0;

    for(ll i = 0; i <= k; i++){
        for(ll j = 0; j < k; j++){
            if(a[j] == -1) continue;
            if(j+1+i <= k && dp[i] != INF) dp[j+1+i] = min(dp[j+1+i], dp[i]+a[j]);
        }
    }

    if(dp[k] == INF) dp[k] = -1;
    cout << dp[k] << endl;

}
int main(){
    ll t;
    cin >> t;
    while(t--)
        solve();
}
