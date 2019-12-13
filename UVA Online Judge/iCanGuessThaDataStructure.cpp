#include <iostream>
#include <stack>
#include <queue>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 11995 - I Can Guess the Data Structure!
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
 * Topics:  Ad Hoc, 
 *
 */

using namespace std;

int main(){

  int n, c, x;

  bool is_q, is_s, is_pq;

  while(cin >> n){

    is_q = is_s = is_pq = true;

    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    for(; n > 0; n--){

      cin >> c >> x;

      if(c == 1){
        q.push(x);
        s.push(x);
        pq.push(x);
      }
      else{
        if(q.empty()){
          is_q = is_s = is_pq = false;
        }
        else{
          is_q  = (q.front() == x) && is_q;
          is_s  = (s.top()   == x) && is_s;
          is_pq = (pq.top()  == x) && is_pq;

          q.pop();
          s.pop();
          pq.pop();
        }
      }
    }

    if(!is_s && !is_q && !is_pq){
      cout << "impossible" << endl;
    }
    else{
      if((is_s && is_q) || (is_s && is_pq) || (is_q && is_pq)){
        cout << "not sure" << endl;
      }
      else{
        if(is_s)  cout << "stack" << endl;

        if(is_q)  cout << "queue" << endl;

        if(is_pq) cout << "priority queue" << endl;
      }
    }
  }

  return 0;
}
