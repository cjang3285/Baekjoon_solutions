#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str1, str2;
    cin >> str1 >> str2;
    
    int n = str1.length();
    int m = str2.length();
    
    // dp[i][j] = str1의 i번째까지, str2의 j번째까지 봤을 때 최장공통부분수열의 길이
    // 1-indexed로 시작 (가비지값 방지, 대각선 위 참조 시 0으로 초기화된 값 사용)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // 계산 순서: 왼쪽에서 오른쪽, 위에서 아래로
    // (부분수열의 순서 조건 유지)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == str2[j-1]) {
                // 같은 문자: dp[i-1][j-1] + 1
                // 왜? 공통문자 발생 후 오른아래만 생존 (i행, j열 포함 나머지 소거)
                // (i,j)에서 이어붙을 수 있는 유일한 이전 칸 = 왼대각위
                // (1,2,3사분면은 소거, i-1행과 j-1열도 소거, 아래/오른칸은 미계산)
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // 다른 문자: max(dp[i-1][j], dp[i][j-1])
                // 왜? 공통문자가 아니므로 이어붙기 불가
                // 하지만 이전까지의 LCS는 접근 가능
                // 경로들이 \\\\ 형태로 오른대각아래 이어짐
                // 왼칸과 윗칸이 서로 다른 경로의 최장을 담음
                // 어느 경로가 더 긴지 모르므로 max 선택
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // 최종 답: dp[n][m]
    // 왜? 모든 칸에서 공통/비공통 기준으로 실처럼 이전 참조하며 갱신
    // → 자동으로 최적에 도달 (전역최적 보장)
    cout << dp[n][m];
    
    return 0;
}