#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int mx = 100000;
int n, m, dist[mx][2];
vector<vector<pair<int, int>>> adj;

int sol(int u, int x){

    for(int i = 0; i < mx; i++){
        for(int j = 0; j < 2; j++){
            dist[i][j] = 1e7;
        }
    }

    deque<pair<int, int>> dq;
    dq.push_back({u, 0});
    dq.push_back({u, 1});
    dist[u][0] = dist[u][1] = 0;

    while(!(dq.empty())){
        pair<int, int> cur = dq.front();
        int v = cur.first;
        int v_dir = cur.second;
        int v_dist = dist[v][v_dir];
        dq.pop_front();

        if(v == x) return v_dist;

        for(auto it: adj[v]){
            int to = it.first;
            int to_dir = it.second;
            int to_dist = 0;

            if(to_dir == v_dir)
                to_dist = dist[v][v_dir];
            else
                to_dist = dist[v][v_dir] + 1;

            if(to_dist < dist[to][to_dir]){
                if(to_dist <= v_dist)
                    dq.push_front({to, to_dir});
                else
                    dq.push_back({to, to_dir});
                dist[to][to_dir] = to_dist;
            }
        }
    }

    return -1;
}


int main(){
    //freopen ("output.txt","w",stdout);
   cin.tie(0),ios::sync_with_stdio(0),cout.tie(0);

   cin >> n >> m;
   adj.resize(n);

   for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back({v, 0});
    adj[v].push_back({u, 1});
   }

    int from, to;
    cin >> from >> to;
    from--; to--;
    cout << sol(from, to) << endl;

}
