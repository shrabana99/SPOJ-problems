//https://www.spoj.com/problems/HIST2/

#include<bits/stdc++.h>
#define ll int
#define pii pair<ll,ll>
#define piii pair<ll, pii>
#define MOD 1000000007
#define MAX 10005
#define INF 10000000001
#define ft first
#define sd second

using namespace std;
ll dp[1<<16][101], dp1[1<<16][101], arr[16];
ll n;

ll tsp(ll mask , ll pos){
    if(mask == ((1<<n)-1)) return arr[pos];
    if(dp[mask][pos] != -1) return dp[mask][pos];
    ll res = -1;
    for(ll i = 0;i<n;i++){
        if((mask&(1<<i))==0){
            res = max(res, abs(arr[pos]- arr[i]) +tsp(mask| (1<<i), i));
        }
    }
    return dp[mask][pos] = res;
}

ll tsp1(ll mask , ll pos){
    if(mask == ((1<<n)-1)) return dp1[mask][pos] =1;
    if(dp1[mask][pos] !=-1) return dp1[mask][pos] ;
    ll c = 0, res = -1;
    for(ll i = 0;i<n;i++){
        if((mask&(1<<i))==0){
            res = max(res, abs(arr[pos]- arr[i]) +tsp(mask| (1<<i), i));
        }
    }
    for(ll i = 0;i<n;i++){
        if((mask&(1<<i))==0){
            if(res == (abs(arr[pos]- arr[i]) +tsp(mask| (1<<i), i))){
                c += tsp1(mask| (1<<i), i);
            }
        }
    }
    return dp1[mask][pos] =c;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(true){
         cin>> n;
        if(n==0) break;
        else{
            ll mx = -1,cnt =0;
            for(ll i =0;i<n;i++){ cin>> arr[i];}
            memset(dp, -1, sizeof(dp));
            memset(dp1, -1, sizeof(dp1));
            for(ll i =0;i<n;i++){
                mx = max(mx, arr[i] + tsp(1<<i, i));
            }
            cout << mx + 2*n << endl;
            for(ll i =0;i<n;i++){
                if((arr[i] + tsp(1<<i, i)) == mx){
                    cnt += tsp1(1<<i,i);
                    // cout << cnt << endl;
                }
            }
            cout << cnt << endl;
        }
    }
}

/*



*/
