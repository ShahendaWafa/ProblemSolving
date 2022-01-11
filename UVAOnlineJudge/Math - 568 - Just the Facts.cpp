#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[10001];

void fact(){
    int a = 1;
    for(int i = 2; i <= 10000; i++){
        a = i*ans[i-1];
        while(1){
            if(a%10 == 0){
                a/=10;
            }
            else
                break;
        }
        a = a%100000;
        ans[i] = a;
    }
}

int main(){
    //freopen ("a.txt","w",stdout);
   ans[0] = 1;
   ans[1] = 1;
   fact();
   int n;
   while(cin >> n){
    printf("%5d -> %d\n", n, ans[n]%10);
   }

}
