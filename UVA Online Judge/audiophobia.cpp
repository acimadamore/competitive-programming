#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 10048 - Audiophobia
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989
 * Topics:  Graphs, Minimum Spanning Tree(MST), Kruskal, Union-Find Disjoint Sets(UFDS), Depth-first Search(DFS)
 *
 */

using namespace std;

#define MAX_CROSSINGS 110

struct edge {
  int c1, c2, d;

  edge(int a, int b, int de){
    c1 = a;
    c2 = b;
    d  = de;
  }
};

int edgeComparator(edge e1, edge e2){
  return e1.d < e2.d;
}

int p[MAX_CROSSINGS], mst[MAX_CROSSINGS][MAX_CROSSINGS], dfs_v[MAX_CROSSINGS];
vector<edge> edges;

int find_set(int i){
  return (i == p[i]) ? i : (p[i] = find_set(p[i]));
}

bool union_set(int i, int j){
  int u = find_set(i);
  int v = find_set(j);

  if(u != v){
    p[u] = v;

    return true;
  }

  return false;
}

void kruskal(){
  int u, v;

  sort(edges.begin(), edges.end(), edgeComparator);

  for(int i = 0; i < edges.size(); i++){

    if(union_set(edges[i].c1, edges[i].c2)){
      mst[edges[i].c1][edges[i].c2] = mst[edges[i].c2][edges[i].c1] = edges[i].d;
    }
  }
}

int dfs(int c1, int c2, int n){
  int dfs_r, maxDecibels = -1;

  dfs_v[c1] = 1;

  for(int i = 0; i <= n; i++){
    if(mst[c1][i] && !dfs_v[i]){
      if(i == c2){
        return mst[c1][c2];
      }
      else{
        dfs_r = dfs(i, c2, n);
        if(dfs_r != -1)
          maxDecibels = max(maxDecibels, max(dfs_r, mst[c1][i]));
      }
    }
  }


  return maxDecibels;
}

void reset(int n){
  edges.clear();

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      mst[i][j] = 0;
    }

    p[i] = i;
  }
}

int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int c, s, q, c1, c2, d, query_result, tc = 0;

  cin >> c >> s >> q;

  while(c && s && q){

    reset(c);

    for(int i = 0; i < s; i++){
      cin >> c1 >> c2 >> d;
      edges.push_back(edge(c1, c2, d));
    }

    kruskal();

    if(tc)
      cout << endl;

    cout << "Case #" << ++tc << endl;

    for(int i = 0; i < q; i++){
      cin >> c1 >> c2;

      memset(dfs_v, 0, sizeof(dfs_v));

      query_result = dfs(c1, c2, c);

      if(query_result != -1){
        cout << query_result << endl;
      }
      else{
        cout << "no path" << endl;
      }
    }

    cin >> c >> s >> q;
  }

  return 0;
}
