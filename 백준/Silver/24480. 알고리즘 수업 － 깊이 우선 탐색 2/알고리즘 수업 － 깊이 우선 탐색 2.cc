#include <bits/stdc++.h>
using namespace std;

/*
    n : 정점의 개수
    m : 간선의 개수
    r : DFS를 시작할 정점 (DFS 트리의 루트)
*/
int n, m, r;

/*
    adj[i] :
    정점 i와 인접한 정점들의 목록
    → 그래프를 "인접 리스트"로 표현 <- 정점이 많아서 인접행렬 방식은 메모리 초과 가능성.
*/
vector<vector<int>> adj;

/*
    visited[i] :
    정점 i가 이미 DFS 탐색 트리에 포함되었는지 여부
    → "이미 트리에 그린 노드인지" 체크 -> 만약 이미 그린 노드를 또 추가하면 dfs 트리가 망가져버리니.
*/
vector<int> visited;

/*
    order[i] :
    정점 i가 DFS에서 몇 번째로 방문되었는지 기록
    → preorder 방문 순서
*/
vector<int> order;

/*
    cnt :
    방문 순서를 매기기 위한 전역 카운터
*/
int cnt = 1;

/*
    dfs(u) :
    정점 u를 루트로 하는 DFS 탐색 수행
    → DFS 탐색 트리에서 u를 하나의 노드로 추가
*/
void dfs(int u) {

    // ===== (1) 함수에 들어오는 순간 =====
    // → preorder, "노드 방문"에 해당

    visited[u] = 1;        // u는 이제 DFS 트리에 포함됨
    order[u] = cnt++;      // 방문 순서 기록 (preorder)

    // ===== (2) 자식 노드들 탐색 =====
    // adj[u]는 이미 오름차순 정렬되어 있음
    // → "인접 정점은 오름차순으로 방문" 조건 충족
    for (int v : adj[u]) {

        // 아직 DFS 트리에 포함되지 않은 정점만 자식으로 삼음
        if (!visited[v]) {

            // dfs(v)를 호출하는 순간:
            // 스택 DFS에서는 v를 push하는 것과 동일
            dfs(v);
        }
    }

    // ===== (3) 함수 종료 =====
    // → 모든 자식을 다 처리하고 부모로 돌아감
    // (스택 DFS에서는 더 이상 할 일 없어서 pop된 상태와 동일)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> r;

    /*
        adj.resize(n + 1)

        왜 n+1 이냐?
        → 정점 번호가 1부터 n까지이기 때문
        → 인덱스 0은 버리고 1~n만 사용

        adj[1] ~ adj[n] 각각이
        "정점 i의 인접 정점 목록"이 됨
    */
    adj.resize(n + 1);

    /*
        visited.resize(n + 1, 0)

        두 번째 인자 0의 의미:
        → 모든 정점을 "아직 방문 안 함" 상태로 초기화

        visited[i] == 0 :
        아직 DFS 트리에 안 들어감
    */
    visited.resize(n + 1, 0);

    /*
        order.resize(n + 1, 0)

        방문하지 않은 정점은
        문제 조건에 따라 0을 출력해야 하므로
        기본값을 0으로 설정
    */
    order.resize(n + 1, 0);

    // ===== 간선 입력 =====
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // 무방향 그래프이므로 양쪽 다 추가
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*
        인접 정점 내림차순 정렬

        이게 없으면:
        → 같은 그래프, 같은 시작 정점이어도
        → DFS 탐색 트리와 방문 순서가 달라질 수 있음

        즉:
        DFS 트리를 "유일하게" 만들어주는 핵심 조건
    */
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    // ===== DFS 탐색 시작 =====
    // r을 루트로 하는 DFS 탐색 트리 생성
    dfs(r);

    // ===== 결과 출력 =====
    for (int i = 1; i <= n; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}
