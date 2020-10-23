#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 627 - The Net
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=568
 * Topics:  Graphs, Shortest Path, Unweighted Graph, Breadth-First Search(BFS)
 *
 */

using namespace std;

#define MAX_ROUTERS 310

int routers[MAX_ROUTERS][MAX_ROUTERS], path[MAX_ROUTERS], n, m;
string l;
char * parsed_r;
char * parsed_adj;

bool bfs(int v_orig, int v_dest){
  bool visited[MAX_ROUTERS];
  queue<int> q;

  memset(path, -1, sizeof path);
  memset(visited, 0, sizeof visited);

  visited[v_orig] = true;
  q.push(v_orig);

  while(!q.empty()){
    int v = q.front();

    q.pop();

    for(int i=0; i <= n; i++){
      if(routers[v][i] && !visited[i]){
        visited[i] = true;
        path[i]    = v;
        if(i == v_dest){
          return true;
        }
        else{
          q.push(i);
        }
      }
    }
  }

  return false;
}

string path_to_string(int v){
  stringstream ss;
  ss << v;

  if(path[v] != -1){
    return path_to_string(path[v]) + " " + ss.str();
  }

  return ss.str();
}

int main(){

  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int v_orig, v_dest;

  while(cin >> n){

    memset(routers, 0, sizeof routers);

    cin.ignore();

    for(int i = 0; i < n; i++){
      getline(cin, l);

      char la[l.length()+1];

      strcpy(la, l.c_str());

      parsed_r = strtok(la, "-");

      parsed_adj = strtok(NULL, ",");

      while(parsed_adj != NULL){
        routers[atoi(parsed_r)][atoi(parsed_adj)] = 1;
        parsed_adj = strtok(NULL, ",");
      }
    }

    cout << "-----" << endl;

    cin >> m;

    for(int i = 0; i < m; i++){
      cin >> v_orig >> v_dest;

      if(bfs(v_orig, v_dest)){
        cout << path_to_string(v_dest) << endl;
      }
      else{
        cout << "connection impossible" << endl;
      }
    }
  }

  return 0;
}
