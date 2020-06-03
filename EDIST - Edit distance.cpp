#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define ll long long

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int n1 = a.size(), n2 = b.size();
        int dp[n1+1][n2+1];

        dp[0][0] = 0;
        for(int i = 1; i <= n1; i++)
            dp[i][0] = i;
        for(int j = 1; j <= n2; j++)
            dp[0][j] = j;

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                if(a[i-1] == b[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                else
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
            }
        }
        //for(int i = 0; i <= n1; i++)
        //{for(int j = 0; j <= n2; j++) cout << dp[i][j] << " "; cout << endl;}

        cout << dp[n1][n2] << endl;
    }
}
