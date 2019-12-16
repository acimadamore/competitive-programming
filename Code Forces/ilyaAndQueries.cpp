#include <cstdio>
#include <cstring>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Code Forces
 * Problem: 313B - Ilya and Queries
 * URL:     codeforces.com/problemset/problem/313/B
 * Topics:  Dynamic Programming(DP), Range Sum Query(RSQ)
 * */

using namespace std;

#define LIMIT 100010

int main(){
  char s[LIMIT];
  int  sum[LIMIT], queries, l, r, s_length, a = 0;

  scanf("%s", s);
  s_length = strlen(s);

  sum[0] = 0;

  for(int i=0; i < s_length; i++){
    sum[i+1] = (s[i] == s[i+1]) ? ++a : a;
  }

  scanf("%d", &queries);

  while(queries--){
    scanf("%d %d", &l, &r);
    printf("%d\n", (sum[r-1] - sum[l-1]));
  }

  return 0;
}
