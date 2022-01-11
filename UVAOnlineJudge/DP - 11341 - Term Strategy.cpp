#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int arr[15][150];
int mem[15][150];

int dp(int x, int h){
    if(h >= m && x <= n)
        return INT_MIN;

    if(x == n+1 && h <= m)
        return 0;

    int &ret = mem[x][h];
    if(ret != -1)
        return ret;

    int ans = INT_MIN;
    for(int i=1; i<=m; i++){
        if(arr[x][i] >= 5)
            ans = max(arr[x][i]+ dp(x+1, h+i), ans);
    }
    return ret = ans;
}

int main() {
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> arr[i][j];
            }
        }
        memset(mem, -1, sizeof(mem));

        double ans = dp(1,0)/double(n) + 1e-8;
        if(ans >= 5.0)
            cout << "Maximal possible average mark - " << fixed << setprecision(2) << ans << "." << endl;
        else
            cout << "Peter, you shouldn't have played billiard that much." << endl;
    }
}
