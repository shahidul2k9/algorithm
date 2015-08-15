#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > ii;

#define MAX  5000
#define WHITE 0
#define GRAY 1
#define MAX  5000

vector < int > g[MAX +1 ];
int E[2*MAX], H[MAX + 1], L[2*MAX];
int M[ MAX+1 ][13];
bool color[MAX+1];
int N, Q, t;

void dfs(int from, int depth){

    int to;
    for(int i = 0; i < g[from].size(); i++){
    to = g[from][i];
        if(color[to] == WHITE){
            color[to] = GRAY;

            t++;
            H[to] = t;
            E[t] = to;
            L[t] = depth + 1;
            dfs(to, depth +1 );
        }

            t++;
            E[t] = from;
            L[t] = depth;




    }

}

int main() {

    //freopen("input.txt", "r", stdin);
    int st, en, test, lca, ans, ind;

    while(scanf("%d", &N) && N){

        for(int  i = 1; i < N; i++){
                scanf("%d %d", &st, &en);
        if(st < en)
            g[st].push_back(en);
        else
            g[en].push_back(st);

        }

    {
    t = 1;
    E[1] = 1;
    H[1] = 1;
    L[1] = 0;
    memset(color, WHITE, sizeof color);
    }

    dfs(1, 0);
    int sz = (N << 1) - 1;
    for(int i = 1; i <= sz; i++)
        M[i][0] = i;

    for(int j = 1; (1 << j) < sz; j++)
        for(int i = 1; i + (j << 1) <= sz ; i++){
            if(L[ M[i][j-1] ] < L[ M[ i + ( 1 << (j-1) )][j-1] ]) M[i][j] = M[i][j-1];
            else M[i][j] = M[i + ( 1 << (j -1))][j-1];
        }

    scanf("%d", &Q);
    while(Q--){
        scanf("%d %d", &st, &en);
        int i = H[st];
        int j = H[en];
        if(i > j) swap(i, j);
        int k = (int)log2(j - i + 1);
        if(L[ M[i][k] ] <= L[ M[j - (1 << k) + 1][k] ]) ind = M[i][k];
        else ind = M[j -  (1 << k) + 1][k];
        printf("%d\n", E[ind]);
    }
    for(int i = 1; i <= N; i++)g[i].clear();
    }

	return 0;
}
