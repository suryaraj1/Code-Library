#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int sz = 2;

int add(int a, int b){
  a += b; 
  if (a >= MOD)
  	a -= MOD;
  return a;
}

int mul(int a, int b){
  return (a * 1ll * b) % MOD;
}

struct matrix{
  int a[sz][sz];
  void reset(){
  	memset(a, 0, sizeof a);
  }
  void makeIden(){
   reset();
   for (int i = 0; i < sz; i++)
   	for (int j = 0; j < sz; j++)
   		a[i][j] = i == j;
  }
  matrix operator + (const matrix &other) const{
  	matrix ret;
  	for (int i = 0; i < sz; i++){
  	  for (int j = 0; j < sz; j++){
  	  	ret.a[i][j] = add(a[i][j], other.a[i][j]);
  	  }
  	}
  	return ret;
  }
  matrix operator * (const matrix &other) const{
  	matrix ret;
  	for (int i = 0; i < sz; i++){
  	  for (int j = 0; j < sz; j++){
  	  	ret.a[i][j] = 0;
  	  	for (int k = 0; k < sz; k++){
  	  	  ret.a[i][j] = add(ret.a[i][j], mul(a[i][k], other.a[k][j]));
  	  	}
  	  }
  	}
  	return ret;
  }
};

matrix power(matrix a, int b){
  matrix ret;
  ret.makeIden();
  while (b){
   if (b & 1) ret = ret * a;
   a = a * a, b >>= 1;
  }
  return ret;
}

int32_t main(){
  int n; cin >> n;
  if (n == 0){
    cout << 0 << endl;
    exit(0);
  }
  matrix trans;
  trans.reset();
  trans.a[0][0] = 1, trans.a[0][1] = 1;
  trans.a[1][0] = 1, trans.a[1][1] = 0;
  matrix base;
  trans = power(trans, n - 1);
  base.a[0][0] = 1;
  base.a[1][0] = 0;
  matrix ret = trans * base;
  cout << ret.a[0][0] << endl;
}