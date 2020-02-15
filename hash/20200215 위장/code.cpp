#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> m;
    
    for(auto elem : clothes){
        if(m.find(elem[1])==m.end()) m[elem[1]] = 2; 
        else m[elem[1]]++;
    }
    
    int mulRes = 1;
    for(auto it = m.begin(); it != m.end(); it++){
        mulRes *= it->second;
    }
    answer = mulRes-1;
    
    return answer;
}