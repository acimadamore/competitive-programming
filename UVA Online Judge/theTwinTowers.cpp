#include <bits/stdc++.h>

/*
 * Author: Andrés Cimadamore(@acimadamore)
 * Judge: Online Judge(Former UVA Online Judge)
 * Problem: 10066 - The Twin Towers
 * URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1007
 * Topics: Dynamic Programming(DP), Longest Common Subsequence(LCS), Bottom-up Approach
 *
 */

using namespace std;

int LCS(vector<int> tower_1, vector<int> tower_2) {
  int i, j, n = tower_1.size() + 1, m = tower_2.size() + 1, PD[n][m];

  for(i = 0; i < n; i++) PD[i][0] = 0;
  for(j = 0; j < m; j++) PD[0][j] = 0;

  for(i = 1; i < n; i++)
    for(j = 1; j < m; j++)
      if(tower_1[i-1] == tower_2[j-1])
        PD[i][j] = PD[i-1][j-1] + 1;
      else
        PD[i][j] = max(PD[i-1][j], PD[i][j-1]);

  return PD[n-1][m-1];
}

int main(){

  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int N1, N2, tile, tc = 1;

  cin >> N1 >> N2;

  while (N1 && N2) {

    vector<int> tower_1, tower_2;

    for(int i=0; i < N1; i++){
      cin >> tile;
      tower_1.push_back(tile);
    }

    for(int i=0; i < N2; i++){
      cin >> tile;
      tower_2.push_back(tile);
    }

    cout << "Twin Towers #" << tc++ << endl;
    cout << "Number of Tiles : " << LCS(tower_1, tower_2) << endl;
    cout << endl;

    cin >> N1 >> N2;
  }

  return 0;
}
