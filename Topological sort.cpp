#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>


using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int nodes, edges;
vvi g;
vi color;
vi topoOrder;

void DFS_Visit(int u)
{
    color[u] = GRAY;

    FOR(i, 0, g[u].size()-1) {
        int v = g[u][i];
        if(color[v] == WHITE)
            DFS_Visit(v);
    }
    topoOrder.push_back(u);
    color[u] = BLACK;
}

void TopoSort()
{
    color = vi(nodes+1, WHITE);
    topoOrder.clear();
    FOR(i, 1, nodes) {
        if(color[i] == WHITE)
            DFS_Visit(i);
    }
    reverse(topoOrder.begin(), topoOrder.end());

}

int main()
{
    READ("input.txt");
    WRITE("output.txt");
    int u, v;

    while(cin >> nodes >> edges) {
        g = vvi(nodes+1);
        FOR(i, 1, edges) {
            cin >> u >> v;
            g[u].push_back(v);
        }
        TopoSort();
        FOR(i, 0, topoOrder.size()-1)
            cout << topoOrder[i] << " " ;
        cout << "\n";
    }

	return 0;
}
