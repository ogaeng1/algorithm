#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    
    while (n > 0) {
        
        int maxNum = pq.top();
        pq.pop();
        
        if (maxNum == 0) break;
        
        pq.push(maxNum-1);
        n--;
    }
    
    while(!pq.empty()) {
        
        long long num = pq.top();
        pq.pop();
        answer += (num * num);
    }
    
    return answer;
}