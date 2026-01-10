#include <bits/stdc++.h>
using namespace std;

int n, m, v;

// vector<int> 타입의 변수를 1001개 가진 배열
// adj[0]  = vector<int>
// adj[1]  = vector<int>
// adj[2]  = vector<int> ...
// 각 adj[i] 자체가 vector 객체

/*
“배열이면 크기 고정 아니냐?” → 오해 포인트
고정되는 것 - 벡터의 개수 (1001개) → 고정
고정되지 않는 것 - 각 벡터 안의 원소 개수
push_back, pop_back, resize 전부 가능
adj[3].push_back(10);
adj[3].push_back(20); 힙 메모리 재할당까지 다 일어남.
*/

vector<int> adj[1001];
bool visited[1001];

// 재귀 dfs라 현재 노드(재귀 고려) 기준의 로직 구성
void dfs(int cur) {
    visited[cur] = true; // 함수 진입이 곧 방문을 의미, 방문 체크
    cout << cur << ' '; // 방문 출력
    for (int next : adj[cur]) { // 다음 정점을 오름차순으로 순회하며 
        if (!visited[next]) { // 방문 안 한 정점에 대해 
            dfs(next); // dfs 콜
        }
    }
}
 
// 재귀없이 큐로 탐색이라 start
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (int next : adj[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // n 정점수 m 간선수 v 시작정점
    cin >> n >> m >> v;
    
    // m개의 간선 푸시
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);// a에서 b로
        adj[b].push_back(a);// b에서 a로
    }
    
    // 모든 정점에 대하여 해당 정점에서 다음 정점으로 방문 시 오름차순으로 방문하도록 소팅
    for (int i = 1; i <= n; i++) { // adj[1~n]를 사용하므로
        sort(adj[i].begin(), adj[i].end()); // 소팅 기본은 오름차순.
    }
    // 첫째 줄에 DFS를 수행한 결과를,
    dfs(v);
    cout << '\n';
    
    // memset으로 방문 체크 
    memset(visited, false, sizeof(visited));
    
    // 그 다음 줄에는 BFS를 수행한 결과를
    bfs(v);
}
