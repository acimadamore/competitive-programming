#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 10583 - Ubiquitous Religion
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1524
 * Topics:  Union-Find Disjoint Sets(UFDS)
 *
 */

using namespace std;

struct UFDS {
  vector<int> p, rank;

  UFDS(int size){
    p.clear();
    rank.clear();

    for(int i = 0; i < size; i++){
      p.push_back(i);
      rank.push_back(0);
    }
  }

  int find_set(int i){
    return (i == p[i]) ? i : (p[i] = find_set(p[i]));
  }

  bool is_same_set(int i, int j){
    return find_set(i) == find_set(j);
  }

  void union_set(int i, int j){
    if(!is_same_set(i, j)){
      int x = find_set(i);
      int y = find_set(j);

      if(rank[x] > rank[y]){
        p[y] = x;
      }
      else{
        p[x] = y;

        if(rank[x] == rank[y]) rank[y]++;
      }
    }

  }

  int count_sets(){
    int sets = 0;

    for(int i = 0; i < p.size(); i++)
      if(p[i] == i)
        sets++;

    return sets;
  }

};

int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int n, m, i, j, tc = 1;

  cin >> n >> m;

  while(n + m){

    UFDS students(n);

    while(m--){
      cin >> i >> j;
      students.union_set(i, j);
    }

    cout << "Case " << tc << ": " << students.count_sets() << endl;

    tc++;
    cin >> n >> m;
  }

  return 0;
}
