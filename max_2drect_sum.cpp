#include <bits/stdc++.h>
using namespace std;
 
#define int long long
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1 << 29;

const int MAX_N = 1000 + 10;
int a[MAX_N][MAX_N];

int32_t main(){
  int Q; cin >> Q;
  while (Q--){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cin >> a[i][j];
        if (i > 0) a[i][j] += a[i - 1][j];
        if (j > 0) a[i][j] += a[i][j - 1];
        if (i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
      }
    }
    int mx = -INF;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        for (int l = i; l < n; l++){
          for (int r = j; r < m; r++){
            int ret = a[l][r];
            if (i > 0) ret -= a[i - 1][r];
            if (j > 0) ret -= a[l][j - 1];
            if (i > 0 && j > 0) ret += a[i - 1][j - 1];
            mx = max(mx, ret);
          }
        }
      }
    }
    cout << mx <<  endl;
  }
}