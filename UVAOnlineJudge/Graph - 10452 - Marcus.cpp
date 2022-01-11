#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char letters[10][10];
vector<string> ans;

void solve(int i, int j, char pre){
    if((letters[i][j+1] == 'I' || letters[i][j+1] == 'E' || letters[i][j+1] == 'H' || letters[i][j+1] == 'O' || letters[i][j+1] == 'V' || letters[i][j+1] == 'A' || letters[i][j+1] == '#') && letters[i][j+1] != pre){
        ans.push_back("right");
        if(letters[i][j+1] == '#')
            return;
        solve(i, j+1, letters[i][j]);
    }
    if((letters[i][j-1] == 'I' || letters[i][j-1] == 'E' || letters[i][j-1] == 'H' || letters[i][j-1] == 'O' || letters[i][j-1] == 'V' || letters[i][j-1] == 'A' || letters[i][j-1] == '#') && letters[i][j-1] != pre){
        ans.push_back("left");
        if(letters[i][j-1] == '#')
            return;
        solve(i, j-1, letters[i][j]);
    }
    if((letters[i-1][j] == 'I' || letters[i-1][j] == 'E' || letters[i-1][j] == 'H' || letters[i-1][j] == 'O' || letters[i-1][j] == 'V' || letters[i-1][j] == 'A' || letters[i-1][j] == '#') && letters[i-1][j] != pre){
        ans.push_back("forth");
        if(letters[i-1][j] == '#')
            return;
        solve(i-1, j, letters[i][j]);
    }
    return;
}


int main(){
    int t, n, m, a, b;
    string s;
    cin >> t;
    while(t--){
        memset(letters, '0', sizeof(letters));
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> s;
            for(int j=0; j<m; j++){
                letters[i][j] = s[j];
                if(s[j] == '@'){
                    a = i;
                    b = j;
                }
            }
        }
        solve(a, b, '$');
        for(int i=0; i < ans.size(); i++){
            cout << ans[i] << " \n"[i == ans.size()-1];
        }
        ans.clear();
    }
}
