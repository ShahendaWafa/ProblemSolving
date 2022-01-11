#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int ind;
   string a, b;
   while(cin >> a >> b){
    int m = 0;
    int arr1[100000], arr2[100000], ans[100000] = {0};
    for(int i=0; i<a.size(); i++){
        arr1[i] = a[i] - '0';
    }
    for(int i=0; i<b.size(); i++){
        arr2[i] = b[i] - '0';
    }
    int ii = 0, jj = 0;
    for(int i = a.size()-1; i >= 0; i--){
        jj = 0;
        for(int j = b.size()-1; j >= 0; j--){
            ind = jj+ii;
            ans[ind] += arr1[i]*arr2[j];
            while(1){
                if(ans[ind] > 9){
                    ans[ind+1] += ans[ind]/10;
                    ans[ind] %= 10;
                    ind++;
                    m = max(m, ind);
                }
                else
                    break;
            }
            jj++;
            m = max(m, ind);
        }
        ii++;
    }
    int flag = 1;
    for(int i=m; i>=0; i--){
        if(ans[i] == 0 && flag == 1){
            if(i == 0)
                cout << 0;
            else
                continue;
        }
        else{
            cout << ans[i];
            flag = 0;
        }
    }
    cout << endl;
   }
}
