#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    // dp[n] = n번째 파도반 수
    // 문제에서 n 최대가 100이므로 충분히 크게 잡는다
    long long dp[101];

    // --- 초기값 (base case) ---
    // 문제에서 직접 주어진 값들
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    // --- 점화식 ---
    // P(n) = P(n-1) + P(n-5)
    // n=6부터 차례대로 채운다
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    // --- 쿼리 처리 ---
    // 미리 dp를 다 만들어두고, 질문 들어오면 바로 출력
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}
