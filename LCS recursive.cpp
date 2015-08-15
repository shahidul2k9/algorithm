/* A Naive recursive implementation of LCS problem */
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<iostream>
#define MAX_X_LEN 60
#define MAX_y_LEN 60
#define NIL -1
using namespace std;
int l[MAX_X_LEN][MAX_y_LEN];
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
string x,y;
int lcs( int m, int n )
{
   if(l[m][n]!=NIL)return l[m][n];
   else if (m == 0 || n == 0)
     return l[m][n]=0;
   if(x[m-1] == y[n-1])
     return l[m][n]=1 + lcs(m-1, n-1);
   else
     return max(l[m][n-1]=lcs(m, n-1), l[m-1][n]=lcs(m-1, n));
}


void traceback(int i, int j){

 if(i == 0|| j == 0)return;

 if(x[i-1] == y[j-1]) {
     traceback(i-1, j-1);
     cout << x[i-1];
 }
 else if(l[i-1][j] > l[i][j-1])
     traceback(i-1, j);
 else traceback(i, j-1);
}
int main()
{
  x = "AGGTAB";
  y = "GXTXAYB";

  int m = x.length();
  int n = y.length();
  memset(l,NIL,sizeof(l));
  printf("Length of LCS is %d\n", lcs(m, n ) );
    traceback(m, n);
  return 0;
}
