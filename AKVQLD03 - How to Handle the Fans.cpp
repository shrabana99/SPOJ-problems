//https://www.spoj.com/problems/AKVQLD03/

// idea- BIT

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define maxn 1000005
#define ll long long

ll n, q;
ll BIT[maxn];

void add(int p, int f)
{
    while(p <= n)
    {
        BIT[p] += f;
        p += p&(-p);
    }
}

ll find(ll p)
{
    ll res = 0;
    while(p > 0)
    {
        res += BIT[p];
        p -= p&(-p);
    }
    return res;
}

int main(){
    cin >> n >> q;
    while(q--)
    {
        string s;
        int l, r;
        cin >> s >> l >> r;
        if(s == "add")
        {
            add(l, r);
        }
        else{
            cout << find(r) - find(l-1) << endl;
        }
    }

}
