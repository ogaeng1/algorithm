#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = s + s;
    
    if (s.size() % 2 != 0) return 0;
    
    for (int i = 0; i < s.size(); i++) {
        vector<char> stack;
        bool valid = true; 
        
        for (int j = i; j < i+s.size(); j++) {
            
            if (temp[j] == '(' || temp[j] == '{' || temp[j] == '[') {
                stack.push_back(temp[j]);
            } else {
                if (stack.empty()) {
                    valid = false;
                    break;
                }
                
                if (temp[j] == ')' && stack.back() == '(') {
                    stack.pop_back();
                } else if (temp[j] == '}' && stack.back() == '{') {
                    stack.pop_back();
                } else if (temp[j] == ']' && stack.back() == '[') {
                    stack.pop_back();
                } else {
                    valid = false;
                    break;
                }
            }   
        }
        if (valid && stack.empty()) answer++;
    }
    return answer;
}