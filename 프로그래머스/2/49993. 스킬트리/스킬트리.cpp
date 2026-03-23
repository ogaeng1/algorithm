#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string skill_str : skill_trees) {
        int idx = 0;
        bool valid = true;
        
        for (char ch : skill_str) {
            int pos = skill.find(ch);
            
            if (pos == string::npos) continue;
            
            if (pos == idx) {
                idx++;
            } else {
                valid = false;
                break;
            }
        }
        
        if (valid) answer++;
    }
    return answer;
}