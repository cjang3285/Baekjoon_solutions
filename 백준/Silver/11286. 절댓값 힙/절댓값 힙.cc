#include <bits/stdc++.h>
using namespace std;

/*
핵심 규칙:
comp(a, b) == true
→ a는 b보다 덜 중요
→ 힙 트리에서 아래로 내려간다.

그래서 우리는:
"a가 b와 비교해서 이럴 때 a를 아래로 보내고 싶은 조건"을 그대로 true가 들어간 자리에 true 대신 넣어주면 된다.
*/

struct abs_less {
    bool operator()(int a, int b) {

        /*
        [문제 중요도 정의]

        1) 절댓값이 작은 값이 더 중요 (위로)
           → 절댓값이 큰 값은 덜 중요 (아래로)

           따라서:
           |a| > |b| 이면 a는 덜 중요 → true
        */

        if (abs(a) == abs(b)) {
            /*
            2) 절댓값이 같으면
               실제값이 작은 값이 더 중요 (위로)
               실제값이 큰 값은 덜 중요 (아래로)

               따라서:
               a > b 이면 a는 덜 중요 → true
            */
            return a > b;
        }

        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, abs_less> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
}
