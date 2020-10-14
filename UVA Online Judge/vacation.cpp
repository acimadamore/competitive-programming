#include <bits/stdc++.h>

/*
 * Author: Andrés Cimadamore(@acimadamore)
 * Judge: Online Judge(Former UVA Online Judge)
 * Problem: 10192 - Vacation
 * URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1133
 * Topics: Dynamic Programming, Bottom-up approach, Longes Common Subsequence(LCS)
 *
 */

using namespace std;

int LCS(string s, string t){
  int n = s.length() + 1, m = t.length() + 1, memo[n][m];

  for(int i = 0; i < n; i++) memo[i][0] = 0;
  for(int j = 0; j < m; j++) memo[0][j] = 0;

  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++){
      if(s[i-1] == t[j-1])
        memo[i][j] = memo[i-1][j-1] + 1;
      else
        memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
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

  string travel_sequence_1, travel_sequence_2;
  int case_number = 1;

  getline(cin, travel_sequence_1);

  while(travel_sequence_1 != "#"){
    getline(cin, travel_sequence_2);

    cout << "Case #" << case_number << ": you can visit at most " << LCS(travel_sequence_1, travel_sequence_2) << " cities." << endl;

    case_number++;

    getline(cin, travel_sequence_1);
  }

  return 0;
}
