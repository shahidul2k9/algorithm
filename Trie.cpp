#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <assert.h>

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

#define NDEBUG
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
#define N 500
#define NOLINK -2

#define R 26
int at,root,ans;

struct Trie{
    int words;
    int prefixes;
    int link[R];
};
//vector<Trie>t;
Trie t [N];
void clear_trie_node(int n){
    t[n].words = t[n].prefixes = 0;
    FOR(i,0,R-1)t[n].link[i] = NOLINK;
}
int getNode(){
    clear_trie_node(at);
    return at++;
}
string asciToString(char ch){
    stringstream ss;
    string s;
    ss<<ch;
    ss>>s;
    return s;
}
void addWord(const string& key){
    int cur = root;
    int lb;
    FOR(i,0,key.length()-1){
        lb = key[i]-'a';
        if(t[cur].link[lb]==NOLINK){
            t[cur].link[lb] = getNode();
        }
        cur = t[cur].link[lb];
        t[cur].prefixes++;
    }
    t[cur].words++;
}
void traverse(int u,string key){
    if(t[u].words)cout<<key<<endl;
    FOR(i,0,R-1){
        if(t[u].link[i]!=NOLINK)
        traverse(t[u].link[i], key+asciToString(i+'a'));
    }
}
int main()
{
    //Attention this program does not work if NOEDGE is assigned 4,5,6 or 7 ... why describe
    //READ("input.txt");
    //WRITE("output.txt");
    int words;
    string key;
   // t.resize(N);

    while(scanf("%d",&words)){
        at = 0;
        root = getNode();
        FOR(i,1,words){
            cin>>key;
            addWord(key);
        }

        traverse(root,"");
    }
	return 0;
}
