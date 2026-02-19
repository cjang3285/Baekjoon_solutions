#include <iostream>
#include <cmath>
using namespace std;

int N;
int S[20][20];
bool selected[20];   // true: 팀 A, false: 팀 B
int answer = 1e9;

/*
    조합이 완성되었을 때 두 팀의 능력치 차이를 계산한다.
    이 함수의 이중 for문은 탐색이 아니라 단순 점수 계산이다.
*/
void calculate() {
    int teamA = 0;
    int teamB = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            // 두 사람 모두 팀 A에 속한 경우
            if (selected[i] && selected[j])
                teamA += S[i][j] + S[j][i];

            // 두 사람 모두 팀 B에 속한 경우
            if (!selected[i] && !selected[j])
                teamB += S[i][j] + S[j][i];
        }
    }

    answer = min(answer, abs(teamA - teamB));
}

/*
    start: 이번 단계에서 선택을 시작할 인덱스
           (이전 단계에서 선택한 인덱스보다 작은 값은 보지 않음 → 중복 방지)

    depth: 현재까지 선택한 인원 수
*/
void backtrack(int start, int depth) {

    // N/2명을 선택하면 조합 완성
    if (depth == N / 2) {
        calculate();
        return;
    }

    // start부터 N-1까지 다음 후보를 하나씩 선택
    for (int i = start; i < N; i++) {

        selected[i] = true;               // i번 사람을 팀 A에 포함

        backtrack(i + 1, depth + 1);      // 다음 인원 선택 단계로 진행

        selected[i] = false;              // 원상복구 (다음 경우의 수를 위해 상태 되돌림)
    }
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    backtrack(0, 0);   // 아무도 선택하지 않은 상태에서 시작

    cout << answer;
}
