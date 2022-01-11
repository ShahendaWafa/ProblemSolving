#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n;
    while(cin >> n && n != 0){
        int f = 1;
        cout << n << " = ";
        if(n<0){
            cout << "-1 x ";
            n*=-1;
        }
        int nn = n;
        int s = pow(n, 0.5);
        for(int i=2; i<=s; i++){
            if(n%i == 0){
                if(f){
                    cout << i;
                    f = 0;
                }
                else
                    cout << " x " << i;
                n/=i--;
            }
        }
        if(n!=1){
            if(n == nn)
                cout << n;
            else
            cout << " x " << n;
        }
        cout << endl;
    }
}
