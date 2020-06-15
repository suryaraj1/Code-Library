#include <bits/stdc++.h>
using namespace std;

/** 
 * @brief dijkstra using set
 * O(nlogn)
 */
#define int long long
const int INF = 1 << 30;
const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
int n, m, s;
int d[N];
bool visited[N];

void dijkstra(int source) {
  fill (d, d + n, INF);
  d[source] = 0;
  using p = pair<int, int>;
  set<p> s;
  s.insert({0, source});
  while (!s.empty()){
    int u = s.begin() -> second;
    s.erase(s.begin());
    for (auto it : g[u]){
      if (d[it.first]  > d[u] + it.second){
        s.erase({d[it.first], it.first});
        d[it.first] = d[u] + it.second;
        s.insert({d[it.first], it.first});
      }
    }
  }
}

int32_t main(){
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++){
    int u, v, cost;
    cin >> u >> v >> cost;
    g[u].push_back({v, cost});
  }
  dijkstra(s);
  for (int i = 0; i < n; i++){
    if (d[i] == INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}