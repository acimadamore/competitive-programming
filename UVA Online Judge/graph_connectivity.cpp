#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 459 - Graph Connectivity
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
 * Topics:  Graphs, Maximal Subgraph, Union-Find Disjoint Sets(UFDS)
 *
 */

using namespace std;

vector<int> sets;
int v;

int find_set(int i){
  return (sets[i] == i) ? i : sets[i] = find_set(sets[i]);
}

void union_set(int i, int j){
  int U = find_set(i);
  int V = find_set(j);

  if (U != V)
    sets[U] = V;
}

int count_sets(){
  int total = 0;
  for(int i = 0; i < v; i++)
    if(sets[i] == i)
      total++;

  return total;
}

int main(){

  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int tc;
  char max_v;
  string edge;

  cin >> tc;

  while(tc--){
    sets.clear();

    cin >> max_v;
    cin.ignore();

    v = max_v - 'A' + 1;

    for(int i = 0; i < v; i++)
      sets.push_back(i);

    while(getline(cin, edge) && edge != "")
      union_set(edge[0] - 'A', edge[1] - 'A');

    cout << count_sets() << endl;

    if(tc)
      cout << endl;
  }

  return 0;
}
