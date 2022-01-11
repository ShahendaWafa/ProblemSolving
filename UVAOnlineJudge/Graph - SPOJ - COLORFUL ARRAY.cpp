#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 200001;
int par[N];
int last[N];
int col[N];

int find(int u){
    return u == par[u] ? u : par[u] = find(par[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    if(rand() & 1)
        swap(u, v);
    par[u] = v;
    last[v] = max(last[v], last[u]);
}

void init(){
    for(int i = 0; i < N; i++)
        par[i] = last[i] = i;
}

struct Q{
    int l, r, c;
};

int main(){
    //freopen ("output.txt","w",stdout);
   srand(time(0));
   init();
   int n, q;
   cin >> n >> q;
   vector<Q> qs(q);
   for(int i = 0; i < q; i++){
    cin >> qs[i].l >> qs[i].r >> qs[i].c;
    qs[i].l--;
    qs[i].r--;
   }
   reverse(qs.begin(), qs.end());
   for(int i = 0; i < q; i++){
    int cur = last[find(qs[i].l)];
    while(cur <= qs[i].r){
        col[cur] = qs[i].c;
        join(cur, cur + 1);
        cur = last[find(cur)];
    }
   }
   for(int i = 0; i < n; i++){
    cout << col[i] << endl;
   }

}
