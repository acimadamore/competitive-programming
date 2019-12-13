#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <string>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 497 - Strategic Defense Initiative
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=438
 * Topics:  Dynamic Programming(DP), Longest Common Subsequence(LIS), Bottom-up approach
 *
 */

using namespace std;


void print_path(vector<int> altitudes, vector<int> prev, int i){
  if(i != -1){
    print_path(altitudes, prev, prev[i]);
    printf("%d\n", altitudes[i]);
  }
}

int main(){
  int tc, altitude, maxHits, i, j;
  string line;

  cin >> tc;

  cin.ignore();
  cin.ignore();

  while(tc--){

    vector<int> altitudes;

    while(getline(cin, line) && line != ""){
      stringstream ss(line);

      ss >> altitude;

      altitudes.push_back(altitude);
    }

    vector<int> pd(altitudes.size(), 1);
    vector<int> prev(altitudes.size(), -1);

    maxHits = 0;

    for(i = 0; i < altitudes.size(); i++){
      for(j = 0; j < i; j++){
        if((altitudes[j] < altitudes[i]) && pd[i] < pd[j] + 1){
          pd[i]   = pd[j] + 1;
          prev[i] = j;
        }
      }

      if(pd[maxHits] < pd[i]) maxHits = i;
    }

    printf("Max hits: %d\n", pd[maxHits]);

    print_path(altitudes, prev, maxHits);

    if(tc) printf("\n");
  }


}
