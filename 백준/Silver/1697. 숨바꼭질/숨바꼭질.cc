#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K; // N은 출발 위치, K는 목표 위치

    const int MAX = 100000; // 위치는 0 이상 10만 이하임. 최대값인 10만은 상수처리
    vector<int> time(MAX + 1, -1); // 시간기록 + 방문여부 체크하는 visited 배열의 역할도 포함한다.
    // 시간 기록을 위해 0부터 10만까지 총 100001칸이 필요하다. (초기화 값인 -1 = 미방문) 
    
    // bfs를 위한 큐 준비
    queue<int> q;
    q.push(N); // 초기위치 푸시
    time[N] = 0; // 시작 위치에서의 시간은 0초

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) break; // 목표위치에 도달했으면 탈출.

        // 하나의 위치는 다음 위치가 방문한 적 없고, 범위 내라는 조건에 한해서 3개까지 자식 위치를 가질 수 있다. 
        int nexts[3] = { cur - 1, cur + 1, cur * 2 }; // 앞뒤로 한칸 가거나, 순간이동(2배)하거나 둘 다 1초 소비된다.
                                                        // 이때 1초는 간선의 가중치가 1이라고 볼 수 있다.

        for (int i = 0; i < 3; i++) {
            int next = nexts[i];

            if (next < 0 || next > MAX) continue; // 계산한 위치가 범위를 벗어나면 방문하지 않는다. 탐색 트리에 없는 셈이다.
            if (time[next] != -1) continue; // -1 즉 미방문이 아니라면 => 방문했던 위치니 방문하지 않는다. 트리를 유지하지 위함.

            time[next] = time[cur] + 1; // 현재 노드까지 걸린 시간 + 1초 = 다음 노드에 가는데 걸린 총 시간.
            q.push(next); // 그 위치에서 다음 이동할 위치 계산을 위해 푸시해줘야 한다.
        }
    }

    cout << time[K] << '\n'; // K 위치에 도달했을 때 총 걸린 시간을 기록했으므로 그대로 출력하자.
}
