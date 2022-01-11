#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
char graph[25][25];
bool visited[25][25];

void dfs(int x, int y){

    if(x < 0 || x >= n || y < 0 || y >= n || graph[x][y] == '0' || visited[x][y] == true)
        return;

    visited[x][y] = true;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    dfs(x+1, y+1);
    dfs(x-1, y-1);
    dfs(x-1, y+1);
    dfs(x+1, y-1);
    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t = 1;
    while(cin >> n){
        memset(visited, false, sizeof(visited));
        int c = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> graph[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] == '1' && visited[i][j] == false){
                    dfs(i, j);
                    c++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", t, c);
        t++;
    }
    return 0;
}

