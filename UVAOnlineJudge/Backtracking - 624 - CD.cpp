#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0, a[20];
vector<int> v, sol;

void backtrack(int x, int sum){
    if(x == n){
        if(sum <= m){
            if(sum > ans){
                ans = sum;
                sol = v;
            }
        }
        return;
    }
    v.push_back(a[x]);
    backtrack(x+1, sum + a[x]);
    v.pop_back();
    backtrack(x+1, sum);
}


int main() {
    while(cin >> m >> n){
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        backtrack(0,0);
        for(auto z : sol)
            cout << z << " ";

        cout << "sum:" << ans << endl;
        ans = 0;
        v.clear();
    }
}
