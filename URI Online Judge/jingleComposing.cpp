#include <bits/stdc++.h>

/*
 * Author: Andrés Cimadamore(@acimadamore)
 * Judge: URI Online Judge
 * Problem: Jingle Composing
 * URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1430
 * Topics: Ad-hoc, Easy AF
 *
 */

using namespace std;

#define CORRECT_DURATION 64

map<char, int> notes = {{'W', 64}, {'H', 32}, {'Q', 16}, {'E', 8}, {'S', 4}, {'T', 2}, {'X', 1}};

int main(){

  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  string line;
  int measure, right_measures;

  getline(cin, line);

  while(line != "*"){

    right_measures = measure = 0;

    for(string::iterator it = line.begin(); it != line.end(); it++){
      if((*it) == '/') {
        if(measure == CORRECT_DURATION){
          right_measures++;
        }
        measure = 0;
      }
      else{
        measure += notes[(*it)];
      }
    }

    cout << right_measures << endl;

    getline(cin, line);
  }

  return 0;
}
