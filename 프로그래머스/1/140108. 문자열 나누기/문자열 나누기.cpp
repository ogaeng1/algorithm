#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    char first;
    int same = 0;
    int diff = 0;
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (same == 0) {
            first = s[i];
            same = 1;
        } else {
            if (first == s[i]) same++;
            else diff++;
        }
        
        if (same == diff) {
            answer++;
            same = 0;
            diff = 0;
        }
    }
    
    if (same != 0) {
        answer++;
    }
    
    return answer;
}