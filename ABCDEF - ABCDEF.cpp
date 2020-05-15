//https://www.spoj.com/problems/ABCDEF/
// idea - store left part for every possible a, b, c and check for every possible c, d, f

#include<bits/stdc++.h>

using namespace std;

#define N 100005
#define ll int // long long
#define INF 100000

int main(){
   int n;
   cin >> n;
   int a[n];
   map<int, int> mp;

   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)
            mp[a[i]*a[j]+a[k]]++;

   long ans =0;
   for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)
        {
            if(a[k] != 0) ans += mp[(a[i]+a[j])*a[k]];
        }

   cout << ans ;

}
