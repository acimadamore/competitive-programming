#include <bits/stdc++.h>

/*
 * Author: Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 12455 - Bars
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886
 * Topics:  Dynamic Programming, Top-Down Approach
 *
 */

using namespace std;

#define MAX_BARS     30
#define MAX_LENGTH 1010

int bars[MAX_BARS], DP[MAX_BARS][MAX_LENGTH];

bool dp(int i, int p, int bar_length){
  if(DP[i][bar_length] != -1) return DP[i][bar_length];

  if(i == p || bar_length == 0)
    return DP[i][bar_length] = (bar_length == 0);

  return DP[i][bar_length] =  dp(i+1, p, bar_length) || (bars[i] <= bar_length && dp(i+1, p, bar_length - bars[i]));
}

int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int t, bar_length, p;

  cin >> t;

  while(t--){
    cin >> bar_length >> p;

    for(int i=0; i < p; i++)
      cin >> bars[i];

    memset(DP, -1, sizeof DP);

    cout << (dp(0, p, bar_length) ? "YES" : "NO") << endl;
  }

  return 0;
}
