#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

vector<int> bfs(string u){
    queue<string> q;
    vector<int> ans;
    q.push(u);
    while(q.size()){
        string tp = q.front();
        q.pop();
        if(mp.find(tp) != mp.end()){
            ans.push_back(mp[tp]);
            q.push(tp+'L');
            q.push(tp+'R');
        }
    }
    return ans;
}

int main() {
    //freopen ("a.txt","w",stdout);
	string s;
	while(cin >> s){
        if(s == "()"){
            vector<int> tree = bfs("");
            if(tree.size() == mp.size()){
                for(int i = 0; i < tree.size(); i++){
                    cout << tree[i] << " \n"[i == tree.size()-1];
                }
            }
            else{
                cout << "not complete\n";
            }
            mp.clear();
            continue;
        }
        int flag = 1;
        string num = "";
        string pos = "";
        for(int i = 1; i < s.size()-1; i++){
            if(s[i] == ','){
                flag = 0;
                continue;
            }
            if(flag)
                num += s[i];
            if(!flag)
                pos += s[i];
        }
        int n = stoi(num);
        if(mp.find(pos) == mp.end())
            mp[pos] = n;
        else
            mp["X"] = 0;
	}
}
