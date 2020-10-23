#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 562 - Dividing Coins
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
 * Topics:  Dynamic Programming(DP), Top-down Approach
 *
 */

#define MAX_COINS  110
#define MAX_SUM 25010

using namespace std;

vector<int> bag;
int DP[MAX_COINS][MAX_SUM], m, coins_sum;

int dp(int idx, int total){
  if(DP[idx][total] != -1)
    return DP[idx][total];

  if(idx == m)
    return total;

  if(coins_sum / 2 < total + bag[idx])
    return dp(idx+1, total);

  return DP[idx][total] = max(dp(idx+1, total + bag[idx]), dp(idx+1, total));
}

int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int n, coin, one_person_max;

  cin >> n;

  while(n--){
    cin >> m;

    bag.clear();
    coins_sum = 0;
    for(int i = 0; i < m; i++){
      cin >> coin;
      coins_sum += coin;
      bag.push_back(coin);
    }

    memset(DP, -1, sizeof DP);

    one_person_max = dp(0, 0);

    cout << abs(one_person_max - (coins_sum - one_person_max)) << endl;
  }

  return 0;
}
