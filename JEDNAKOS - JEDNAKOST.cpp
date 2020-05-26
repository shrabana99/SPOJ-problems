#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000

int S, N;
string s, ss;
int dp[1005][5005];

int sol(int p, int n)
{ //cout << p << " " << n << endl;
    if(p == N) {
        if(n == 0) return 0;
        else return INF;
    }
    if(dp[p][n] != -1) return dp[p][n];
    int num = 0, r = INF;
    for(int k = p; k < N; k++)
    {
        num = num*10 + s[k]- '0';
        if(num > n) break;
        r = min(r, 1+sol(k+1, n-num));
    }
    return dp[p][n] = r;

}

int main(){
    cin >> s;
    int j = s.size();
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '=') j = i;
        if(i > j) ss += s[i];
    } //
    S = 0;
    for(auto x: ss)
    {
        S = S*10 + x-'0';
    }
    ss.clear();
    int c0 = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '=') {break;}
        if(s[i] != '0'){
            c0 = 0; ss += s[i];
        }
        else if(c0 <= 3){
            ss += s[i];
            c0++;
        }
    }
    s.clear();
    s = ss; //cout << s << " ";
    N = s.size();
    for(int i = 0; i <= N;  i++)
        for(int j = 0; j <= S; j++)
            dp[i][j] = -1;
    cout << sol(0, S)-1;
}
