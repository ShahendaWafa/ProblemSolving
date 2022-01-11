#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> ind;
vector<int> ans;

void dfs(int u){
    ans.push_back(u);
    vis[u] = 1;
    for(auto el : adj[u]){
        ind[el]--;
        if(ind[el] == 0)
            dfs(el);
    }
}

int main(){
    //freopen ("output.txt","w",stdout);
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0)
            return 0;
        adj.resize(n);
        vis.resize(n);
        ind.resize(n);

        set<int> s;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            ind[v]++;
            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i] && ind[i] == 0){
                dfs(i);
            }
        }


        if(ans.size()== n){
            for(auto x: ans)
                cout << x + 1 << endl;
        }
        else
            cout << "IMPOSSIBLE" << endl;

        adj.clear();
        vis.clear();
        ind.clear();
        ans.clear();
    }
}
