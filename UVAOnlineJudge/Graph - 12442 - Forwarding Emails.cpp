#include<bits/stdc++.h>

using namespace std;

int adj[50001];
vector<int> sum;
bool visited[50001];
int cnt;


int dfs(int s){
    visited[s] = true;
        int x = adj[s];
        if(!visited[x]){
            cnt++;
            dfs(x);
        }
    visited[s] = false;
    return sum[s] = cnt;
}

int main(){
    int t;
    cin >> t;

    for(int j=1; j<=t; j++){
        int n, u, v, mx, ans;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> u >> v;
            adj[u] = v;
        }
        sum.assign(n+1,-1);
        cnt = 1;
        mx = 0;
        for(int i = 1; i <= n; i++){
            if(sum[i] == -1){
               dfs(i);
               sum[i] = cnt;
            }
            if(cnt > mx){
                mx = cnt;
                ans = i;
            }
            cnt = 1;
        }

        cout << "Case " << j << ": " << ans << endl;
    }
}
