#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N), dp(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // dp[i] = i번째 원소에서 끝나는 "최대 연속 부분합"
    dp[0] = a[0];
    int ans = dp[0];

    for (int i = 1; i < N; i++) {
        // i에서 새로 시작 vs 이전 걸 이어가기
        dp[i] = max(a[i], dp[i-1] + a[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
    return 0;
}
