//https://www.spoj.com/problems/AIBOHP/

// idea- keep longest common subsequence of the string and its reverse
//       to minimize answer

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define maxn 100005

int n;
string s, r;

int lcs()
{
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(s[i] == r[j]));
        }
    }
    return dp[n][n];
}

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        cin >> r;
        s = r;
        reverse(r.begin(), r.end());
        n = s.size();
        cout << n-lcs() << endl;
    }
}
