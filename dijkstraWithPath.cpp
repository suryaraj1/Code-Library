#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define alpha_size 26

/**
*@brief Dijkstra with path
*/

const int INF = 1 << 30;
const int N = 2e5 + 10;
int n, m;
int d[N];
int p[N];
vector<int> path;
vector<pair<int, int> > g[N];

void dijkstra(int source) {
  fill (d, d + N, INF);
  d[source] = 0;
  set<pair<int, int> > s;
  s.insert({0, source});
  while (!s.empty()){
    int u = s.begin() -> second;
    s.erase(s.begin());
    for (auto it : g[u]){
      if (d[it.first] > d[u] + it.second){
        s.erase({d[it.first], it.first});
        d[it.first] = d[u] + it.second;
        s.insert({d[it.first], it.first});
        p[it.first] = u;
      }
    }
  }
}

void printPath(int source, int destination) {
  int cur = destination;
  while (p[cur]){
    path.push_back(cur);
    cur = p[cur];
  }
  path.push_back(source);
  reverse(path.begin(), path.end());
  for (auto it : path)
    cout << it << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);    
  
    cin >> n >> m;
    for (int i = 0 ; i < m; i++){
      int s, e;
      cin >> s >> e;
      g[s].push_back({e, 1});
      g[e].push_back({s, 1});
    }
    dijkstra(1);
    if (d[n] == INF)
      cout << "IMPOSSIBLE" << endl;
    else{
      cout << d[n] + 1 << endl;
      printPath(1, n);
    }
}