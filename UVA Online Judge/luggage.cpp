#include <bits/stdc++.h>

/*
 * Author: Andrés Cimadamore(@acimadamore)
 * Judge: Online Judge(Former UVA Online Judge)
 * Problem: 10644 - Luggage
 * URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1605
 * Topics: Dynamic Programming(DP), Top down approach
 *
 */

using namespace std;

int DP[210][210];

bool dp(const vector<int> &suitcases, int idx, int car_1, int car_2){
  if(DP[car_1][car_2] != -1)
    return DP[car_1][car_2];

  if(idx == suitcases.size()) 
    return car_1 == car_2;

  return DP[car_1][car_2] = dp(suitcases, idx+1, car_1 + suitcases[idx], car_2)
                         || dp(suitcases, idx+1, car_1, car_2 + suitcases[idx]);
}

int main(){

  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int m, suitcase;
  vector<int> suitcases;
  string line;

  cin >> m;

  cin.ignore();

  while(m--){
    suitcases.clear();

    getline(cin, line);

    stringstream ss(line);

    while(ss >> suitcase){
      suitcases.push_back(suitcase);
    }

    memset(DP, -1, sizeof DP);

    cout << (dp(suitcases, 0, 0, 0) ? "YES" : "NO") << endl;
  }

  return 0;
}
