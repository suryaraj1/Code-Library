#include <bits/stdc++.h>
using namespace std;

/** 
 * @brief Topological Sort
 * O(v + e)
 */

#define int long long
const int INF = 1 << 29;
const int N = 1e5 + 10;

vector<int> g[N];
int n, m;
int deg[N];
bool viisted[N];


int32_t main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    deg[y]++;
  }
  queue<int> Q;
  for (int i = 0; i < n; i++){
    if (deg[i] == 0)
      Q.push(i);
  }
  vector<int> ret;
  while (!Q.empty()){
    int u = Q.front();
    Q.pop();
    ret.push_back(u);
    for (auto it : g[u]){
      if (--deg[it] == 0)
        Q.push(it);
    }
  }
  // topological ordering
  for (auto it : ret)
    cout << it << endl;
}