#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> seq;

void dfs(int start) {
    if (seq.size() == M) {
        for (int x : seq) cout << x << ' ';
        cout << '\n';
        return;
    }

    // start부터 시작 → 이전 값보다 작아지지 않음
    for (int i = start; i <= N; i++) {
        seq.push_back(i);
        dfs(i);      // ★ 중복 허용 → i 그대로
        seq.pop_back();
    }
}

int main() {
    cin >> N >> M;
    dfs(1);
}
