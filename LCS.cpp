#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define MAX 20+1
string x,y,z;
int c[MAX][MAX];
char t[MAX][MAX];
int m,n, length;
int LCS(){
    int i,j;
    for(i = 0; i<=m; i++)c[0][i] = 0;
    for(j = 0; j<=n; j++)c[j][0] = 0;

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            {
                if(x[i-1]==y[j-1]){
                    c[i][j] = c[i-1][j-1] + 1;
                    t[i][j] = '\\';
                }
                else if(c[i-1][j]>c[i][j-1])
                    {
                        t[i][j] = '|';
                        c[i][j] = c[i-1][j];
                    }
                else {
                    t[i][j] = '-';
                    c[i][j] = c[i][j-1];
                    }
            }

return c[m][n];
}
void printLCS(int i, int j){
    if(i==0||j==0)return;
    else if(t[i][j]=='\\')
        {
            printLCS(i-1,j-1);
            printf("%c",x[i-1]);
        }
    else if(t[i][j]=='|')printLCS(i-1,j);
    else printLCS(i,j-1);

}
int main() {
   while(cin >> x >> y){
       m = x.length();
       n = y.length();
       length = LCS();
       cout << length << endl;
       printLCS(m,n);
   }

    return 0;
}
