#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen ("a.txt","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n, m, flag = 1;
        cin >> n >> m;
        int a[n][m] = {0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[i][j];
            }
        }

        set<pair<int,int>> s;
        vector<int> v;
        for(int i=0; i<m; i++){
            int cn = 0;
            for(int j=0; j<n; j++){
                if(a[j][i] == 1){
                    cn++;
                    v.push_back(j+1);
                }
            }
            if(cn == 2){
                s.insert({v[0],v[1]});
                v.clear();
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag){
            if(s.size() == m)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
            cout << "No" << endl;

    }
}
