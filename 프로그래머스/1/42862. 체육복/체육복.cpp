#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int count = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] == -1) continue;
            
        for (int j = 0; j < reserve.size(); j++) {
            if (reserve[j] == -1) continue;
            
            if (abs(lost[i]-reserve[j]) == 1) {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    for (auto student : lost) {
        if (student != -1) count++;
    }
    
    return n-count;
}