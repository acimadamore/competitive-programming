#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 280 - Vertex
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=216
 * Topics:  Graphs, Reachability, Depth-first Search(DFS), Breadth-first Search(BFS)
 *
 */

using namespace std;

#define MAX_V 110

bool g[MAX_V][MAX_V], v[MAX_V];
int n;

void bfs(int start){
  queue<int> q;

  memset(v, 0, sizeof v);

  q.push(start);

  while(!q.empty()){
    int vertex = q.front();
    q.pop();

    for(int i = 1; i <= n; i++){
      if(g[vertex][i] && !v[i]){
        q.push(i);
        v[i] = true;
      }
    }
  }
}

void _dfs(int start){
  v[start] = true;

  for(int i=1; i <= n; i++)
    if(g[start][i] && !v[i])
      _dfs(i);
}

void dfs(int start){
  memset(v, 0, sizeof v);

  for(int i = 1; i <= n; i++)
    if(g[start][i] && !v[i])
      _dfs(i);
}

int main(){

  int nq, q, start_v, dest_v, not_v;
  string s;

  while(scanf("%d", &n), n){

    memset(g, 0, sizeof g);

    while(scanf("%d", &start_v), start_v)
      while(scanf("%d", &dest_v), dest_v)
        g[start_v][dest_v] = true;

    scanf("%d", &nq);

    while(nq--){
      scanf("%d", &q);

      // dfs(q);
      bfs(q);

      not_v = 0;
      for(int i=1; i <= n; i++)
        if(!v[i])
          not_v++;

      printf("%d", not_v);

      for(int i=1; i <= n; i++)
        if(!v[i])
          printf(" %d", i);

      printf("\n");
    }

  }

  return 0;
}
