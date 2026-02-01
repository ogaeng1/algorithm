#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (int i = 0; i <= myString.size()-pat.size(); i++) {
        if (myString.substr(i, pat.length()) == pat) {
            answer++;
        }
    }
    return answer;
}