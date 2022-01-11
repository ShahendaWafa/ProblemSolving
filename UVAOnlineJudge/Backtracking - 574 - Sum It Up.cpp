#include <bits/stdc++.h>
using namespace std;

int t, n, a[12];
vector<int> v;
set<vector<int>> sol;

bool comp(int p1, int p2){
   	 if(p1 > p2) return 1;
  	  return 0;
}

void backtrack(int x, int sum){
    if(x == n){
        if(sum == t){
            sort(v.begin(), v.end(), comp);
            sol.insert(v);
        }
        return;
    }
    v.push_back(a[x]);
    backtrack(x+1, sum + a[x]);
    v.pop_back();
    backtrack(x+1, sum);
}

int main() {
   while(cin >> t >> n){
        if(n == 0) break;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        backtrack(0, 0);

        cout << "Sums of " << t << ":\n";
        if(sol.empty())
            cout << "NONE\n";

        for(auto it = sol.rbegin(); it != sol.rend(); it++){
            vector<int> vec = *it;
            for(int i=0; i<vec.size(); i++){
                cout << vec[i] << "+\n"[i==vec.size()-1];
            }
        }

        sol.clear();
        v.clear();
   }
}
