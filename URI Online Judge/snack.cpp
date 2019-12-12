/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   URI Online Judge
 * Problem: 1038 - snack
 * URL:     https://www.urionlinejudge.com.br/judge/en/problems/view/1038
 * Topics:  Ad hoc, EasyAF
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  float prices[] = { 0.00, 4.00, 4.50, 5.00, 2.00, 1.50 };

  int x, y;

  cin >> x >> y;

  cout << "Total: R$ " << fixed << setprecision(2) << prices[x] * y << endl;

  return 0;
}

