#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> adj;
bool vis[26];

void dfs(int u){
    if(vis[u]) return;
    vis[u] = true;
    for(auto v: adj[u]){
        if(!vis[v])
            dfs(v);
    }
}


int main(){
    //freopen ("output.txt","w",stdout);
   cin.tie(0),ios::sync_with_stdio(0),cout.tie(0);
   int t; cin >> t;
   while(t--){
    memset(vis, false, sizeof(vis));
    string s; cin >> s;
    int n = s[0] - 'A';
    adj.resize(n+1);
    getline(cin, s);
    while(getline(cin, s)){
        if(s.size() == 0) break;
        adj[s[0] - 'A'].push_back(s[1] - 'A');
        adj[s[1] - 'A'].push_back(s[0] - 'A');
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    if(t > 0) cout << endl;
    adj.clear();
   }

}
