//https://www.spoj.com/problems/SQRBR/

#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define MAXn 50
#define clear(a, x) memset(a,x, sizeof(a))

using namespace std;
ll arr[MAXn], dp[MAXn][MAXn], len;


ll solve(ll pos,ll bracket,ll cnt){

    if(pos>len || cnt <0) return 0;
    if(arr[pos] && bracket== 2) return 0;
    if(pos==len && cnt==0) return 1;
    if(dp[pos][cnt]!=-1) return dp[pos][cnt];
    dp[pos][cnt] = solve(pos+1, 1,cnt+1) + solve(pos+1, 2, cnt-1);
    //cout << pos << " " << bracket << " " << cnt << " " <<dp[pos][cnt] << endl;
    return dp[pos][cnt] ;
}
int main(){
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll t ; cin>> t; while(t--){
	ll n, k,fg=0; cin>> n >>k;
	len = 2*n;
	memset(arr, 0, sizeof(arr));
	memset(dp, -1, sizeof(dp));
	for(ll i =1;i<=k;i++){
        ll x;cin>>x;
        arr[x] =1;
    }
    cout << solve(1, 1, 1) << endl;

	}
}
