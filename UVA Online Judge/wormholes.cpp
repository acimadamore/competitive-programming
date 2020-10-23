#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 558 - Wormholes
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
 * Topics:  Graphs, Negative Cycles, Bellman–Ford
 *
 */

using namespace std;

#define MAX_STARSYSTEMS 1010

#define INF 1000000000

struct Edge{
  int x, y, t;
};

int n, m, x, y, t, dist[MAX_STARSYSTEMS];
vector<Edge> edges;


bool bellman_ford(){

  for(int i = 1; i < n; i++){
    dist[i] = INF;
  } 
  dist[0] = INF;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(dist[edges[j].y] > dist[edges[j].x] + edges[j].t)
        dist[edges[j].y] = dist[edges[j].x] + edges[j].t;

  for(int i = 0; i < m; i++)
    if(dist[edges[i].y] > dist[edges[i].x] + edges[i].t)
      return true;

  return false;
}

int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int cases;
  Edge e;

  cin >> cases;

  while(cases--){
    cin >> n >> m;

    for(int i=0; i < n; i++){
      edges.clear();
    }

    for(int i=0; i < m; i++){
      cin >> e.x >> e.y >> e.t;
      edges.push_back(e);
    }

    cout << (bellman_ford() ? "possible" : "not possible") << endl;
  }

  return 0;
}
