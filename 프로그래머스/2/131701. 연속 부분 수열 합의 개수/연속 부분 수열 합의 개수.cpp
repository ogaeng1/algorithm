#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int length = elements.size();
    unordered_set<int> total;
    vector<int> seq = elements;
    seq.insert(seq.end(), elements.begin(), elements.end());
    
    for (int i = 1; i <= length; i++) {
        int sum = 0;
        
        for (int j = 0; j < i; j++) {
            sum += seq[j];
        }
        total.insert(sum);
        
        for (int start = 1; start < length; start++) {
            sum -= seq[start-1];
            sum += seq[start + i - 1];
            total.insert(sum);
        }
    }
    
    
    return total.size();
}