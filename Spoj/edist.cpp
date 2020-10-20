#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Sphere Online Judge(SPOJ)
 * Problem: EDIST - Edit distance
 * URL:     https://www.spoj.com/problems/EDIST/
 * Topics:  Dynamic Programming(DP), Edit Distance(ED), Bottom-up approach
 *
 */

#define INF 1000000000

using namespace std;

int ED(string s, string t, int cost_delete, int cost_insert, int cost_replace){
  int n = s.length() + 1, m = t.length() + 1, memo[n][m];

  for(int i = 0; i < n; i++) memo[i][0] = i * cost_delete;
  for(int j = 0; j < m; j++) memo[0][j] = j * cost_insert;

  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++){
      memo[i][j] = memo[i-1][j-1];
      if(s[i-1] != t[j-1]){
        memo[i][j]+= cost_replace;
      }
      memo[i][j] = min(memo[i][j], memo[i-1][j] + cost_delete);
      memo[i][j] = min(memo[i][j], memo[i][j-1] + cost_insert);
    }
  }

  return memo[n-1][m-1];
}

int main(){
 
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int T;
  string a, b;

  cin >> T;

  while(T--){
    cin >> a >> b;
    cout << ED(a, b, 1, 1, 1) << endl;
  }
 
  return 0;
}
