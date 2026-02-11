#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // score[i] : i번째 계단의 점수, 0번째 = 땅
    // dp[i]    : i번째 계단에 도달했을 때 얻을 수 있는 최대 점수
    vector<int> score(n+1), dp(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    // ===== 초기값 =====
    // 계단이 1개일 때: 그냥 밟는 수밖에 없음
    // 0 -> 1
    dp[1] = score[1];

    // 계단이 2개일 때:
    // 0 -> 1 -> 2 로 가는 게 최대 (계단 연속 2칸까지는 허용)
    if(n >= 2)
        dp[2] = score[1] + score[2];

    // 계단이 3개일 때:
    // 0 -> 1 -> 3
    // 0 -> 2 -> 3
    // (1 -> 2 -> 3 은 3연속이라 불가능)
    if(n >= 3) {
        dp[3] = max(
            score[1] + score[3],  // 0 -> 1 -> 3
            score[2] + score[3]   // 0 -> 2 -> 3
        );
    }

    // ===== 점화식 =====
    for(int i = 4; i <= n; i++) {

        // i에 도착하는 방법은 딱 두 가지뿐

        // Case 1: i-2 -> i
        // 한 칸 건너뛰므로 연속성 리셋 (항상 안전)
        int case1 = dp[i-2] + score[i];

        // Case 2: i-3 -> i-1 -> i
        // i-1을 밟고 오고 싶으면,
        // i-2를 밟으면 안 되므로 반드시 i-3에서 와야 함
        // (이게 연속 2칸의 유일한 합법 루트)
        int case2 = dp[i-3] + score[i-1] + score[i];

        // 두 경우 중 더 큰 점수 선택
        dp[i] = max(case1, case2);
    }

    // 마지막 계단은 반드시 밟아야 하므로 dp[n]이 정답
    cout << dp[n];
}
