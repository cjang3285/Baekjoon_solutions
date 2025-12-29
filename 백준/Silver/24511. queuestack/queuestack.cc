#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    /*
        핵심 아이디어:

        - 스택(1)은 값이 절대 밖으로 나오지 않고 그냥 통과.
        - 큐(0)에 있던 값들만이 swap되며 결국 출력으로 나온다.

        중요한 관찰:
        입력 하나가 들어오면 여러 큐를 거쳐서
        "가장 마지막 큐"에 있던 값이 먼저 출력된다.

        따라서 출력 순서는:
        (뒤쪽 큐 값들부터) -> (앞쪽 큐 값들) -> (입력값들)
    */

    queue<int> q;

    // 큐(0) 위치의 값들을 "뒤에서부터" 넣는다.
    // 이렇게 해야 q.front()가 실제로 가장 먼저 출력될 값이 된다.
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            q.push(b[i]);
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int x;
        cin >> x;

        q.push(x);                 // 새 입력은 뒤에
        cout << q.front() << " "; // 가장 앞 값이 출력
        q.pop();
    }

    return 0;
}
