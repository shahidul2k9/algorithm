#include <cstdio>
#include <algorithm>
#define MAXN 100
using namespace std;

struct graph{
	int st,en,w;
//	bool operator < (const graph &g) const{
//		return w<g.w;
	//}
};
bool comp(graph e1, graph e2){
    return e1.w<e2.w;
}
graph edge[MAXN];
int Prev[MAXN];
int parent(int a){
	if(a==Prev[a]) return a;
	return Prev[a]=parent(Prev[a]);
}

int main(){
	int nodes,edges;
        freopen("input.txt","r",stdin);
        scanf("%d%d",&nodes,&edges);

		int total=0;
        //nodes are numbered from 0 to n-1
		for(int i=0;i<nodes;i++) Prev[i]=i;
		for(int i=0;i<edges;i++) scanf("%d%d%d",&edge[i].st,&edge[i].en,&edge[i].w);

		sort(edge,edge+edges,comp);

		for(int i=0; i<edges; i++ ){
			int u=parent(edge[i].st);
			int v=parent(edge[i].en);

			if(u!=v){
				total +=edge[i].w;
				Prev[u]=v;
				printf("%d %d %d\n",edge[i].st,edge[i].en,edge[i].w);
			}
		}

		printf("Total Cost of MST is:%d\n",total);

	return 0;
}


