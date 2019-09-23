//https://www.spoj.com/problems/TRIPINV/

#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll, ll>
#define s second
#define f first
#define MOD 1000000007
#define maxn 100005
using namespace std;

void update(ll pos,ll b[], ll n){
    while(pos<=n){
        b[pos] +=1;// increasing the number
        pos += (pos&(-pos));
    }
}
ll query(ll pos,ll b[]){
    ll ans =0;
    while(pos>0){
        ans +=b[pos] ;// calculating numbers less than given number
        pos -= (pos&(-pos));
    }
    return ans;
}
int main(){
    ll n, i; cin>>n;
    ll arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    ll BIT[n+1], d[n+1][2];
    memset(BIT, 0, sizeof(BIT));
    for(i=0;i<n;i++){
        d[i][0] = query(arr[i], BIT);// want to count total numbers less or equal to arr[i]
        update(arr[i], BIT, n);
    }
    memset(BIT, 0, sizeof(BIT));
    for(i=n-1;i>=0;i--){
        d[i][1] = query(arr[i]-1, BIT);// want to count total numbers strictly less than arr[i]
        update(arr[i], BIT, n);
    }
    ll ans=0;
    for(i=0;i<n;i++){
      //  cout<< d[i][0] << " " << d[i][1] << endl;
        ans += (i- d[i][0])*d[i][1]; // number greater than arr[i]* number less than arr[i]
    }
    cout<< ans << endl;

}
