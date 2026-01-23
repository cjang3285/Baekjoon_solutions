#include <bits/stdc++.h>
using namespace std;

int cnt_rec = 0;
int cnt_dp = 0;

int fib_rec(int n) {
    if (n == 1 || n == 2) {
        cnt_rec++;         // ★ 여기!
        return 1;
    }
    return fib_rec(n-1) + fib_rec(n-2);
}

int main() {
    int n;
    cin >> n;

    fib_rec(n);

    // DP 카운트
    vector<int> dp(n+1);
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        cnt_dp++;          // ★ 여기!
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << cnt_rec << " " << cnt_dp;
}

