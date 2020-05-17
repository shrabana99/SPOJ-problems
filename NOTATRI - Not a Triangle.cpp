
#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define mx 22



int main(){

    while(true)
    {
        int n;
        cin >> n;
        if(n == 0) break;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        int ans = 0;
        for(int i = 0; i < n-2; i++)
        {
            for(int j = i+1; j < n-1; j++)
            {
                int k = a[i]+a[j]+1;
                ans += n-(lower_bound(a, a+n, k)-a);
            }
        }
        cout << ans << endl;
    }
}
