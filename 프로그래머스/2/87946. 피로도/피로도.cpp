#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());
        
    do {
        int cur = k;
        int cnt = 0;
        
        for (const auto& d : dungeons) {
            if (cur >= d[0]) {
                cur -= d[1];
                cnt++;
            } else break;
        }
        
        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}