#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define pb(x) push_back(x)
#define MAXN 1001
typedef  pair<int,int> pii;
// ( w (u, v) ) format
vector< pair< int, pii > > g, mst;
int parent[MAXN];

int findset(int x)
{
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

int kruskal(int e)
{
    int i, pu, pv,total;
    sort(g.begin(), g.end()); // increasing weight
    for(i=total=0; i<e; i++)
    {
        pu = findset(g[i].second.first);
        pv = findset(g[i].second.second);
        if(pu != pv)
        {
            mst.pb(g[i]); // add to tree
            total += g[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
    return total;
}

void reset(int n)
{
    g.clear();
    mst.clear();
    for(int i=0; i<n; i++) parent[i] = i;
}


int main()
{
    int i, u, v, w ,n, e;

    scanf("%d %d", &n, &e);
    reset(n);
    for(i=0; i<e; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        g.push_back(pair< int, pii >(w, pii(u, v)));
    }
    printf("%d",kruskal(e)); // runs kruskal and construct mst vector
    return 0;
}
