#include <bits/stdc++.h>
using namespace std;
#define MAX_PATTERN_LENGTH 1000
#define MAX_TEXT_LENGTH 1000000
int z[MAX_PATTERN_LENGTH + MAX_TEXT_LENGTH + 1];

void computeZ(const char* s, int length){
    int lp, rp, k;
    z[0] = -1; lp = rp = 0;
    for( int i = 1; i < length; i++ ){
        if(rp < i){
            lp = rp = i;
            while(rp < length && s[rp - i] == s[rp])
                rp++;
            rp--; z[i] = rp - lp + 1;
        }
        else{
            k = i - lp;
            if( z[k] < rp - i +1 )//<=
                z[i] = z[k];
            else{
                lp = i;
                //rp = i + z[k] ;
                while(rp < length && s[rp - i] == s[rp])
                    rp++;
                rp--;z[i] = rp - lp + 1;
            }

        }
    }
}
/*
Assume z is computed over P$T string where $ is not present in P and T
*/
void showPatternPosition(int length, int patLength){
    for(int i = 0; i <= length; i++)
        if(z[i] == patLength)
            printf("%d ", i - patLength - 1);


}
int main(){
    char s[MAX_PATTERN_LENGTH + MAX_TEXT_LENGTH + 1];
    char pat[MAX_PATTERN_LENGTH],text[MAX_TEXT_LENGTH];
    int M, N;
    while(gets(text)){
        gets(pat);
        N = strlen(text);
        M = strlen(pat);

        strcpy(s,pat);
        s[M] = '$';s[M+1] = NULL;
        strcat(s,text);
        computeZ(s, M + N + 1);

        showPatternPosition(M+N+1, M);
    }
    return 0;
}
