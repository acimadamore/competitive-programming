#include <iostream>
#include <cstring>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   ICPC Live Archive
 * Problem: 7350 - ACM Contest Scoring
 * URL:     https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=717&page=show_problem&problem=5372
 * Topics:  Ad Hoc, EasyAF
 * 
 */

using namespace std;

#define MAX_PROBLEMS 100
#define PENALTY      20

typedef long long ll;

int main(){

  int    t, problems_solved, penalizations[MAX_PROBLEMS];
  ll     total_time;
  char   p;
  string r;

  bool solved[MAX_PROBLEMS];

  while(cin >> t){

    problems_solved = total_time = 0;
    memset(penalizations, 0, sizeof penalizations);
    memset(solved, false, sizeof solved);

    while(t != -1){
      cin >> p >> r;

      if(!solved[p]){
        if(r == "right"){
          total_time += t + penalizations[p];
          solved[p] = true;
          problems_solved++;
        }
        else{
          penalizations[p] += PENALTY;
        }
      }

      cin >> t;
    }

    cout << problems_solved << " " << total_time << endl;
  }

  return 0;
}
