#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    for (int i = 1; i < numLog.size(); i++) {
        
        int cur = numLog[i] - numLog[i-1];
        
        if (cur == 1) answer += "w";
        else if (cur == -1) answer += "s";
        else if (cur == 10) answer += "d";
        else if (cur == -10) answer += "a";
    }
    
    return answer;
}