#include <bits/stdc++.h>

/*
 * Author: Andrés Cimadamore(@acimadamore)
 * Judge: CodeChef
 * Problem: SPIDY2 - Spiderman and Jumping
 * URL: https://www.codechef.com/problems/SPIDY2
 * Topics: Dynamic Programming(DP), Top-down approach, Bottom-up approach
 *
 */

using namespace std;

#define MAX_N 200010

typedef long long unsigned llu;

llu dp[MAX_N], b[MAX_N];
int n;

llu absdiff(llu a, llu b){
  return (a < b) ? (b-a) : (a-b);
}


// Top-down solution
llu spidermanTD(int idx){
  if(idx == n) return 0;

  if(dp[idx] != -1) return dp[idx];

  dp[idx] = ULONG_MAX;

  for(int i=1; i + idx <= n; i*=2)
    dp[idx] = min(dp[idx], absdiff(b[i + idx], b[idx]) + spidermanTD(i + idx));

  return dp[idx];
}

// Bottom-up solution
llu spidermanBU(){
  dp[1] = 0;

  for(int i = 2; i <= n; i++){
    dp[i] = ULONG_MAX;

    for(int j = 1; i - j >= 1; j *=2)
      dp[i] = min(dp[i], dp[i - j] + absdiff(b[i - j], b[i]));
  }

  return dp[n];
}

int main(){
  scanf("%d", &n);
  for(int i=1; i <= n; i++)
    scanf("%llu", &b[i]);

  memset(dp, -1, sizeof dp);

  printf("%llu\n", spidermanBU());
  // printf("%llu\n", spidermanTD(1));

  return 0;
}
