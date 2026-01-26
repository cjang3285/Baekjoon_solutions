#include <bits/stdc++.h>
using namespace std;

int N, M;
bool used[10];      // used[i] = true면 i는 이미 현재 수열에 사용됨
vector<int> seq;   // 현재 탐색 중인 수열 (현재 경로)

void dfs(int depth) {
    // [종료 조건]
    // M개를 다 골랐으면 하나의 완성된 경우
    if (depth == M) {
        for (int x : seq) cout << x << ' ';
        cout << '\n';
        return; // 더 내려갈 필요 없음
    }

    // [다음 선택을 시도]
    for (int i = 1; i <= N; i++) {

        // --- 가지치기 (pruning) ---
        // 이미 쓴 숫자면, 이 분기는 규칙 위반이므로
        // 그 아래 모든 경우가 전부 불가능 → 아예 안 들어감
        if (used[i]) continue;

        // [선택한다]
        used[i] = true;   // i를 썼다고 기록
        seq.push_back(i); // 현재 경로에 i 추가

        // [다음 단계로]
        dfs(depth + 1);

        // [되돌린다] ★ 백트래킹의 핵심
        // 다른 경우의 수를 만들기 위해
        // 현재 선택을 원상복구
        seq.pop_back();
        used[i] = false;
    }
}

int main() {
    cin >> N >> M;
    dfs(0); // 아무것도 고르지 않은 상태에서 시작
}

