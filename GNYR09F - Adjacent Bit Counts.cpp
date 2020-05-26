#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define mx 22

int dp[105][105][2];
int no, n, k;

int sol(int p, int rem, int d){ //cout << p << " " << rem  << endl;
    if(p == n) return rem == k;
    int &r = dp[p][rem][d];
    if(r != -1) return r;
    r = sol(p+1, rem, 0) + sol(p+1, rem+d, 1);
    return r;
}

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        cin >> no >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << no << " " << sol(0, 0, 0) << endl;
    }
}
