#include <bits/stdc++.h>
using namespace std;

int n, m, t, k, sum;
int arr[10001];
int mem[10001][100];

int mod(int m){
    return (m % k + k)%k;
}

int dp(int x, int sum){
    int &ret = mem[x][sum];
    if(x == n)
        return ret = sum == 0;

    if(mem[x][sum] != -1)
        return ret;

    if(dp(x+1, mod(sum + arr[x])) || dp(x+1, mod(sum - arr[x])))
        return ret = 1;

    return ret = 0;
}


int main() {
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        memset(mem, -1, sizeof(mem));

        if(dp(1, mod(arr[0])))
            cout << "Divisible" << endl;
        else cout << "Not divisible" << endl;
    }
}
