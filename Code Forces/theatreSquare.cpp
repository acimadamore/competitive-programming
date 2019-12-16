#include<iostream>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Code Forces
 * Problem: 1A - Theatre Square
 * URL:     codeforces.com/blog/entry/19700
 * Topics:  Ad hoc, EasyAF
 *
 */

using namespace std;

typedef unsigned long long ull;

int main(){

  ull n, m, a;

  cin >> n >> m >> a;

  n = (n % a == 0) ? n/a : (n/a)+1;
  m = (m % a == 0) ? m/a : (m/a)+1;

  cout << n*m << endl;

  return 0;
}
