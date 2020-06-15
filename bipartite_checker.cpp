#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define alpha_size 26

/**
*@Bipartite Check [DFS]
*/

const int N = 1e5 + 10;
vector<int> g[N];
int color[N];
int n, m;
bool visited[N];
#define white 0
#define black 1

bool dfs(int u, int col) {
  visited[u] = true;
  color[u] = col;
  for (auto it : g[u]){
    if (!visited[it]){
      if (!dfs(it, col ^ 1))
        return false;
    }
    else{
      if (color[it] == color[u])
        return false;
    }
  }
  return true;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);    
  
    cin >> n >> m;
    fill (visited, visited + N, false);
    for (int i = 0; i < m; i++){
      int s, e;
      cin >> s >> e;
      g[s].push_back(e);
      g[e].push_back(s);
    }
    bool isBipartite = true;
    for (int i = 1; i <= n; i++){
      if (!visited[i]){
        if (!dfs(i, white)){
          isBipartite = false;
          break;
        }
      }
    }
    if (!isBipartite)
      cout << "IMPOSSIBLE" << endl;
    else{
      for (int i = 1; i <= n; i++)
        cout << color[i] + 1 << " ";
    }
}