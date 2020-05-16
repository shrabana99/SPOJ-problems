//https://www.spoj.com/problems/AGGRCOW/

// idea- binary search the possible minimum distance and take the largest

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define maxn 100005

int n, c;
int a[maxn];

bool check(int x){
    int k = a[0], tc = c-1;
    for(int i = 1; i < n; i++){
        if(a[i] >= k+x){
            tc--;
            k = a[i];
            if(tc == 0) break;
        }
    }
    if(tc) return false;
    return true;
}

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a+n);
        int l = 0, r = INF, ans = 0;
        while(r>=l)
        {
            int md = (r-l)/2+l; //cout << md << " ";
            if(check(md)){
                l = md+1;
                ans = max(ans, md);
            }
            else r = md-1;
        }
        cout << ans << endl;
    }
}
