#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<ll, ll> p1, pair<ll, ll> p2){
   	 if(p1.first == p2.first){
        	if(p1.second < p2.second) return 1;
       	 return 0;
  	  }
   	 if(p1.first > p2.first) return 1;
  	  return 0;
}



int main() {
    freopen ("a.txt","w",stdout);
	ll n;
	cin >> n;
	while(n--){
        ll a, b, cnt;
        vector<pair<ll, ll>> ans;
        cin >> a >> b;
        for(ll i = a; i <= b; i++){
            ll s = pow(i, 0.5), cnt = 0;
            for(ll j=1; j<=s; j++){
                if(i%j == 0)
                    cnt++;
            }
            cnt*=2;
            if(s*s == i)
                cnt--;
            ans.push_back({cnt,i});
        }
        sort(ans.begin(), ans.end(), comp);
        cout <<"Between " << a << " and " << b <<", " << ans[0].second << " has a maximum of " << ans[0].first << " divisors." << '\n';
	}
}
