#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[101];
vector<int> v[101];
int flag = 1;

void dfs(int s){
    if(flag){
        flag = 0;
    }
    else{
        if (visited[s])
            return;
        visited[s] = true;
    }
    for (auto u: v[s]) {
        dfs(u);
    }
}


int main(){
    //freopen ("a.txt","w",stdout);
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        while(1){
            int s, ss;
            cin >> s;
            if(s == 0)
                break;
            while(cin >> ss){
               if(ss == 0)
                    break;
                v[s].push_back(ss);
            }
        }
        int t, x;
        vector<vector<int>> ans;
        cin >> t;
        for(int i=0; i<t; i++){
            cin >> x;
            for(int k = 1; k <= n; k++){
                visited[k] = false;
            }
            flag = 1;
            dfs(x);
            vector<int> v1;
            for(int j = 1; j<= n; j++){
                if(visited[j] == false){
                    v1.push_back(j);
                }
            }
            ans.push_back(v1);
        }

        for(int i = 0; i < ans.size(); i++){
                cout << ans[i].size();
            for(int j=0; j < ans[i].size(); j++){
                cout << " " << ans[i][j];
            }
            cout << endl;
        }

        for (auto& it : v) {
            it.clear();
        }
    }
}
