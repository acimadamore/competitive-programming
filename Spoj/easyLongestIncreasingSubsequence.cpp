#include <cstdio>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Sphere Online Judge(SPOJ)
 * Problem: ELIS - Easy Longest Increasing Subsequence
 * URL:     https://www.spoj.com/problems/ELIS/
 * Topics:  Dynamic Programming, Longest Increasing Subsequence(LIS), Bottom-Up approach
 * 
 */

using namespace std;

#define MAX_LENGTH 20

int A[MAX_LENGTH], PD[MAX_LENGTH], n;

int lis(){
  int maxLis = 0;

  for(int i = 0; i < n; i++){

    PD[i] = 1;

    for(int j = 0; j < i; j++)
      if(A[j] < A[i] && PD[i] < PD[j] + 1){
        PD[i] = PD[j] + 1;
      }
    }

    if(maxLis < PD[i]) maxLis = PD[i];
  }

  return maxLis;
}

int main(){
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  printf("%d\n", lis());
}
