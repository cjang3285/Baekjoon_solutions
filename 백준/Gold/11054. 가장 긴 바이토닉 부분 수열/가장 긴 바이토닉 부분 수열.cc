#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    vector<int> LIS(N + 1);
    vector<int> LDS(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        LIS[i] = 1;  // 자기 자신만 선택하는 경우
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    for (int i = N; i >= 1; i--) {
        LDS[i] = 1;  // 자기 자신만 선택
        for (int j = N; j > i; j--) {
            if (A[j] < A[i]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, LIS[i] + LDS[i] - 1);
    }

    cout << answer;
}
