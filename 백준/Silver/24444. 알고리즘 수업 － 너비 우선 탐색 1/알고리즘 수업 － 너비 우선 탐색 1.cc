#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> order(N + 1, 0);
    queue<int> q;

    int cnt = 1;
    order[R] = cnt++;
    q.push(R);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (order[next] == 0) {
                order[next] = cnt++;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}
