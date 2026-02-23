#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;

/*int finv[N];
void prec() { //linear inverse trick 
  f[0] = 1;
  for (int i = 1; i < N; i++) f[i] = 1LL * i * f[i - 1] % mod;
  inv[1] = 1;
  for (int i = 2; i < N; i++ ) {
    inv[i] = (-(1LL * mod / i) * inv[mod % i] ) % mod;
    inv[i] = (inv[i] + mod) % mod;
  }
  finv[0] = 1;
  for (int i = 1; i < N; i++) finv[i] = 1LL * inv[i] * finv[i - 1] % mod;
}*/

// void brute() { //brute force pascal triangle
//  for (int i = 0; i < N; i++) {
//    C[i][0] = 1;
//  }
//  for (int i = 1; i < N; i++) {
//    for (int j = 1; j <= i; j++) {
//      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
//    }
//  }
// }

int f[N], inv[N];
int pw(int a, int b){
  int res = 1;
  while(b){
    if(b&1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res; 
}
void prec(){
  f[0] = 1;
  for(int i = 1; i < N; i++) f[i] = i * f[i-1] % mod;
  inv[N-1] = pw(f[N-1], mod-2);
  for(int i = N-2; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % mod;
}
int ncr(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  return f[n] * inv[n - r] % mod * inv[r] % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  int q; cin >> q;
  while (q--) {
    int n, r; cin >> n >> r;
    cout << ncr(n, r) << '\n';
  }
  return 0;
}
// https://cses.fi/problemset/task/1079/
