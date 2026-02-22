#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 입력: 행렬 1부터 n까지 각각 r c 형태로 주어짐
    // 1-based 인덱싱 사용
    // 행렬 i의 크기: p[i] × p[i+1]
    // p[1] = 행렬 1의 행, p[2] = 행렬 1의 열 = 행렬 2의 행, ...
    // p[i] = 행렬 i의 행, p[i+1] = 행렬 i의 열
    vector<long long> p(n + 2);
    
    for (int i = 1; i <= n; i++) {
        long long r, c;
        cin >> r >> c;
        if (i == 1) p[1] = r;  // 첫 행렬의 행
        p[i + 1] = c;           // 행렬 i의 열
    }
    
    // dp[i][j] = i번째부터 j번째 행렬까지 모두 곱하는데 필요한 곱셈연산 횟수의 최솟값
    // 초기값: dp[i][i] = 0 (자기 자신은 곱할 게 없음)
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    
    // len = 대각선 인덱스. len이 고정되면 j - i가 고정 → 같은 대각선
    // len 순서로 채우면 작은 구간 먼저 보장
    // → 큰 구간 계산 시 작은 구간 값이 항상 이미 채워져 있음
    //
    // N=8 상삼각행렬 (len 표시)
    //       1    2    3    4    5    6    7    8
    //   1 [L1] [L2] [L3] [L4] [L5] [L6] [L7] [L8]
    //   2      [L1] [L2] [L3] [L4] [L5] [L6] [L7]
    //   3           [L1] [L2] [L3] [L4] [L5] [L6]
    //   4                [L1] [L2] [L3] [L4] [L5]
    //   5                     [L1] [L2] [L3] [L4]
    //   6                          [L1] [L2] [L3]
    //   7                               [L1] [L2]
    //   8                                    [L1]
    //
    // dp[1][7] (len=7) 계산 시 참조하는 칸:
    // k=1: dp[1][1](L1) + dp[2][7](L6)
    // k=2: dp[1][2](L2) + dp[3][7](L5)
    // k=3: dp[1][3](L3) + dp[4][7](L4)
    // k=4: dp[1][4](L4) + dp[5][7](L3)
    // k=5: dp[1][5](L5) + dp[6][7](L2)
    // k=6: dp[1][6](L6) + dp[7][7](L1)
    //
    // 참조하는 자리들을 줄로 연결하면 두 줄이 교차하는 규칙을 볼 수 있다.
    
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            
            // i~j를 i~k와 k+1~j 두 덩어리로 쪼갬
            // i~k를 곱한 결과: p[i] × p[k+1]
            // k+1~j를 곱한 결과: p[k+1] × p[j+1]
            // 
            // 행렬 곱셈: n×m과 m×k를 곱하면 n×k이고, 곱셈연산은 n*m*k번
            // 따라서 마지막 두 행렬 p[i]×p[k+1]과 p[k+1]×p[j+1]
            // 의 곱셈 연산 횟수: p[i] * p[k+1] * p[j+1]
            //
            // e.g. (입력 순서대로 곱셈 시):
            // 행렬 1(p[1]×p[2]) × 행렬 2(p[2]×p[3]): 연산횟수 p[1]*p[2]*p[3]회
            // 결과(p[1]×p[3]) × 행렬 3(p[3]×p[4]): 누적연산횟수 p[1]*p[2]*p[3] + p[1]*p[3]*p[4]회
            // 마지막 행렬까지 끝나면 최종 누적 연산횟수: p[1]*p[2]*p[3] + p[1]*p[3]*p[4] + ... + p[1]*p[n]*p[n+1]회
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], 
                    dp[i][k] + dp[k+1][j] + p[i] * p[k+1] * p[j+1]);
            }
        }
    }
    
    cout << dp[1][n] << "\n";
    
    return 0;
}
