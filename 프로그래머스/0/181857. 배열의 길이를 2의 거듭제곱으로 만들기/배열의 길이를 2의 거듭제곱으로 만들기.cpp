#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int target = 1;
    int n = arr.size();
    
    while (target < n) {
        target *= 2;
    }
    
    arr.resize(target, 0);
    
    return arr;
}