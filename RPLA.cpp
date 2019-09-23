//https://www.spoj.com/problems/RPLA/

#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> topo;
void tpsort(vector<int>g[],int n,int in[]){
    priority_queue<int, vector<int>, greater<int>> pq;
    int par[n];
    for(int i =0;i<n;i++){
        if(in[i]==0){
            pq.push(i);
            par[i] = 1;
        }
    }
    while(!pq.empty()){
        int t = pq.top();
        pq.pop();
        topo.push_back({par[t],t});
        for(int i=0;i<g[t].size();i++){
            in[g[t][i]]--;
            if(in[g[t][i]]==0){
            pq.push(g[t][i]);
            par[g[t][i]] = par[t]+1;
            }
        }
    }
    sort(topo.begin(), topo.end());
    for(int i=0;i<n;i++){
        cout<< topo[i].first << " " << topo[i].second << endl;
    }
    topo.clear();
}

int main(){
    int t ; cin>> t ;for(int j =0;j<t;j++){
        int nodes, edges;
        cin>> nodes >> edges;
        vector<int> g[nodes];
        int in[nodes];
        memset(in, 0 , sizeof(in));
        for(int i =0;i<edges;i++){
            int u , v;
            cin>> u>> v;
            g[v].push_back(u);
            in[u]++;
        }
      //  for(int i =0;i<nodes;i++) cout<<in_degree[i] << " ";
        cout << "Scenario #" << j+1 << ":\n";
        tpsort(g, nodes, in);

    }
}
