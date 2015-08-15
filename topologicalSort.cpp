/*
   Complexity:  O(N) where N is the number of nodes
        There may be more than one way to topological sort
		a DAG.  If the lexicographically first one is needed,
		it may be a good idea to use a priority queue instead
		and just pull off vertices with 0 in-degree
	        Vertices are numbered 0..n-1.
*/
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define pb(x) push_back(x)
#define MAXNODE 1000
#define sz size()
vector<int> g[MAXNODE];
int id, top[MAXNODE], done[MAXNODE];

void dfs(int u){
  done[u] = 1;
  for(size_t i = 0; i < g[u].sz; i++)
    if(!done[g[u][i]]) dfs(g[u][i]);
  top[id--] = u;//keeping nodes according to their finishing time
}

void topSort(int n){
  memset(done, 0, sizeof(done));
  id = n-1;
  for(int i = 0; i < n; i++)
    if(!done[i]) dfs(i);
}

int main(){
  int n, e, i, u, v;
  while(scanf("%d %d", &n, &e) == 2){
    for(i = 0; i < n; i++) g[i].clear();
    for(i = 0; i < e; i++){
      scanf("%d %d", &u, &v);
      g[u].pb(v);
    }
    topSort(n);
    for(i = 0; i < n; i++)
      printf("%d ", top[i]);
    printf("\n");
  }
  return 0;
}
