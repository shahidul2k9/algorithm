#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
#define MAX 100
int main()
{
    freopen("input.txt", "r", stdin);
    set<int> st;
    set<int>::iterator it;
    int n ,i, a[MAX];
    while(scanf("%d", &n)==1&&n){
    for(i=0;i<n;i++)scanf("%d", &a[i]);

    st.clear();

    for(i=0; i<n; i++){
    st.insert(a[i]); it=st.find(a[i]);

    it++; if(it!=st.end()) st.erase(it);
//    if(*it == *(st.rbegin())) ;
//    else st.erase(++it);
    }

    printf("LIS length=%d\n", st.size());

    for(it=st.begin(); it!=st.end();it++)printf("%d ", *it);
    }
    return 0;
}
