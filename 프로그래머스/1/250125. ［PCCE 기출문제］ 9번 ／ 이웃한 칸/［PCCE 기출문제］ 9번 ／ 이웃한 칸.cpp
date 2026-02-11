#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    vector<int> dh = {1, 0, -1, 0};
    vector<int> dw = {0, 1, 0, -1};
    
    for (int i = 0; i < 4; i++) {
        int nh = dh[i] + h;
        int nw = dw[i] + w;
        
        if (0 <= nh && nh < n && 0 <= nw && nw < n) {
            if (board[h][w] == board[nh][nw]) {
                answer += 1;
            }
        }
    }
    return answer;
}