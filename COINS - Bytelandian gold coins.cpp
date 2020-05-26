#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define ll long long

map<ll, ll> mp;

ll sol(ll x)
{
    if(x < 2) return x;
    if(!mp[x])
        mp[x] = max(x, sol(x/2)+sol(x/3)+sol(x/4));
    return mp[x];
}
int main(){
    int n;
    mp.clear();
    while(cin >> n)
    {
        cout << sol(n) << endl;
    }

}
