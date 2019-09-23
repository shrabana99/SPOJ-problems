//https://www.spoj.com/problems/SUBMERGE/

#include<bits/stdc++.h>
#define ll int
#define pii pair<ll,ll>
#define piii pair<ll, pii>
#define MOD 1000000007
#define MAX 100005
#define INF 10000000001

using namespace std;
ll n , m, tim=0, ans;
vector<pii> v1;
bool comp(pii a, pii b){
    if(a.first== b.first) return a.second<b.second;
    else return a.first<b.first;
}

void cut_vertex(ll u,vector<ll>vec[],ll par[],ll vis[],ll disc[],ll low[], ll ar[]){
    vis[u] = 1;
    tim++;
    disc[u] = low[u] = tim;
    ll ch= 0;
    for(ll i =0;i< vec[u].size(); i++){
        ll v =vec[u][i];
        if(!vis[v]){
            par[v] = u;
            ch++;
            cut_vertex(v,vec, par, vis, disc, low, ar);
            low[u] = min(low[u], low[v]);
            if(par[u]==-1  && ch>1) ar[u]=1;
            else if(par[u]!=-1  && low[v]>= disc[u]) ar[u] = 1;
        }
        else if(par[u]!=v){
            low[u] = min(low[u], disc[v]);
        }
    }

}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    while(true){
        scanf("%d%d", &n,&m);
        if(n==0 && m==0 ) break;
        vector<ll>vec[n];
        for(ll i=0;i<m;i++){
            ll x, y;
            scanf("%d%d", &x,&y);
            x--, y--;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        ll vis[n], par[n], disc[n], low[n], ar[n];
        memset(par, -1, sizeof(par));
        memset(vis, 0, sizeof(vis));
        memset(disc, 0, sizeof(disc));
        memset(low, 0, sizeof(low));
        memset(ar, 0, sizeof(ar));
        //vector<pii> v1;
        for(ll i= 0;i<n;i++){
            if(!vis[i])cut_vertex(i,vec, par, vis, disc, low, ar);
        }
        for(ll i= 0;i<n;i++){
            if(ar[i])ans++;
        }
        cout << ans << endl;
        tim=0;
        ans =0;
    }
}


