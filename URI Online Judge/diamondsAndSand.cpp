#include <bits/stdc++.h>

/*
 * Author: Andrés Cimadamore(@acimadamore)
 * Judge: URI Online Judge
 * Problem: Diamonds and Sand
 * URL: https://www.urionlinejudge.com.br/judge/en/problems/view/1069
 * Topics: Ad Hoc, EasyAF
 *
 */

using namespace std;


int main(){
 
  #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #else
    freopen("input", "r", stdin);
  #endif

  int n;

  cin >> n;
  cin.ignore();

  while(n--){
    int diamonds = 0, lside = 0;
    string mine;

    getline(cin, mine);

    for(int i = 0; i < mine.size(); i++){
      if(mine[i] == '<') {
        lside++;
      }
      else if(mine[i] == '>' && lside){
        diamonds++;
        lside--;
      }
    }

    cout << diamonds << endl;
  }

  return 0;
}
