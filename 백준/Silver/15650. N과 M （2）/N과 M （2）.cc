#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> seq;   // 현재 탐색 중인 경로 (지금 트리에서 내가 서 있는 노드)

// 핵심!!: start = 다음에 선택할 수 있는 "최소 값"
// 이 값 하나로:
// 1) 오름차순 유지
// 2) 중복 방지
// 3) 구조적 pruning (애초에 잘못된 가지를 만들지 않음)
void dfs(int start) { // 핵심!!: 인자인 start

    // 리프 노드: M개를 다 고른 상태
    if (seq.size() == M) {
        for (int x : seq) cout << x << ' ';
        cout << '\n';
        return;   // 여기서부터 위로 올라가며 pop 반복될 예정
    }

    // 핵심!!: start부터만 시도 → 항상 이전 값 i보다 큰 수 i + 1 이상만 고르게 됨
    for (int i = start; i <= N; i++) {

        // 핵심!!: 여기엔 used 배열도, 오름차순으로 정렬된 건지 검사도 필요없음
        // 왜냐면,
        // 1. i는 항상 커지므로 이번 pass에서 
        // seq에 추가할 수는 무조건 이미 들어가있는 마지막 수보다 크다.
        // 2. dfs(i+1)로 start값을 받기 때문에 
        // 이전 start값인 i보다 1 큰 수가 되기 때문에 같은 숫자를 다시 쓸 경로 자체가 만들어지지 않는다.
        seq.push_back(i);

        // 다음 칸에서는 i보다 큰 값만 후보
        // → 구조 자체가 가지치기(pruning)
        dfs(i + 1);

        // 백트래킹: 상태 복구
        // 자식이 더 이상 갈 수 없으면 return되고
        // 이 pop들이 연쇄로 터진다.
        seq.pop_back();
    }
}

int main() {
    cin >> N >> M;
    dfs(1);   // 1부터 시작
}

