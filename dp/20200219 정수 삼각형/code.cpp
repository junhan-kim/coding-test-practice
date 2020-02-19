#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> g_triangle;
vector<vector<int>> sum;
int hLimit;

int cal(int h, int r){
    if(h==0) return g_triangle[0][0];
    if(sum[h][r]!=-1) return sum[h][r];
    if(r==0) sum[h][r] = g_triangle[h][r] + cal(h-1,r);
    else if(r==h) sum[h][r] = g_triangle[h][r] + cal(h-1,r-1);
    else sum[h][r] =  g_triangle[h][r] + max(cal(h-1,r-1), cal(h-1,r));
    return sum[h][r];
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    g_triangle = triangle;
    hLimit = triangle.size()-1;
    sum.assign(triangle.size(), vector<int>(triangle.size(), -1));
    vector<int> totalSumArr(triangle.size());
    for(int r=0; r<triangle.size(); r++){
        totalSumArr[r] = cal(triangle.size()-1, r);
    }
    sort(totalSumArr.begin(), totalSumArr.end());
    answer = totalSumArr[triangle.size()-1];
    return answer;
}