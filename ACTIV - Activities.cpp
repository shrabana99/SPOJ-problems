// https://www.spoj.com/problems/ACTIV/

// idea - 1. sort according to ending time
//        2. for each period, find out the closest period that has ending time <= starting time of current one
//           and fill dp


#include<bits/stdc++.h>

using namespace std;
#define INF 100000000 //1000000000100000000
#define maxn 100005
#define pii pair<int, int>
#define ft first
#define sd second



int main(){

    while(true)
    {
        int n;
        long long dp[maxn];
        vector<pii> v;
        scanf("%d", &n);
        if(n == -1) break;
        memset(dp, 0, sizeof(dp));
        v.push_back({0, 0});
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d",&x,&y);
            v.push_back({y, x});
        }

        sort(v.begin(), v.end());

        for(int i = 1; i <= n; i++)
        {
            int l = 0, r = i-1, mx = 0;
            while(l <= r)
            {
                int md = (l+r)/2;
                if(v[md].ft <= v[i].sd){
                    l = md+1;
                    mx = max(mx, md);
                }
                else r = md - 1;
            }
            dp[i] = dp[mx] + 1 + dp[i-1];
            dp[i] %= INF;
        }

        printf("%08lld\n", dp[n]);

    }
}
