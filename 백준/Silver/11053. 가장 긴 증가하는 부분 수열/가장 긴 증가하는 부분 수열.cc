#include <bits/stdc++.h>
using namespace std;

int dp[1001]; 
// dp[i] = "i번째 원소를 마지막으로 사용하는 LIS 길이"
// i번째 원소 이전의 원소들은 최대 수열 길이를 위해 교체될 수 있음
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n+1);
    // 1-index 사용: 수식(dp, j < i) 그대로 쓰기 편하게
    // 수열 입력
    for(int i = 1; i <= n; i++){
        cin >> v[i];

    }

    // LIS DP 시작
    for(int i = 1; i <= n; i++){ // i가 n까지 간다
        dp[i] = 1;
        // 자기 자신 하나만 쓰는 증가 수열은 항상 가능
        // 모든 LIS의 최소 길이는 1

        for(int j = 1; j < i; j++){
            // i보다 앞에 있는 모든 원소 탐색
            // 바로 직전(i-1)만 보는 게 아니라 매 i 마다 '전체 과거 j들'을 봄

            if(v[i] - v[j]> 0){ // i보다 앞의 원소가 i보다 작으면 즉, 증가하면
                // dp[i] = "i번째 원소를 마지막으로 사용하는 LIS 길이"
                dp[i] = max(dp[i], dp[j] + 1);
                // j에서 끝나는 LIS 뒤에 i를 붙여보고 
                // 현재까지 알려진 최대 길이인 dp[i]보다 크면 그 값을 채택한다. 
                // 이를 반복하여 여러 j (1 ~ i-1) 중에서 가장 큰 dp[j] + 1 값 선택
                // 증가하는 경우가 하나도 없으면 dp[i]로 유지.
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
        // LIS는 반드시 n에서 끝난다는 보장이 없음
        // 모든 dp[i] 중 최대값이 진짜 LIS
    }

    cout << ans;
}
