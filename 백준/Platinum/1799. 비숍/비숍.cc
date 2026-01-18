#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[10][10];
int l_diag[20];
int r_diag[20];
int max_cnt[2]; // 0: 검은색 칸 최대, 1: 흰색 칸 최대

void solve(int row, int col, int count, int color) {
    if (col >= N) {
        row++;
        col = (col % 2 == 0) ? 1 : 0;
    }
    if (row >= N) {
        max_cnt[color] = max(max_cnt[color], count);
        return;
    }

    // 비숍을 놓을 수 있는 경우
    if (board[row][col] && !l_diag[row - col + N] && !r_diag[row + col]) {
        l_diag[row - col + N] = r_diag[row + col] = 1;
        solve(row, col + 2, count + 1, color);
        l_diag[row - col + N] = r_diag[row + col] = 0; // 백트래킹
    }
    
    // 비숍을 놓지 않는 경우
    solve(row, col + 2, count, color);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> board[i][j];

    solve(0, 0, 0, 0); // 검은색 칸 시작 (0,0)
    solve(0, 1, 0, 1); // 흰색 칸 시작 (0,1)

    cout << max_cnt[0] + max_cnt[1] << '\n';
    return 0;
}
