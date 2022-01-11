#include <bits/stdc++.h>
using namespace std;

int n, t;
int arr[10][1001];
int mem[10][1001];


int dp(int x, int y){
    if(x > 9 || x < 0 || y > n)
        return 1e9;

     if(y == n){
        if(x == 0)
            return 0;
        else
            return 1e9;
    }

    int &ret = mem[x][y];
    if(ret != -1)
        return ret;

    return ret = min(60 - arr[x][y] + dp(x+1, y+1), min(30 - arr[x][y] + dp(x, y+1), 20 - arr[x][y] + dp(x-1, y+1)));
}


int main() {
    cin >> t;
    while(t--){
        cin >> n;
        n/=100;
        for(int i = 9; i >= 0; i--){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        memset(mem, -1, sizeof(mem));
        int ans = dp(0,0);
        cout << ans << "\n\n";
    }
}
