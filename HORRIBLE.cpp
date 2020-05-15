//https://www.spoj.com/problems/HORRIBLE/

#include<bits/stdc++.h>
#define ll long long
#define MINint 10000000
#define N  1000005
using namespace std;

ll n,m;
ll lazy[4*N+1];
ll tree[4*N+1];
void shift(ll l , ll r, ll rt){
    if(lazy[rt]){
        //if(l!=r){
            lazy[rt*2]+= lazy[rt];
            lazy[rt*2+1]+= lazy[rt];
        //}
    }
}
void task(ll rt, ll l , ll r){
    tree[rt] += lazy[rt]*(r-l+1);lazy[rt]= 0;//tree[rt*2] + tree[rt*2+1] ;
}
void update(ll a, ll b, ll c, ll rt, ll l , ll r){
   // if(lazy[rt]) return;
    if(l>r) return;
    if(b<l || r<a) return;
    else if(a<=l && r<=b) {
        lazy[rt] += c;
    }
    else {
        if(a<=l && b<=r) tree[rt]+= c*(b-l+1);
        else if(l<=a && r<=b) tree[rt]+= c*(r-a+1);
        else if (l<=a && b<=r)tree[rt]+= c*(b-a+1);
        shift(l,r, rt);
        ll m = l+(r-l)/2;
        update(a,b,c,rt*2, l ,m);update(a,b,c,rt*2+1, m+1,r);
        task(rt, l , r);//lazy[rt]+= c;
    }
}
ll quer( ll a,ll b,ll rt, ll l , ll r){
    if(l>r) return 0;
    if(b<l || r<a) return 0;
    else if(a<=l && r<=b) {
        return tree[rt]+ lazy[rt]*(r-l+1);
    }
    else {
        shift(l,r, rt);
        ll m = l+(r-l)/2;
        ll x =quer(a,b,rt*2, l ,m);
        ll y =quer(a,b,rt*2+1, m+1,r);
        task(rt, l ,r);
       // cout<< l << " " << r << " " << x<< " " <<y << endl;
        return x+y;
    }
}
/*
void prin(ll rt, ll l , ll r){
if(l>r) return;
else if(l==r) {cout<< l << " " << r << " " << lazy[rt]+tree[rt] <<endl; return;}
ll m = (l + r)/2;
prin(rt*2, l, m); prin(rt*2+1, m+1, r);
cout<< l << " " << r << " " << lazy[rt]+tree[rt] <<endl;
}
*/
int main(){
    ll t; cin>> t; while(t--){
        memset(lazy, 0, sizeof(lazy));memset(tree, 0, sizeof(tree));
        cin>> n>>m;
        while(m--){
            ll q;
            cin>> q;
            if(!q){
                ll x, y , v; cin>>x>>y>>v;
               // if(x>y) swap(x,y);
                update(x,y, v, 1,1,n);
            }
            else{
                ll x,y; cin>> x>>y;
             //   if(x>y) swap(x,y);
                cout<< quer(x,y,1,1,n)<<endl;
            }
        }
       // prin(1,1,n);
    }

}
