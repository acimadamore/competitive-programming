#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <tuple>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 10131 - Is Bigger Smarter?
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1072
 * Topics:  Dynamic Programming(DP), Longest Common Subsequence(LIS), Bottom-up Approach
 * Comment: Tuples are used to represent the elephants. Tuples are available since C++11, use g++ -std=c++11 <file.cpp> to compile
 *
 */

using namespace std;

#define MAX_ELEPHANTS 1010

//         weight, iq,  id
typedef tuple<int, int, int> elephant;

void print_elephants(vector<elephant> elephants, int prev[], int i){
  if(i != -1){
    print_elephants(elephants, prev, prev[i]);
    cout << get<2>(elephants[i]) << endl;
  }
}

int main(){
  int pd[MAX_ELEPHANTS], prev[MAX_ELEPHANTS], weight, iq, id = 0, lis = 0;
  vector<elephant> elephants;

  while(cin >> weight >> iq){
    elephants.push_back(elephant(weight, iq, ++id));
  }

  sort(elephants.begin(), elephants.end());  

  memset(prev, -1, sizeof prev);

  for(int i = 0; i < elephants.size(); i++){
    pd[i] = 1;
    for(int j=0; j < i; j++){
      if(get<1>(elephants[i]) < get<1>(elephants[j]) && pd[i] < pd[j] + 1){
        pd[i]   = pd[j] + 1;
        prev[i] = j;
      }
    }

    if(pd[lis] < pd[i]) lis = i; 
  }

  cout << pd[lis] << endl;
  print_elephants(elephants, prev, lis);

  return 0;
}
