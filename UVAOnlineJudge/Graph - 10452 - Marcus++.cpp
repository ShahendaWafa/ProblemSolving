#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
char letters[10][10];
int dx[] = {-1, 0, 0};
int dy[] = {0, -1, 1};
string dir[] = {"forth", "left", "right"};
string path = "IEHOVA#";
vector<string> ans;

void dfs(int i, int j, int ind){
    if(ind == path.size())
        return;
    for(int k=0; k<3; k++){
        int newi = i + dx[k], newj = j + dy[k];
        if(newi >= 0 && newi < n && newj >= 0 && newj < m){
            if(letters[newi][newj] == path[ind]){
                ans.push_back(dir[k]);
                dfs(newi, newj, ind+1);
            }
        }
    }
}


int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> letters[i][j];
                if(letters[i][j] == '@'){
                    a = i;
                    b = j;
                }
            }
        }
        dfs(a, b, 0);
        for(int i=0; i < ans.size(); i++){
            cout << ans[i] << " \n"[i == ans.size()-1];
        }
        ans.clear();
    }
}
