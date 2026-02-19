#include <iostream>
#include <cmath>
using namespace std;

int N;
int S[20][20];
bool selected[20];  // t: 팀A, f: 팀B. 초기 상태는 전부 f
int answer = 1e9;

// 조합 완성 시 호출. 탐색과 무관한 단순 점수 계산.
void calculate() {
    int teamA = 0;
    int teamB = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (selected[i] && selected[j])
                teamA += S[i][j] + S[j][i];
            if (!selected[i] && !selected[j])
                teamB += S[i][j] + S[j][i];
        }
    }

    answer = min(answer, abs(teamA - teamB));
}

// start: 이번 단계에서 선택 시작할 인덱스
//        손으로 조합 쓸 때 "앞 숫자 다음부터" 와 동일
//        중복 방지. 1선택 후 0으로 못 돌아감.
//
// dep: 현재까지 t의 개수 (선택된 인원 수)
//      dep+1을 인자로 넘기는 방식이라 함수 안 dep는 불변.
//      return 후 올라오면 이전 dep 그대로 유지됨.
void backtrack(int start, int dep) {

    // dep == N/2 인 순간 selected에 t가 정확히 N/2개.
    // dep+1을 넘겨받은 시점에 이미 선택 완료 상태이므로 N/2+1 아님.
    if (dep == N / 2) {
        calculate();
        return;
    }

    for (int i = start; i < N; i++) {

        selected[i] = true;           // f → t. 팀A에 포함.

        backtrack(i + 1, dep + 1);    // 이 호출이 끝날 때까지 다음 i로 못 넘어감.
                                      // 한 분기 전체를 끝내고 나서야 i++ 됨.

        selected[i] = false;          // t → f. 복구.
                                      // 안 하면 다음 경우의 수에서 이전 t가 남아 조합 오염.
    }
    // 손으로 조합 쓰면 (N=8, 4명):
/* 1~8
    1 2 3 45678
    1 2 4 5678
    1 2 5 678
    1 2 6 78
    1 2 7 8 <= 12 끝
    1 3 4 5678
    1 3 5 678
    1 3 6 78
    1 3 7 8 <= 13 끝
    1 4 5 678
    1 4 6 78
    1 4 7 8 <= 14 끝
    1 5 6 78
    1 6 7 8 <= 16 끝. 1로 시작하는 모든 경우 끝
    이제 2로 시작 1로 시작 금지
    2 3 4 5678
    2 3 5 678
    2 3 6 78
    2 3 7 8
    2 4 5 678
    2 4 6 78
    2 4 7 8
    2 5 6 78
    2 5 7 8
    2 6 7 8 <= 2끝
    3 4 5 678
    3 4 6 78
    3 4 7 8
    3 5 6 78
    3 5 7 8
    3 6 7 8
    4 5 6 78
    4 5 7 8
    5 6 7 8
*/
    // 앞 숫자 정해지면 뒤는 항상 그 다음 번호부터 시작.
    // 이게 backtrack(i+1, dep+1) 이고 start의 역할.
    //
    // 대략적인 런타임 흐름 (N=4, 2명):
    // [f f f f]  시작
    // [t' f f f]  selected[0]=true
    // [t t' f f]  selected[1]=true  => dep==2, return
    // [t f' f f]  selected[1]=false (cancel)
    // [t f t' f]  selected[2]=true  => dep==2, return
    // [t f f' f]  selected[2]=false (cancel)
    // [t f f t']  selected[3]=true  => dep==2, return
    // [t f f f']  selected[3]=false (cancel)
    // [f' f f f]  selected[0]=false (cancel)
    // [f t' f f]  selected[1]=true
    // [f t t' f]  selected[2]=true  => dep==2, return
    // [f t f' f]  selected[2]=false (cancel)
    // [f t f t']  selected[3]=true  => dep==2, return
    // [f t f f']  selected[3]=false (cancel)
    // [f f f f]  selected[1]=false (cancel)
    // [f f t' f]  selected[2]=true
    // [f f t t']  selected[3]=true  => dep==2, return
    // [f f f' f']  selected[2]=false, selected[3]=false (cancel)
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    backtrack(0, 0);  // 전부 f인 상태에서 시작

    cout << answer;
}
