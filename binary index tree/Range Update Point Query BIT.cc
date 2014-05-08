#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef int  Type;
#define MAX_ELEMENTS 100000
#define step(x) ((x)& (-x))

//Range Update Point Query BIT
struct Bit{
    int N;
    Type ft[MAX_ELEMENTS+1];
    Bit(int n):N(n){memset(ft, 0, sizeof(Type)*(N+1));}
    void add(int idx, Type v){
        while(idx <= N){
            ft[idx] += v;
            idx += step(idx);
        }
    }
    void init(int n){
        N = n;
        memset(ft, 0, sizeof(Type)*(N+1));
    }
    //Returns value at index[idx]
    Type query(int idx){
        Type s = 0;
        while(idx > 0){
            s += ft[idx];
            idx -= step(idx);
        }
        return s;
    }
    //Add value v in range [a...b]
    void update(int a, int b, Type v){
        add(a, v);
        add(b+1, -v);
    }

};
