#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> height, cost;

ll curCost(ll mid){
    ll sum = 0;

    for(int i = 0; i < cost.size(); i++)
        sum += abs(height[i]- mid) * cost[i] *1LL;

    return sum;
}


ll ternarySearch(){

    ll left = 0, right = 100000000;

    while(right - left >= 3){
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        ll cost1 = curCost(mid1);
        ll cost2 = curCost(mid2);
        if(cost1 < cost2)
            right = mid2;
        else
            left = mid1;
    }

    ll ans1 = curCost(right), ans2 = curCost(left), ans3 = curCost(left + 1);

    return min(ans1, min(ans2, ans3));
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, x;
        cin >> n;
        m = n;
        while(n--){
            cin >> x;
            height.push_back(x);
        }
        while(m--){
            cin >> x;
            cost.push_back(x);
        }
        cout << ternarySearch() << endl;
        cost.clear();
        height.clear();
    }
}
