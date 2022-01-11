#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
bool prime[1000001];
vector<int> v;

bool check(int n){
    int ans = 0;
    while(n > 0){
        ans += n%10;
        n/=10;
    }
    auto it = find(v.begin(), v.end(), ans);
    if(it == v.end())
       return false;
    return true;
}

void SieveOfEratosthenes(int n){
	memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=n; p++){
        arr[p] = arr[p-1];
		if (prime[p] == true){
		    v.push_back(p);
			for (int i=p*p; i<=n; i += p){
				prime[i] = false;
			}
		}
	}
}

int main()
{
	int t, a, b, n = 1000000;
	SieveOfEratosthenes(n);

    for(int i=0; i<1000001; i++){
        arr[i] = arr[i-1];
        if(prime[i]==true && check(i))
            arr[i]++;
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        int an = arr[b] - arr[a-1];
        printf("%d\n", an);
    }
	return 0;
}

