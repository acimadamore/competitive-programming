#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 484 - The Department of Redundancy Department
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=425
 * Topics:  Ad hoc, EasyAF
 *
 */

using namespace std;

int main(){

  map<int, int> occurrences;
  vector<int> order;
  int n;

  while(cin >> n){

    occurrences[n]++;

    if (occurrences[n] == 1){
      order.push_back(n);
    }

    cin >> n;
  }

  for(vector<int>::iterator i = order.begin(); i < order.end(); i++){
    cout << (*i) << " " << occurrences[(*i)] << endl;
  }

  return 0;
}
