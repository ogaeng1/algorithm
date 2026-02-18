#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> orange;
    vector<int> box;
    
    for (auto t : tangerine) {
        orange[t]++;
    }
    
    for (const auto& [size, count] : orange) {
        box.push_back(count);
    }
    
    sort(box.begin(), box.end(), greater<int>());
    
    for (const auto& v : box) {
        answer++;
        k -= v;
        
        if (k <= 0) break;
    }
    
    return answer;
}