#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
  2565번 전깃줄
  
  [문제 분석]
  교차 정의: (a' > a AND b' < b) OR (a' < a AND b' > b)
  
  [논리적 유도]
  교차하지 않는 조건 = 교차 조건의 부정
  NOT[(a' > a AND b' < b) OR (a' < a AND b' > b)]
  = (a' <= a OR b' >= b) AND (a' >= a OR b' <= b)
  
  [분배법칙 적용]
  (X OR Y) AND (Z OR W) = (X AND Z) OR (X AND W) OR (Y AND Z) OR (Y AND W)
  X=a'<=a, Y=b'>=b, Z=a'>=a, W=b'<=b
  
  = (a' = a) OR (a' <= a AND b' <= b) OR (a' >= a AND b' >= b) OR (b' = b)
  
  [조건 적용]
  같은 위치에 2개 이상 불가 → a' ≠ a, b' ≠ b
  = (a' < a AND b' < b) OR (a' > a AND b' > b)
  
  [결론]
  교차하지 않으려면: 둘 다 앞이거나 OR 둘 다 뒤여야 함
  A를 정렬하면 이미 증가 순서 → B도 증가 순서여야 함
  = B의 LIS(최장 증가 부분수열) 찾기
  
  [답]
  제거할 줄 개수 = 전체 줄 개수 - LIS 길이
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // A 위치 순서로 정렬하기 위해 페어 사용
    vector<pair<int, int>> wires(n);
    for (int i = 0; i < n; i++) {
        cin >> wires[i].first >> wires[i].second;
    }
    
    // A 위치 순서로 정렬
    sort(wires.begin(), wires.end());
    
    // B 수열 추출
    vector<int> b_seq(n);
    for (int i = 0; i < n; i++) {
        b_seq[i] = wires[i].second; // second가 A 정렬 상태에서의 B 값들
    }
    
    // DP: dp[i] = i번째 원소까지 고려했을 때 LIS 길이
    vector<int> dp(n, 1); // 이미 1로 초기화했으니 첫 FOR문 안에서 초기화할 필요 X
    
    for (int i = 1; i < n; i++) { // i = 0일 때는 원소 하나로 LIS이므로 dp[i] = 1이니 스킵
        for (int j = 0; j < i; j++) { // i의 앞에 있는 원소들을 순회하며(A 정렬 순서) 체크하며
            if (b_seq[j] < b_seq[i]) { // b가 증가했으면
                dp[i] = max(dp[i], dp[j] + 1); // LIS에 통합
            }
        }
    }
    
    // LIS의 최댓값
    int LIS_length = *max_element(dp.begin(), dp.end());
    
    // 제거할 줄의 최소 개수
    int answer = n - LIS_length;
    
    cout << answer;
}