#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define maxn 1000005
#define ll long long

#define mx 202
int a[mx], n, dp[mx][mx][mx];

int solve(int p, int inc, int dec)
{
    if(p == n) return 0;
    int &r = dp[p][inc][dec];
    if(r != -1) return r;
    r = solve(p+1, inc, dec);
    if(a[p] > inc) r = max(r, 1+solve(p+1, a[p], dec));
    if(a[p] < dec) r = max(r, 1+solve(p+1, inc, a[p]));
    return r;
}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        set<int> s;
        for(int i = 0; i < n; i++)
        {
            int x; cin >> x; s.insert(x); a[i] = x;
        }
        map<int, int> mp;
        int id = 1;
        for(auto it = s.begin(); it != s.end(); it++){
            mp[*it] = id++;
        }
        for(int i = 0; i < n; i++)
        {
            a[i] = mp[a[i]];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, mx-1) << endl;
    }
}
