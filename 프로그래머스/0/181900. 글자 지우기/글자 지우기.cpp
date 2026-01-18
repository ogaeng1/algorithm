#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    for (int i = 0; i < indices.size(); i++) {
        int curIndex = indices[i];
        my_string[curIndex] = '*';
    }
    
    for (int i = 0; i < my_string.size(); i++) {
        if (my_string[i] != '*') {
            answer += my_string[i];
        }
    }
    
    return answer;
}