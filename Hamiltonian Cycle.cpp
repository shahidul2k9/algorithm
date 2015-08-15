#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX_NODE 15
int g[MAX_NODE][MAX_NODE];
int touple[MAX_NODE];
int v;
/*
    index is the current level or depth of the space state tree
    whose root is unknown and root's label is 0
*/
bool promising(int index, int curv){
    if(!g[touple[index-1]][curv])return false; //check if it can move from previous node
    for(int i =2;i<index;i++)if(touple[i]==curv)return false; //check if current node is already taken or not
    return true;
}

void hamiltonian (int index) {
    for(int i=2; i<=v;i++)
    if (promising (index, i)){
        touple[index] = i;
        if(index == v){
            //if(g[touple[index]][1])//check if is there cycle
               // for(int k = 1;k<=v; k++)printf("%d%c", touple[k], k==v?'\n':' ');
            for(int k = 1;k<=v; k++)printf("%d%c", touple[k], k==v?'\n':' ');  //for hamiltonian path
        }
        else hamiltonian(index + 1);
    }

}
int main()
{
    freopen("input.txt", "r", stdin);
    while(scanf("%d", &v)==1 && v){
        for(int i=1; i<=v;i++)
            for(int j=1; j<=v;j++)scanf("%d", &g[i][j]);
        touple[1] = 1;  //we will start our tour from 1
        hamiltonian(2);
    }
    return 0;
}
 /* Let us create the following graph
      (1)--(2)--(3)
       |   / \   |
       |  /   \  |
       | /     \ |
      (4)-------(5)


5
1 1 0 1 0
1 1 1 1 1
0 1 1 0 1
1 1 0 1 1
0 1 1 1 1
*/
