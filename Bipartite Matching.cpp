#include <cstdio>
#include <string.h>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXN 300      /* How many vertices in U+V (in total) */
#define N 300
#define EPS 1e-9
#define SQR(x) ((x)*(x))

int r [MAXN][MAXN];      /* MODIFIED Adj. matrix (see note) */
int parent[MAXN];
int cost[MAXN];
int match[MAXN];
int nodes,edges,s,t,m,n;



void addEdge(int x, int y){
//  r[x][y+n] = r[y+n][x] = 1;
r[x][y+n] = 1;
}

bool bfs(){

    queue<int> q;
    for(int i=0;i<nodes;i++)parent[i]=-1;
    cost[s] = INT_MAX;
    parent[s] = s;
    q.push(s);
    while (!q.empty()) {
    int u =q.front();q.pop();
    if (u == t)
            return true;

    for (int i = 0; i < nodes; i++)
        if (r[u][i] > 0 && parent[i]==-1) {
            parent[i] = u;
            cost[i] = min(cost[u], r[u][i]);
            q.push(i);
        }
    }
return false;
}

	int main() {
	    int st,en;
        freopen("input.txt","r",stdin);
	    //freopen("output.txt","w",stdout);
		while (scanf("%d %d",&n, &m)==2) {
            memset(r, 0, sizeof(r));          /* Clear edges */
            memset(match,-1,sizeof(match));

            scanf("%d", &edges);              /* get # of edges */
            for(int i=0;i<edges;i++){
              scanf("%d %d", &st, &en);         /* add edges */
              addEdge(st,en);                 /* Edges [0,n-1]->[0,m-1] */
            }

            s = m+n;
            t = m+n+1;
            nodes = n + m + 2;

            for(int i=0;i<n;i++)r[s][i]=1;
            for(int i=n;i<m+n;i++)r[i][t]=1;

			int maxflow = 0;
			while (bfs()) {

					maxflow += cost[t];
					int u = t;
					while (parent[u] != u) {
					    match[parent[u]] = u;
						r[parent[u]][u] -= cost[t];
						r[u][parent[u]] += cost[t];
						u = parent[u];
					}
			}
			printf("%d\n",maxflow);

//			for(int i=0;i<n;i++){
//			    if(match[i]!=-1)printf("%d %d\n",i,match[i]);
//			}
		}
	}




