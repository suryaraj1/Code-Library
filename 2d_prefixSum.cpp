#include <bits/stdc++.h>
using namespace std;
 
#define int long long
using pii = pair<int, int>;
const int MOD = 1e9 + 7;

const int MAX_N = 100 + 10;
int a[MAX_N][MAX_N];

// 2 D prefix sum

int32_t main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
     cin >> a[i][j];
     if (i > 0) a[i][j] += a[i - 1][j];
     if (j > 0) a[i][j] += a[i][j -1];
     if (i  && j > 0) a[i][j] -= a[i - 1][j - 1];
    }
  }
  // for submatrix sum query
  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;
  int ret = a[l2][r2];
  if (l1 > 0) ret -= a[l1 - 1][r2];
  if (r1 > 0) ret -= a[l2][r1 - 1];
  if (l1 > 0 && r1 > 0) ret += a[l1 - 1][r1 - 1];
  cout << ret << endl;
}