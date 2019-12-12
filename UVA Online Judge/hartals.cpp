#include <iostream>
#include <cstring>
#include <cstdio>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 10050 - Hartals
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=991
 * Topics:  Ad Hoc, EasyAF
 * */

using namespace std;

#define MAX_DAYS 3700

int main(){

  int t, n, p, h, days[MAX_DAYS], working_days_losed;

  cin >> t;

  while(t--){
    memset(days, 0, sizeof(days));

    working_days_losed = 0;

    cin >> n >> p;

    for(int i = 6; i <= n; i+=7){
      days[i] = days[i+1] = 1;
    }

    while(p--){
      cin >> h;

      for(int i = h; i <= n; i+=h){
        if(!days[i]){
          working_days_losed++;
          days[i] = 1;
        }
      }

    }

    cout << working_days_losed << endl;
  }

  return 0;
}
