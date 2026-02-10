#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    
    for (char c : s) {
        m[c]++;
    }
    
    for (auto const& [k, v] : m) {
        if (v == 1) {
            answer += k;
        }
    }
    
    
    return answer;
}