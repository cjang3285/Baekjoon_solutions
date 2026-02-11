#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    const int MOD = 15746;

    // dp[n] = 길이가 n인 이진 문자열을 만들 수 있는 경우의 수
    vector<int> dp(n+1);

    // [기저 사례]
    // 길이 1:
    // 만들 수 있는 건 "1" 하나뿐
    dp[1] = 1;

    // 길이 2:
    // "11", "00" 두 가지
    if (n >= 2) dp[2] = 2;

    // [점화식 채우기]
    for (int i = 3; i <= n; i++) {
        /*
            길이 i짜리 문자열의 마지막 경우는 두 가지뿐

            1) 마지막이 '1'인 경우
               → 앞은 길이 i-1
               → 경우의 수: dp[i-1]

            2) 마지막이 '00'인 경우
               → 앞은 길이 i-2
               → 경우의 수: dp[i-2]

            두 경우는 서로 겹치지 않으므로 더해준다.
        */
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    // 길이 n짜리 전체 경우의 수 출력
    cout << dp[n];
}
