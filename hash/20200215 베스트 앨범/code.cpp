#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string,int> &b){
    return a.second > b.second;
}

bool indexPlaysVectorCompare(const pair<int, int> &a, const pair<int, int> &b){
    return a.second != b.second? a.second > b.second : a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> m;

    for(int i = 0; i < genres.size(); i++){
        m[genres[i]]+=plays[i];
    }

    vector<pair<string,int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    for(auto it = v.begin(); it != v.end(); it++){
        map<int, int> index_plays_map;
        for(int i = 0; i < genres.size(); i++){
            if(it->first == genres[i]){
               index_plays_map[i] = plays[i];
            }
        }     
        vector<pair<int, int>> index_plays_vector(index_plays_map.begin(), index_plays_map.end());
        sort(index_plays_vector.begin(), index_plays_vector.end(), indexPlaysVectorCompare);

        int cnt = 0;
        for(auto it = index_plays_vector.begin(); it != index_plays_vector.end(); it++){
            answer.push_back(it->first);
            cnt++;
            if(cnt == 2) break;
        }
    } 
    return answer;
}