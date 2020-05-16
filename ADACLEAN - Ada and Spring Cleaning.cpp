//https://www.spoj.com/problems/ADACLEAN/

// idea - double hash and store the value in set

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define maxn 100005
#define ll long long
#define pii pair<ll, ll>
#define ft first
#define sd second

#define p1 31
#define p2 37
#define M1 1000000007
#define M2 1000000009

ll power(ll b, ll p, ll mod){
    ll ret = 1;
    while(p){
        if(p%2)
            ret = (ret*b)%mod;
        b = (b*b)%mod;
        p/=2;
    }
    return ret;
}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        set<pii> ss;

        ll v1 = 0, v2 = 0, b1 = 1, b2 = 1;

        for(int i = 0; i < k; i++)
        {
            v1 = (v1 + b1*s[i])%M1;
            b1 = (b1*p1)%M1;

            v2 = (v2 + b2*s[i])%M2;
            b2 = (b2*p2)%M2;
        }
        ss.insert({v1, v2});
        ll inv1 = power(p1, M1-2, M1);
        ll inv2 = power(p2, M2-2, M2);
        for(int i = k, j = 0; i < n; i++, j++)
        {
            v1 -= s[j];
            if(v1 < 0) v1 += M1;
            v1 = (v1 + b1*s[i])%M1;
            v1 = (v1*inv1)%M1;

            v2 -= s[j];
            if(v2 < 0) v2 += M2;
            v2 = (v2 + b2*s[i])%M2;
            v2 = (v2*inv2)%M2;
            ss.insert({v1, v2}); //cout << v1 << " " << v2 << endl;
        }
        cout << ss.size() << endl;
    }
}
