#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define alpha_size 26

/**
*@brief DFS on grid
*/

const int N = 1e3 + 10;
int n, m;
bool visited[N][N];
char g[N][N];
int cnt = 0;
vector<pair<int, int> > dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int r, int c) {
  return (r >= 0 && c >= 0 && r < n && c < m && !visited[r][c] && g[r][c] == '.');
}

void dfs(int r, int c) {
  visited[r][c] = true;
  for (int k = 0; k < 4; k++){
    int x = r + dir[k].first;
    int y = c + dir[k].second;
    if (isValid(x, y))
      dfs(x, y);
  }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);    
  
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> g[i][j];
    memset(visited, false, sizeof visited);
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (!visited[i][j] && g[i][j] == '.'){
          cnt++;
          dfs(i, j);
        }
      }
    }
    cout << cnt << endl;
}