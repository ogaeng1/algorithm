#include <iostream>
#include <vector>

using namespace std;

int dp[2001][2001];
int arr[2001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }

    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
    }
    
    for (int len = 3; len <= N; len++) {
        for (int start = 1; start <= N - len + 1; start++) {
            int end = start + len - 1;

            if (arr[start] == arr[end] && dp[start + 1][end - 1]) {
                dp[start][end] = 1;
            }
        }
    }

    cin >> M;
    while (M--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }

    return 0;
}