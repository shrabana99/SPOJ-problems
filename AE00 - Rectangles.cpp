//https://www.spoj.com/problems/AE00/

// idea - iterate through 1 to n and add contribution

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define maxn 100005


int main(){
    int n;
    cin >> n;
    int ans = 0, kk = 0;
    for(int i = 1; i <= n; i++)
    {
        int k = n/i; //cout << k-(i-1) << " ";
        if(k > i-1) ans += k-(i-1);
        else break;
    }
    cout << ans;
}
