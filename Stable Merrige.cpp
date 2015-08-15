#include <cstdio>
#include <string.h>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define N 102
int bp[N][N];//bp[i][j] contains the jth prefered girl's name of the of boy i
int gp[N][N];//gp[i][j] contains the jth prefered boy's name of the of girl i
int b_s[N]; /*b_s[i] means boy i matches to his b_s[i]th prefered girl
                so boy i matches to girl bp[i][b_s[i]]*/
int g_s[N];/*b_s[i] means girl i matches to her b_s[i]th prefered boy
            so girl i matches to boy gp[i][g_s[i]]*/
bool engaged[N];//if engaged[i] is true then boy i is engaged to girl
int n;
int getRank(int boy, int girl){
    for(int i=0;i<n;i++)if(gp[girl][i]==boy)return i;
}
inline void engage(int boy, int girl){
    engaged[boy] = true;
    g_s[girl] = getRank(boy,girl);
}

int main(){

    freopen("input.txt","r",stdin);
    int test,cs=1;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        /*boys' preference lis*/
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                {scanf("%d",&bp[i][j]);}
        /*girls' preference list*/
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                {scanf("%d",&gp[i][j]);}

        memset(engaged,0,sizeof(engaged));
        memset(b_s,-1,sizeof(b_s));
        memset(g_s,-1,sizeof(g_s));

        for(int boy = 0;boy<n;boy++){
            if(engaged[boy])continue;   /* while ∃ free boy  who still has a girl  to propose to*/
            int girl = bp[boy][++b_s[boy]];/*boy's highest ranked such girl to whom he has not yet proposed*/
            if(g_s[girl]==-1)       /*if girl is free (boy, girl) become engaged*/
                engage(boy,girl);

            /*else some pair (boy', girl) already exists */
            else{
                int dumped_boy = gp[girl][g_s[girl]];
                int curr_boy_rank = getRank(boy,girl);
                int prev_boy_rank = getRank(dumped_boy,girl);
                /*if girl prefers boy to boy' (boy, girl) become engaged boy' becomes free*/
                if(curr_boy_rank<prev_boy_rank){
                    engaged[dumped_boy] = false;
                    engage(boy,girl);
                    boy = dumped_boy;
                    boy--;
                    continue;

                }
                else {boy--;continue;}/*(boy', girl) remain engaged*/
            }

        }
        printf("Case %d: ",cs++);
        for(int i=0;i<n;i++)printf("(%d %d)%c",i,bp[i][b_s[i]],(i==n-1)?'\n':' ');
    }
}
