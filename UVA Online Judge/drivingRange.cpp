#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 11857 - Driving Range
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2957
 * Topics:  Graphs, 
 *
 */


using namespace std;

#define MAX 1000001


struct edge {
  int c1, c2, dist;

  edge(int a, int b, int distance){
    c1   = a;
    c2   = b;
    dist = distance;
  }
};

int edgeComparator(edge e1, edge e2){
  return e1.dist < e2.dist;
}

int p[MAX];
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

int kruskal(){
  int u, v, maxEdge = -1;

  sort(edges.begin(), edges.end(), edgeComparator);

  for(int i = 0; i < edges.size(); i++){
    if(union_set(edges[i].c1, edges[i].c2))
      maxEdge = edges[i].dist;
  }

  return maxEdge;
}

void reset(int n){
  edges.clear();

  for(int i = 0; i <= n; i++)
    p[i] = i;
}

bool cities_are_connected(int n){
  int sets = 0;
  for(int i = 0; i < n; i++){
    if(p[i] == i){ 

      sets++;

      if(sets > 1)
        return false;
    }
  }

  return true;
}


int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int cities, roads, city_1, city_2, distance, maxRange;

  cin >> cities >> roads;

  while(cities || roads){

    reset(cities);

    for(int i=0; i < roads; i++){
      cin >> city_1 >> city_2 >> distance;
      edges.push_back(edge(city_1, city_2, distance));
    }

    maxRange = kruskal();

    if(maxRange != -1 && cities_are_connected(cities)){
      cout << maxRange << endl;
    }
    else{
      cout << "IMPOSSIBLE" << endl;
    }

    cin >> cities >> roads;
  }

  return 0;
}
