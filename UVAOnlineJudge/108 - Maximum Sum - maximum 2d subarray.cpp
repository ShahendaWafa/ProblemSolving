#include <bits/stdc++.h>
using namespace std;

int n, M[100][100], ROW, COL;

int maxSubArraySum(int a[]){
   int max_so_far = a[0];
   int curr_max = a[0];

   for (int i = 1; i < n; i++){
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int maxRec(int M[100][100]){
    int maxSum = INT_MIN;

    int left, right, i;
    int temp[ROW], sum;

    for (left = 0; left < COL; ++left) {
        memset(temp, 0, sizeof(temp));
        for (right = left; right < COL; ++right) {
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];
                sum = maxSubArraySum(temp);

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}


int main(){
    cin >> n;
    ROW = n;
    COL = n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> M[i][j];
        }
    }
    int ans = maxRec(M);
    cout << ans << endl;
	return 0;
}
