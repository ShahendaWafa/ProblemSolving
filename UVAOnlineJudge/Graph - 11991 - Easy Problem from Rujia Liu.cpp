#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
   //freopen ("a.txt","w",stdout);
   int n, m, a, b, c;
   while(cin >> n >> m){
       map<int,vector<int>> mp;
       for(int i=1; i<=n; i++){
        cin >> a;
        mp[a].push_back(i);
       }
       while(m--){
        cin >> b >> c;
        map<int,vector<int>>:: iterator it = mp.find(c);
        if(it == mp.end())
            cout << 0 << endl;
        else{
            if(it->second.size()<b)
                cout << 0 << endl;
            else
                cout << it->second[b-1] << endl;
        }
       }
   }
}
