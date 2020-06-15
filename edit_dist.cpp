#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1 << 29;
const int N =  1e4 + 10;
const int LG = 20;
 
struct IOsetup{
  IOsetup(){
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   cout << fixed << setprecision(8);
  }
}IO;

// edit distance problem
const int MAX_N = 5e3 + 10;
int dp[MAX_N][MAX_N];

int32_t main(){
  string s, t;
  cin >> s >> t;
  for (int i = 0; i <= (int)s.size(); i++){
    for (int j = 0; j <= (int)t.size(); j++){
      if (min(i, j) == 0){
        dp[i][j] = max(i, j);
        continue;
      }
      if (s[i - 1] == t[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else 
        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    }
  }
  cout << dp[(int)s.size()][(int)t.size()] << endl;
}