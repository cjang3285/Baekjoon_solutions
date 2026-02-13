#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    /*
        A[i] : 입력 수열
        - 입력 수열은 아무 구조도 보장되지 않은 무작위 수열
        - 바이토닉 구조는 입력의 성질이 아니라
          우리가 만들어야 할 출력(부분수열)의 성질
    */
    vector<int> A(N + 1);

    /*
        LIS[i] : i번째 원소를 마지막으로 하는
                 최장 증가 부분수열 길이
    */
    vector<int> LIS(N + 1);

    /*
        LDS[i] : i번째 원소를 시작으로 하는
                 최장 감소 부분수열 길이
    */
    vector<int> LDS(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    /* 
       1. LIS 계산 (왼쪽 → 오른쪽)

       초기 착각:
       바이토닉이면 최대값이 중심 아닐까?
        하지만,
       - 최대값이 중심이라는 보장은 전혀 없음
       - 산이 울퉁불퉁한 무작위 수열이라면?
       - 그러므로 모든 i가 중심 후보

       그래서 모든 i를 끝점으로 하는 LIS를 전부 계산
       LDS 계산도 마찬가지
    */
    for (int i = 1; i <= N; i++) {
        LIS[i] = 1;  // 자기 자신만 선택하는 경우
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    /* 
       2. LDS 계산 (왼쪽 <- 오른쪽)
       문제에서 필요한 LDS 정의는

       "i를 시작으로 하는 감소 수열"

       - i보다 오른쪽 값을 참조하며 최장 길이를 찾아야 함
       - 그래서 계산 순서가 자동으로
         앞 <= 뒤로 결정됨
    */
    for (int i = N; i >= 1; i--) {
        LDS[i] = 1;  // 자기 자신만 선택
        for (int j = N; j > i; j--) {
            if (A[j] < A[i]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    /* 
       3. 바이토닉 결합

       각 i를 중심으로:
           증가: LIS[i]
           감소: LDS[i]
       바이토닉 길이:
           LIS[i] + LDS[i] - 1
       -1 이유:
       중심 A[i]가
       증가 부분과 감소 부분에
       두 번 포함되므로 중복 제거
       
       최종 답:
       모든 i를 중심 후보로 두고
       그중 최대값
    */
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, LIS[i] + LDS[i] - 1);
    }

    cout << answer;
}
