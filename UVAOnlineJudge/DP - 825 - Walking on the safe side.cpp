#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, long long> mem;

set<pair<int, int>> wall;

int n, m;

long long dp(int x, int y){
    if(x == n && y == m)
        return 1;
    if(x > n || y > m || wall.find({x,y}) != wall.end())
        return 0;
    if(mem.find({x,y}) != mem.end())
        return mem[{x,y}];
    long long o1 = dp(x+1, y);
    long long o2 = dp(x, y+1);
    return mem[{x, y}] = o1+o2;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            int r, c;
            cin >> r;
            string s;
            getline(cin, s);
            stringstream ss(s);
            while(ss >> c){
                wall.insert({r,c});
            }
        }
        cout << dp(1,1) << endl;
        if(t > 0)
            cout << endl;
        mem.clear();
        wall.clear();
    }
}
