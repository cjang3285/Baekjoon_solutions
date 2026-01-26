#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> seq;

void dfs(int depth) {
    if (depth == M) {
        for (int x : seq) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        // 중복 허용 → 컷 없음
        seq.push_back(i);
        dfs(depth + 1);
        seq.pop_back();
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}
