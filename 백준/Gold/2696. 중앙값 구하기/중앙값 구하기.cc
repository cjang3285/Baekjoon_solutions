#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int M;
        cin >> M;

        priority_queue<int> left; // 작은 절반 (maxHeap)
        priority_queue<int, vector<int>, greater<int>> right; // 큰 절반 (minHeap)

        vector<int> ans;

        for (int i = 1; i <= M; i++) {
            int x;
            cin >> x;

            // 1) 값 기준 분기 (중앙 경계 기준)
            if (left.empty() || x <= left.top())
                left.push(x);
            else
                right.push(x);

            // 2) 크기 균형 (불변식 유지)
            if (left.size() > right.size() + 1) {
                right.push(left.top());
                left.pop();
            }
            else if (right.size() > left.size()) {
                left.push(right.top());
                right.pop();
            }

            // 3) 홀수 번째 → 중앙값
            if (i % 2 == 1)
                ans.push_back(left.top());
        }

        // 출력
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
            if ((i + 1) % 10 == 0) cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
