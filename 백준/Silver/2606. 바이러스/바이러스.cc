#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> infected(n + 1, 0); // 0이면 미감염, >0이면 감염 순서

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    int order = 1;

    q.push(1);
    infected[1] = order; // 1번 컴퓨터 감염 (감염원)

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (infected[next] == 0) { // 아직 감염 안 됨
                infected[next] = ++order;
                q.push(next);
            }
        }
    }

    // 1번 컴퓨터 제외
    cout << order - 1 << '\n';
}
