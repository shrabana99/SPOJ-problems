//https://www.spoj.com/problems/ACPC11B/

// idea - merge and sort

#include<bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define mx 100005
#define pii pair<int, int>
#define ft first
#define sd second

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        vector<pii> v;
        int n;
        cin >> n;
        for(int i = 0; i  <n; i++) {
            int x;
            cin >> x;
            v.push_back({x, 1});
        }
        cin >> n;
        for(int i = 0; i  <n; i++) {
            int x;
            cin >> x;
            v.push_back({x, 2});
        }
        sort(v.begin(), v.end());
        int mn = INF;
        for(int i = 0; i < v.size()-1; i++)
        {
            if(v[i].sd != v[i+1].sd)
                mn = min(mn, abs(v[i].ft - v[i+1].ft));
        }
        cout << mn << endl;
    }
}
