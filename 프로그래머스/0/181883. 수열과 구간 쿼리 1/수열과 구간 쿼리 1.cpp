#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    int n = arr.size();
    vector<int> temp(n+1, 0);
    
    for (const auto& q : queries) {
        int s = q[0];
        int e = q[1];
        temp[s]++;
        temp[e+1]--;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += temp[i];
        arr[i] += sum;
    }
    
    return arr;
}