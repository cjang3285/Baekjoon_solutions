#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 도시의 수는 최대 400개 (1번~N번 도시)
const int MAX = 401; 

// 장부 기록용 배열들
int capacity[MAX][MAX]; // 통로의 한계치 (용량)
int flow[MAX][MAX];     // 현재 실제로 흐르는 물의 양 (유량)
int parent[MAX];        // 이번 BFS에서 어떤 도시를 거쳐왔는지 기록 (경로 역추적용)
vector<int> adj[MAX];   // 도시들 간의 연결 관계 (인접 리스트)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, P;
    cin >> N >> P;

    for (int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        
        // 1. 정방향과 역방향 모두 길을 열어줌
        adj[u].push_back(v);
        adj[v].push_back(u); 
        
        // 2. 문제 조건: 각 간선은 한 번만 쓸 수 있으므로 용량은 1 => 방문 시 72행에서 유량을 흘려서 다음 bfs부터는 그 간선을 정방향으로는 못 지나가게 함. 다만 역방향은 여전히 가능.
        capacity[u][v] = 1; 
    }

    int totalFlow = 0;
    int Start = 1;  // 출발지: 1번 도시
    int Target = 2; // 도착지: 2번 도시

    // [BFS 무한 반복] 가능한 최대한 많은 서로 다른 경로를 찾기 위해!
    while (true) {
        // 매 pass마다 방문 체크(부모 기록)를 초기화하여 새로운 경로를 발굴할 준비를 함
        fill(parent, parent + MAX, -1);
        queue<int> q;
        
        q.push(Start);

        while (!q.empty() && parent[Target] == -1) {
            int curr = q.front();
            q.pop();

            for (int next : adj[curr]) {
                // 논리 3: 정방향이든 역방향이든 '잔여 유량'이 있어야만 갈 수 있는 길로 간주함
                // (capacity - flow > 0) 이 조건이 정방향의 벽으로 인한 방문 불가와 역방향으로는 통과 기회가 있음을 모두 판별함
                if (capacity[curr][next] - flow[curr][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = curr;
                }
            }
        }

        // 논리 1: 큐가 빌 때까지 쑤셔봤는데도 Target에 도달 못 했다면?
        // 정말로 더 이상 한 방울도 보낼 수 있는 경로가 없다는 뜻이므로 항복(break)
        if (parent[Target] == -1) break;

        // 논리 2: 경로를 찾았으므로 '역전파' 느낌으로 장부를 업데이트함
        // 이 과정에서 flow[v][u]를 깎아 미래의 BFS에게 '상쇄/재배치'의 기회를 유도함
        for (int i = Target; i != Start; i = parent[i]) {
            int u = parent[i];
            int v = i;

            flow[u][v] += 1; // 정방향으로 점유함 (이제 정방향 잔여량은 0이 됨)
            flow[v][u] -= 1; // 다음 bfs에게 이 간선은 역방향으로 지나가보라고 전달함
        }
        
        // 한 번의 BFS 성공 = 하나의 경로를 완벽히 찾아내 물을 흘림
        totalFlow++;
    }

    // 최종적으로 쥐어짜낸 모든 경로의 합 출력
    cout << totalFlow << endl;

    return 0;
}