#include <string>
#include <vector>
#include <string.h>

using namespace std;

long long *roundMemo;
long long *facMemo;

long long fac(int tile);

long long round(int tile){
    if(tile==1) return 4;
    if(roundMemo[tile] != -1) return roundMemo[tile];
    roundMemo[tile] = round(tile-1) + fac(tile)*2;
    return roundMemo[tile];
}

long long fac(int tile){
    if(tile==1 || tile==2) return 1;
    if(facMemo[tile] != -1) return facMemo[tile];
    facMemo[tile] = fac(tile-1) + fac(tile-2);
    return facMemo[tile];
}

long long solution(int N) {
    long long answer = 0;

    roundMemo = new long long[N+1];
    facMemo = new long long[N+1];
    memset(roundMemo, -1, sizeof(long long)*(N+1));
    memset(facMemo, -1, sizeof(long long)*(N+1));    
    answer = round(N);

    return answer;
}