#include <iostream>
#include <set>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 11849 - CD
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2949
 * Topics:  Ad Hoc, Set, EasyAF
 *
 */

using namespace std;

typedef unsigned long long ull;

int main(){

  ull n, m, cd, sellables;

  set<ull> s;

  cin >> n >> m;

  while(n != 0 || m != 0){

    sellables = 0;

   for(int i=0; i < n+m; i++){
      cin >> cd;

      if(s.find(cd) == s.end()){
        s.insert(cd);
      }
      else{
        sellables++;
      }
    }

    cout << sellables << endl;

    s.clear();

    cin >> n >> m;
  }

  return 0;
}
