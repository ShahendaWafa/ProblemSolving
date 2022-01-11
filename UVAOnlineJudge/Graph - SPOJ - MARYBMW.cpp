#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 50000;
int par[N];
vector<int> vis;
vector<pair<ll, int>> par2;
vector<vector<pair<int, ll>>> adj;

int find(int u){
    return u == par[u] ? u : par[u] = find(par[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v)
        return;

    if(rand() & 1)
        swap(u, v);

    par[u] = v;
}

void init(){
    for(int i = 0; i < N; i++)
        par[i] = i;
}

struct Edge{
    int u, v;
    ll w;
    bool operator<(const Edge &other) const{
        return w > other.w;
    }
};

void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while(q.size()){
        int tp = q.front();
        q.pop();
        for(auto el: adj[tp]){
            int v;
            ll w;
            v = el.first;
            w = el.second;
            if(!vis[v]){
                vis[v] = 1;
                par2[v] = {w, tp};
                q.push(v);
            }
        }
    }
}


int main(){
    //freopen ("output.txt","w",stdout);
    cin.tie(0),ios::sync_with_stdio(0),cout.tie(0);
    int t; cin >> t;
    while(t--){
        init();
        int n, m, flag = 1;
        cin >> n >> m;
        vector<Edge> es(m);
        vis.resize(n);
        par2.resize(n);
        adj.resize(n);
        for(int i = 0; i < m; i++){
            cin >> es[i].u >> es[i].v >> es[i].w;
            es[i].u--;
            es[i].v--;
            if(es[i].u == 0 || es[i].v == 0){
                flag = 0;
            }
        }
        if(flag){
            cout << "-1\n";
            continue;
        }
        sort(es.begin(), es.end());
        vector<Edge> mst;
        for(int i = 0; i < m; i++){
            if(find(es[i].u) != find(es[i].v)){
                mst.push_back(es[i]);
                join(es[i].u, es[i].v);
            }
        }
        for(int i = 0; i < mst.size(); i++){
            adj[mst[i].u].push_back({mst[i].v, mst[i].w});
            adj[mst[i].v].push_back({mst[i].u, mst[i].w});
        }
        bfs(0);
        if(vis[n - 1] == 0){
            cout << '-1\n';
        }
        else{
            set<ll> path;
            int cur = n - 1;
            while(cur != 0){
                path.insert(par2[cur].first);
                cur = par2[cur].second;
            }
            cout << *path.begin() << '\n';
        }
        adj.clear();
        vis.clear();
        par2.clear();
    }
}
