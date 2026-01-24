#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> coin(N);
    for (int i = 0; i < N; i++) cin >> coin[i];

    int cnt = 0;

    // 큰 동전부터
    for (int i = N - 1; i >= 0; i--) {
        cnt += K / coin[i];
        K %= coin[i];
    }

    cout << cnt;
}
