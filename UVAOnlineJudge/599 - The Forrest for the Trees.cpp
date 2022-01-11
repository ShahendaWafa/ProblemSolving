#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[100];
vector<int> v[100];

void dfs(int s) {
    if (visited[s])
        return;
    visited[s] = true;
    // process node s
    for (auto u: v[s]) {
        dfs(u);
    }
}

int main(){
    //freopen ("a.txt","w",stdout);
    int t;
    cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        set<int> dist;
        vector<int> alph;
        string s;
        while(cin >> s){
            if(s[0]=='*')
                break;
            v[s[1]-'A'].push_back(s[3]-'A');
            v[s[3]-'A'].push_back(s[1]-'A');
            dist.insert(s[1]-'A');
            dist.insert(s[3]-'A');
        }
        cin >> s;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ',')
                alph.push_back(s[i]-'A');
        }
        int ans = 0;
        for(int i=0; i<alph.size(); i++){
            if(!(visited[alph[i]])){
                dfs(alph[i]);
                ans++;
            }
        }

        int acorn = alph.size() - dist.size();
        int trees = ans - acorn;

        cout << "There are "  << trees << " tree(s) and " << acorn << " acorn(s)." << endl;
        for (auto& it : v) {
            it.clear();
        }
    }
}
