#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define alpha_size 26

/**
*@brief Kruskal MST
*/

struct edge{
  int u, v, cost;
  bool operator < (edge const &other){
     return cost < other.cost;  
  } 
};

const int N = 1e5 + 11;
int n, m;
int p[N], sz[N];
vector<edge> ret, edge_list;
int weight = 0;
int ccps;

int get(int x){
  if (p[x] == x) return x;
  return p[x] = get(p[x]);  
}

void unite(int x, int y){
  x = get(x), y = get(y);
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  p[y] = x; 
  ccps--;
}

void KruskalMST(vector<edge> &edge_list){
    sort(edge_list.begin(), edge_list.end());
    for(auto it : edge_list){
    if (get(it.u) != get(it.v)){
       weight += it.cost;
       ret.push_back(it);
       unite(it.u, it.v); 
    }
  }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);    
  
    cin >> n >> m;
    for(int i = 0; i < n; i++){
      p[i] = i;
      sz[i] = 0;  
    }
    vector<edge> g;
    ccps = n;
    for(int i = 0; i < m; i++){
      int x, y, val;
      cin >> x >> y >> val;
      g.push_back({x, y, val}); 
   }
   KruskalMST(g);
   if (ccps > 1)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << weight << endl;
    
}