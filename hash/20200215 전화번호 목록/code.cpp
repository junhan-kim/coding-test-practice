#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    map<string, bool> m;
    
    for(auto str : phone_book){
        m[str] = true;
    }
    
    for(auto str : phone_book){
        for(int len = 1; len < str.size(); len++) {
            string prefix = str.substr(0, len);
            if(m[prefix] == true) {
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}