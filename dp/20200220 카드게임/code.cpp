#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> memo;
vector<int> g_left;
vector<int> g_right;
int func(int l, int r){
    if(l==g_left.size()||r==g_right.size()) return 0;
    if(memo[l][r]!=-1) return memo[l][r];
    vector<int> v;
    v.push_back(func(l+1, r));
    v.push_back(func(l+1, r+1));
    if(g_right[r] < g_left[l]) v.push_back(func(l, r+1) + g_right[r]);
    memo[l][r] = *max_element(v.begin(), v.end());
    return memo[l][r];
}
int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    g_left = left;
    g_right = right;
    memo.assign(left.size(), vector<int>(right.size(),-1));
    answer=func(0,0);
    return answer;
}