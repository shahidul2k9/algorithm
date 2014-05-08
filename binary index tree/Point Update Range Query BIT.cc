#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int Type;
#define MAX_ELEMENTS 100000
#define step(x) ((x)& (-x))

// Point update range query BIT
struct Bit{
    int N;
    Type* ft;
    Bit(int n):N(n){ft = new Type[N+1];}
    void init(int n){
        memset(ft, 0, sizeof(Type)*(N+1));
    }
    void add(int idx, Type v){
        while(idx <= N){
            ft[idx] += v;
            idx += step(idx);
        }
    }
    //Returns cumulative sumation in rnage [1...idx]
    Type cms(int idx){
        Type s = 0;
        while(idx > 0){
            s += ft[idx];
            idx -=step(idx);
        }
        return s;
    }
    Type query(int a, int b){
        return cms(b) - cms(a-1);
    }
    void scaleUp(Type c){
        for(int idx = 1; idx <= N; idx++)
            ft[idx] *= c;
    }
    void scaleDown(Type c){
        for(int idx = 1; idx <= N; idx++)
            ft[idx] /= c;
    }


};

int main(){
    Bit bit = Bit(MAX_ELEMENTS);

	return 0;
}
