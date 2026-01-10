#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    // C와 C++의 입출력 동기화를 끊어서 cin/cout 속도 향상
    cin.tie(nullptr);
    // cin과 cout의 묶음을 해제 → 입력 후 자동 flush 방지 → 속도 향상

    /*
        입력:
        N: 정점 수 (5 ≤ N ≤ 100,000)
        M: 간선 수 (1 ≤ M ≤ 200,000)
        R: 시작 정점 (1 ≤ R ≤ N)

        N이 최대 100,000이므로
        인접 행렬(N^2)은 메모리 초과 → 인접 리스트 사용
    */
    int N, M, R;
    cin >> N >> M >> R;

    /*
        graph[i] : 정점 i와 연결된 정점들의 목록
        크기를 N+1로 잡는 이유:
        - 정점 번호가 1부터 N까지이기 때문 (0번은 안 씀)
    */
    vector<vector<int>> graph(N + 1);

    /*
        간선 입력
        무방향 그래프이므로
        u → v, v → u 둘 다 추가
    */
    // 간선 수가 M개이므로 M회 반복으로 인접리스트의 각 정점에 간선 노드 추가.
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        
        // 학교 강의에서 다룬 인접 리스트 구현에서는 원래 있던 노드 앞에 추가하는 식인데 
        // 여기서는 push_back을 사용한다. 어차피 이후 55행에서 소트를 하기 때문에 특정 정점에서의 간선 노드들이
        // 어떤 순서를 가지는지 중요하지는 않다.
        graph[u].push_back(v); // u와 v 연결
        graph[v].push_back(u); // v와 u 연결
    }

    /*
        "정점 번호가 작은 것부터 방문" => "오름차순"
        인접 리스트의 각 정점 노드(벡터)를 미리 "오름차순" 정렬해야 함
    */
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    // order[i]: 
    // 정점 i가 몇 번째로 방문되었는지 저장
    // 정점 0은 없음 + 방문 안하는 경우를 처리하기 위해 사용하려 함.
    // N+1로 크기 지정. 0으로 초기화.
    // order 에는 정점번호가 들어간다. **
    vector<int> order(N + 1, 0);
    
    // BFS는 큐 FIFO 사용
    // q 에는 정점번호가 들어간다. **
    queue<int> q;

    int cnt = 1;
    // 방문 순서 카운터
    // 문제에서 방문 순서는 1부터 시작

    order[R] = cnt++;
    // 시작 정점 R을 첫 번째로 방문
    // prefix라서 시작 정점 R에는 1이 들어가고 이후 증가된다.
    // 다음 방문 번호로 미리 증가시킨 것이다.

    q.push(R);
    // BFS 시작점 큐에 삽입

    // BFS 시작
    while (!q.empty()) { // q에 정점이 남아있으면
        int cur = q.front();
        // 현재 탐색 중인 정점. 처음에는 R이 cur이 될 것이다.

        q.pop();
        // 큐에서 제거 (이제 cur의 인접 정점 탐색). 처음에는 R을 제거한다.

        // 앞에서 소트했기 때문에 오름차순으로 방문
        for (int next : graph[cur]) { // 현재 정점과 이어지는 다음 정점 = next, 처음에는 R의 다음 정점을 오름차순으로 순회할 것이다.
            // 아직 방문하지 않은 정점만 처리하기위해
            // order[next] == 0면 미방문 상태라는 사실을 이용한다.
            if (order[next] == 0) { // 다음 정점 방문한 적 없으면
                order[next] = cnt++; // 방문 처리 + 방문 순서 기록
                q.push(next); // 다음 레벨에서 탐색하도록 큐에 추가
                // order의 인덱싱, q 내부에는 모두 정점번호가 들어간다.
            }
        }
    }

    /*
        각 정점(1~N)의 방문 순서 출력
        방문되지 않은 정점은 0 그대로 출력됨
    */
    for (int i = 1; i <= N; i++) {
        cout << order[i] << '\n';
    }
    return 0;
}
