#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string alpha = "";
    
    for (char c = 'a'; c <= 'z'; ++c) {
        if (skip.find(c) == -1) {
            alpha += c;
        }
    }
    
    for (auto& c : s) {
        int pos = (alpha.find(c) + index) % alpha.size();
        answer += alpha[pos];
    }
    
    return answer;
}