#include<bits/stdc++.h>
using namespace std;
// dp[i][j]는 i, j까지의 최대 누적 비용
int dp[501][501];
int cost[501][501];

int main(){
    int n; cin >> n;
    int first_cost; cin >> first_cost;
    dp[1][1] = first_cost;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(i == 1 && j == 1) // 초기값 대입했으므로 여기서도 하면 안됨
                continue;
            
            cin >> cost[i][j];
            dp[i][j] = cost[i][j] + max(dp[i-1][j], dp[i-1][j-1]); 
            // 만약 왼쪽이나 오른쪽 끝이라 둘 중 하나의 dp 값만 존재하는 경우
            // dp 배열이 전역변수로 초기화되어 0으로 차있으므로 max 함수에 들어가면 정상 dp 값이 0보다는 클테니 문제 없이 처리된다.
        }
    }
    
    /*
        dp[1,1] = cost[1,1](7) // 첫 값은 대입
        ...
        dp[5,1] = cost[5,1](4) + min(dp[4,1](2), dp[3,1](x)) // 왼쪽 끝은 오른쪽 위에서만 내려올 수 있음
        ...
        dp[5,4] = cost[5,4](6) + min(dp[4,4](4), dp[4,3](4))
        dp[5,5] = cost[5,5](5) + min(dp[4,4](4), dp[4,5](x)) // 오른쪽 끝은 왼쪽 위에서만 내려올 수 있음
    
        dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i-1][j-1]); 라는 점화식을 가진다는 것을 관찰을 통해 알 수 있다
    */
    
    int max = 0;
    for(int k = 1; k <= n; k++){
        if(dp[n][k] > max)
            max = dp[n][k];    
    }
    cout << max;
}