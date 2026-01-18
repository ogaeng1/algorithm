#include <iostream>
#include <vector>

using namespace std;

long long dp[101][10][1024];
const int MOD = 1000000000;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int bit = 0; bit < 1024; bit++) {
                if (j > 0) {
                    dp[i][j][bit | (1 << j)] = (dp[i][j][bit | (1 << j)] + dp[i - 1][j - 1][bit]) % MOD;
                }
                if (j < 9) {
                    dp[i][j][bit | (1 << j)] = (dp[i][j][bit | (1 << j)] + dp[i - 1][j + 1][bit]) % MOD;
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer = (answer + dp[N][i][1023]) % MOD;
    }

    cout << answer << endl;

    return 0;
}