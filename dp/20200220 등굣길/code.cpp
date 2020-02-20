#include <string>
#include <vector>
using namespace std;

const int MOD = 1000000007;
vector<vector<int>> g_puddles;
vector<vector<int>> memo;
int func(int x, int y){
    if(x==0&&y==0) return 1;
    if(x<0||y<0) return 0;
    for(int i=0; i<g_puddles.size(); i++){
        if(x==g_puddles[i][0]-1 && y==g_puddles[i][1]-1) return 0;
    }
    if(memo[x][y]!=-1) return memo[x][y];
    memo[x][y] = (func(x-1,y)%MOD + func(x,y-1)%MOD)%MOD;
    return memo[x][y];
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    g_puddles = puddles;
    memo.assign(m, vector<int>(n, -1));
    answer = func(m-1,n-1);
    return answer;
}