#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
   //freopen ("a.txt","w",stdout);
   int t;
   cin >> t;
   while(t--){
    vector<pair<int, int>>v;
    int p;
    cin >> p;
    cin.ignore();
    string s;
    for(int i=1; i<=p; i++){
        getline(cin, s);
        stringstream ss(s);
        string num;
        int ans = 0;
        while(ss >> num){
           ans++;
        }
        v.push_back({ans, i});
    }

    sort(v.begin(), v.end());
    cout << v[0].second;
    if(v.size() > 1){
        for(int i=1; i<v.size(); i++){
            if(v[i].first == v[0].first)
                cout << " " << v[i].second;
            else
                break;
        }
    }
    cout << endl;
    v.clear();

   }
}
