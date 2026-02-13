#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // A[i] : 원본 수열 (1-indexed)
    vector<int> A(N + 1);

    // LIS[i] : i번째 원소를 "마지막"으로 하는 최장 증가 부분 수열 길이
    vector<int> LIS(N + 1);

    // LDS[i] : i번째 원소를 "시작"으로 하는 최장 감소 부분 수열 길이
    vector<int> LDS(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    /* =======================
       1. LIS 계산
       =======================
       dp[i] = i를 끝으로 하는 LIS
       -> i보다 왼쪽(j < i) 중
          A[j] < A[i] 인 것들 중
          LIS[j] 최대값 + 1
    */
    for (int i = 1; i <= N; i++) {
        LIS[i] = 1;  // 자기 자신만 선택하는 경우 (길이 1)
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    /* =======================
       2. LDS 계산
       =======================
       dp[i] = i를 시작으로 하는 LDS
       -> i보다 오른쪽(j > i) 중
          A[j] < A[i] 인 것들 중
          LDS[j] 최대값 + 1

       뒤에서부터 도는 이유:
       "i 다음" 상태들이 이미 계산돼 있어야 하기 때문
    */
    for (int i = N; i >= 1; i--) {
        LDS[i] = 1;  // 자기 자신만 선택
        for (int j = N; j > i; j--) {
            if (A[j] < A[i]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    /* =======================
       3. 바이토닉 결합
       =======================
       i를 중심으로:
       LIS[i] (증가)
     + LDS[i] (감소)
     - 1 (A[i] 중복 제거)
    */
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, LIS[i] + LDS[i] - 1);
    }

    cout << answer;
}
