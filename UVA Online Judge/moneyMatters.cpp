#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 11690 - Money Matters
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2737
 * Topics:  Union-Find Disjoint Sets(UFDS)
 *
 */

using namespace std;

typedef long long ll;

vector<int> friends_sets;
vector<ll> debts;
int tc, n, m, o, x, y;

int find_set(int i){
  return (friends_sets[i] == i) ? i : friends_sets[i] = find_set(friends_sets[i]);
}

void befriend(int i, int j){
  int U = find_set(i);
  int V = find_set(j);

  if (U != V){
    friends_sets[U] = V;
    debts[V] += debts[U];
  }
}
 
bool is_possible(){
  for(int i = 0; i < n; i++)
    if(friends_sets[i] == i && debts[i] > 0)
      return false;

  return true;
}

int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  cin >> tc;

  while(tc--){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
      cin >> o;

      friends_sets.push_back(i);
      debts.push_back(o);
    }

    for(int i = 0; i < m; i++){
      cin >> x >> y;

      befriend(x, y);
    }

    cout << (is_possible() ? "POSSIBLE" : "IMPOSSIBLE") << endl;

    friends_sets.clear();
    debts.clear();
  }

  return 0;
}
