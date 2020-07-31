// https://cp-algorithms.com/graph/bridge-searching.html
// https://www.spoj.com/problems/GRAFFDEF/


#include <iostream>
#include <vector>
#include <iomanip> // for setprecision
#include <cstring> //for memset
#include <map>

using namespace std;
typedef long long ll;


const int N = 1e5+5;
vector<int> graph[N];
int tin[N]; // first discovery time of a node u
int low[N]; // lowest time to reach from root to a node using a back or tree edge, initially it will be tin[u]
int tim = 0;
bool visited[N];
map<pair<int, int>, bool > bridge;
ll id = 0, count[N];

void findBridge(int u, int p){
    visited[u] = true;
    tim++;
    tin[u] = low[u] = tim;
    for(auto v: graph[u]){ // p -> u -> v
        if(v == p) continue; // tree edges(p->u) are already calculated with dfs(by time++)

        //child is already visited, use its discovery time(back edge)
        //??: why are we using min(low[u], tin[v]) instead of min(low[u], low[v])
        if(visited[v]){
            low[u] = min(low[u], tin[v]);
        }
        //child not visited, do a dfs and use childs lowest time
        else{
            findBridge(v, u);
            low[u] = min(low[u], low[v]);
            // if lowest time to reach from root to a child is greater than that of parent
            // it indicates there is no other way to reach to child without using par->child edge
            if(low[v] > low[u]){
                bridge[{u, v}] = bridge[{v, u}] = true;
            }
        }
    }
}

void dfs(int u, int p){
    visited[u] = true;
    count[id]++;
    for(auto v: graph[u]){
        if(!visited[v] && !bridge[{u, v}])
            dfs(v, u);
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            findBridge(i, 0);
    }
    memset(visited, 0, sizeof(visited));

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            id++;
            dfs(i, 0);
        }
    }

    ll fail = 0;
    for(int i = 1; i <= id; i++){
        if(count[i]){
            fail += (ll)(count[i]*(count[i]-1))/2;
        }
    }
    cout << fixed << setprecision(5) << (1.0 - 1.0 * fail / (n * (n - 1) / 2));
}
