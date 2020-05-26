#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define mx 22

int dp[mx][205];

int sol(int p, int rem)
{
	if(p == 0) return 0;
	if(rem == 0) return 1;
	int &r = dp[p][rem];
	if(r == -1)
    {
        r = 0;
        for(int i = 0; i < p && rem-i>=0; i++)
        {
            r += sol(p-1, rem-i);
        }
    }
    return r;
}

int main(){

    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    sol(mx-1, 204);
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        cout << sol(n, k) << endl;
    }
}
