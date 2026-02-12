#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // wine[i] = i번째 포도주의 양 (1-indexed)
    vector<int> wine(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

    // dp[i] = 1 ~ i번째 포도주까지 고려했을 때 얻을 수 있는 최대 양
    vector<int> dp(n+1, 0);

    // 기저값
    if (n >= 1) dp[1] = wine[1];
    if (n >= 2) dp[2] = wine[1] + wine[2];

    /*
        핵심 아이디어 (시간축 DP):

        "연속 3잔 금지"라는 제약은 논리적으로:
        -> 마지막 3칸(i, i-1, i-2) 중
           반드시 하나는 '안 마신 지점'이 있어야 한다.

        즉, 합법적인 모든 경우는
        "마지막으로 안 마신 시점"이 어디냐로
        딱 3가지로 완전 분해된다.

        Case 1: i번째를 안 마신다
            패턴: ... - _
            dp[i-1]

        Case 2: i-1번째를 안 마신다
            패턴: ... - _ -
            dp[i-2] + wine[i]

        Case 3: i-2번째를 안 마신다
            패턴: ... - _ - -
            dp[i-3] + wine[i-1] + wine[i]

        이 3개 말고는 존재 불가능.
        (i, i-1, i-2 전부 마시면 3연속 위반)
    */

    for (int i = 3; i <= n; i++) {
        dp[i] = max({
            dp[i-1],                              // Case 1: 이번에 안 마심
            dp[i-2] + wine[i],                    // Case 2: i-1에서 끊김
            dp[i-3] + wine[i-1] + wine[i]         // Case 3: i-2에서 끊김
        });
    }

    cout << dp[n];
}
