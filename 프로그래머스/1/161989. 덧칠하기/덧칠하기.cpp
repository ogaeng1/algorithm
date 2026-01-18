#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int pos_paint = 0;
    
    for (int i = 0; i < section.size(); i++) {
        int s = section[i];
        
        if (s > pos_paint) {
            answer++;
            pos_paint = s + m - 1;
        }
    }
    
    
    return answer;
}