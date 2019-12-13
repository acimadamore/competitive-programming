#include <bits/stdc++.h>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   URI Online Judge
 * Problem: Canteen Queue
 * URL:     https://www.urionlinejudge.com.br/judge/en/problems/view/1548
 * Topics:  Ad hoc, Easy peasy
 *
 */

using namespace std;

vector<int> grades;
priority_queue<int> order;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, grade, changes;

  cin >> n;

  while(n--){
    cin >> m;

    changes = 0;
    grades.clear();


    for(int i = 0; i < m; i++){
      cin >> grade;
      grades.push_back(grade);
      order.push(grade);
    }

    for(int i = 0; i < m; i++){
      if(grades[i] == order.top()){
        changes++;
      }

      order.pop();
    }

    cout << changes << endl;
  }

  return 0;
}
