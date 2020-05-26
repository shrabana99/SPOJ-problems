#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000

int n, m;
int L[101], R[101];
long long dp[101][101];

long long sol(int p, int rem)
{ //cout << p << " " << rem << endl;
    if(rem > m) return 0;
    if(p == n) return rem==m;
    long long &r = dp[p][rem];
    if(r == -1)
    {
        r = 0;
        for(int i = L[p]; i <= R[p]; i++)
        {
            r += sol(p+1, rem+i);
        }
    }
    return r;
}

int main(){
    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; i++)
        {
            cin >> L[i] >> R[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << sol(0, 0) << endl;
    }
}
