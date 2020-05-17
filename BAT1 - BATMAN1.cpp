#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define mx 22


int n, m, tot;
int opn[mx], cost[mx][mx], rate[mx][mx], dp[1005][mx][mx];

int sol(int k, int p, int b) {
    if(p == n) return 0;
    int &r = dp[k][p][b];
    if(r != -1) return r;
    r = sol(k, p+1, -1); // without taking any from pth position
    if(b == -1)
    {
        if(opn[p] <= k) r = max(r, sol(k-opn[p], p, b+1)); // giving opening charge for pth position
    }
    else if(b == m) r = max(r, sol(k, p+1, -1)); // all checked for pth position , time to go at p+1
    else{
        if(cost[p][b] <= k) // will take for many times
            r = max(r, rate[p][b] + sol(k-cost[p][b], p, b));
        r = max(r, sol(k, p, b+1)); // go to next batch
    }
    return r;
}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> tot;
        for(int i = 0; i < n; i++) cin >> opn[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> cost[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> rate[i][j];

        memset(dp, -1, sizeof(dp));
        cout << sol(tot, 0, -1) << endl;
    }
}
