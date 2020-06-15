c#include <bits/stdc++.h>
using namespace std;

// struct for DSU

const int N = 1e5 + 10;

struct  DSU{
  int p[N], sz[N];
  DSU () {};
  void init(int n){
    for (int i = 0; i <= n; i++)
      p[i] = i, sz[i] = 1;
  }
  int get(int n){
    return p[n] == n ? n : p[n] = get(p[n]);
  }
  void unite(int x, int y){
   x = get(x), y = get(y);
   if (x == y) return;
   if (sz[x] < sz[y]) swap(x, y);
   sz[x] += sz[y];
   p[y] = x;
  }
};

int32_t main(){
 DSU dsu;
 dsu.init(N);
 //;.... add stuff
}