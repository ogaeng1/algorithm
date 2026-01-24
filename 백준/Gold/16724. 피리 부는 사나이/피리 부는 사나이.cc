#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<string> board;
vector<vector<int>> visited;
int safe_zone_count = 0;
int cycle = 1;

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) {
                int r = i, c = j;

                while (visited[r][c] == 0) {
                    visited[r][c] = cycle;
                    
                    char dir = board[r][c];
                    if (dir == 'U') r--;
                    else if (dir == 'D') r++;
                    else if (dir == 'L') c--;
                    else if (dir == 'R') c++;
                }

                if (visited[r][c] == cycle) {
                    safe_zone_count++;
                }
                
                cycle++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    board.resize(N);
    visited.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    solve();

    cout << safe_zone_count << "\n";

    return 0;
}