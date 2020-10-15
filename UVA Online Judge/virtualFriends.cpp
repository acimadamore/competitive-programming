#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 11503 - Virtual Friends
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498
 * Topics:  Union-Find Disjoint Sets(UFDS)
 *
 */

using namespace std;

#define MAX_FRIENDS 100010

struct UFDS {
  vector<int> p, sizes;

  UFDS(int size){
    p.clear();
    sizes.clear();

    for(int i = 0; i < size; i++){
      p.push_back(i);
      sizes.push_back(1);
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

      if(sizes[x] > sizes[y]){
        p[y] = x;
        sizes[x] += sizes[y];
      }
      else{
        p[x] = y;
        sizes[y] += sizes[x];
      }
    }

  }

  int size_of_set(int i){
    return sizes[i];
  }

};

int main(){
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int tc, F, uid_f1, uid_f2, uid;
  string f1, f2;

  cin >> tc;

  while(tc--){
    cin >> F;

    uid = 0;
    UFDS friendships(MAX_FRIENDS);
    map<string, int> people;

    while(F--){
      cin >> f1 >> f2;

      if(people.find(f1) == people.end()){
        people[f1] = uid++;
      }

      if(people.find(f2) == people.end()){
        people[f2] = uid++;
      }

      uid_f1 = people[f1];
      uid_f2 = people[f2];

      friendships.union_set(uid_f1, uid_f2);

      cout << friendships.size_of_set(friendships.find_set(uid_f1)) << endl;
    }
  }

  return 0;
}
