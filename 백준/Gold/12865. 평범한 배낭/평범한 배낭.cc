#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    // DP 테이블 구조
    // dp[i][w] = i번째 물건까지 고려했을 때, 최대용량이 w인 가방에서의 최대 가치 값
    //
    // 테이블 구조 (예: N=3, W=10):
    //  i(번째 물건)\   w(최대용량)=0  1  2  3  4  5  6  7  8  9  10
    //  0              0          0  0  0  0  0  0  0  0  0  0  0 <= 0번째 물건 : 가치 0으로 초기화
    //  1              0          0  1  2  3  4  5  6  7  8  9  10 <= 그 상태(i,w)에서의 최대가치값들 계산순서
    //  2              0          0  A  B  C  D  E  F  G  H  ..
    //  3              0          0  ....                       30 <= 문제서 제시한 최대용량 W
    //                            ^=용량이 0이면 가치는 0 
    // 계산 순서 (각 칸에 번호를 매기면):
    // 000000000000        dp[i-1][w-weight] + value, dp[i-1][w]
    // 0123456789AB                      \               | 
    // 0CDEFGHIJKL                        \              | 안 넣는 경우는 유지만
    // 0MNOPQRSTUV                         \             | 넣는 경우는 둘 중 더 큰 값으로.
    //                                      \=>dp[i][w]<=| 
    // 각 칸은 윗칸과 왼윗칸만 참조
    // → 이전 물건 단계(i-1)의 두 용량 상태(w, w - weight) 둘 중에 더 큰 최대가치값을 i,w에 채택
    
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W;
    cin >> N >> W;
    
    // 1-indexed
    // items에 각 물건의 무게와 가치 입력 
    vector<pair<int, int>> items(N + 1);
    items[0] = {0, 0};
    
    for (int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;
        items[i] = {w, v};
    }
    
    // N + 1 바이 M + 1 크기의 dp 테이블 생성
    // 첫 행과 첫 열을 0으로 초기화
    // dp[0][w] = 0 (물건이 0개면 가치는 0)
    // dp[i][0] = 0 (용량이 0이면 아무것도 못 넣으므로 가치는 0)
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    
    // DP 계산
    for (int i = 1; i <= N; i++) {
        int weight = items[i].first;
        int value = items[i].second;
        
        for (int w = 0; w <= W; w++) {
            // i번째 물건을 넣을 수 있는 경우
            if (weight <= w) { // 넣을 수 있더라도 안넣는 게 이득이면 안 넣고 유지해야하니까 비교해보자
                // 윗칸(dp[i - 1][w]), 
                // 왼윗칸(dp[i - 1][w - weight] + value) 중 최대가치값이 더 큰 값을 i,w에 채택
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight] + value);
            
            } 
            // i번째 물건을 넣을 수 없는 경우
            else { 
                dp[i][w] = dp[i - 1][w]; // 물건을 못 넣으므로 이전 상태 유지 : 바로 윗칸 참조 
            }
        }
    }
    
    // 모든 물건을 고려했을 때, 전체 용량 W에서의 최대 가치
    cout << dp[N][W];
    
    return 0;
}