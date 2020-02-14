#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    map<string, int> m;

    for(auto elem : participant){
        m[elem] = 0;
    }

    for(auto elem : participant){
        m[elem]++;
    }

    for(auto elem : completion){
        m[elem]--;
    }

    for(auto it = m.begin(); it != m.end(); it++){           
        if(it->second == 1) {
            answer = it->first;
            return answer;
        }        
    }
}