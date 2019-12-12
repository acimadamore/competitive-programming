#include <iostream>
#include <cstdlib>
#include <cstring>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 10038 - Jolly Jumpers
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979
 * Topics:  Ad Hoc, EasyAF
 *
 */

using namespace std;

#define MAX_N 3500

int main(){
  int  n, prev, act, diff, matched;
  bool sequence[MAX_N];

  while(cin >> n){

    matched = 0;

    memset(sequence, false, sizeof sequence);

     cin >> prev;

    for (int i = 1; i < n; i++){
      cin >> act;

      diff = abs(prev - act);

      if(diff < n && diff != 0 && !sequence[diff]){
        matched++;
        sequence[diff] = true;
      }

      prev = act;
    }

    cout << ((matched == n-1) ? "Jolly" : "Not jolly") << endl;
  }
}
