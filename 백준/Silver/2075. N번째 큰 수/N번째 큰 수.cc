#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 최소 힙 (top = 가장 작은 값)
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N * N; i++) {
        int x;
        cin >> x;
        pq.push(x);

        // N개가 다 찬 이후로, push pop 사이에서
        
        // 만약 x가 pq에 차있는 N개 전부랑 비교해도 "제일 작으면", 
        // 상향이동을 반복하여 조건문에서 바로 "팝된다".
        
        // 제일 작지 않으면, x는 남고
        // x가 아닌 "제일 작은 값이 팝된다".
        
        // 결국 어떤 값이 추가되어도 x든 x가 아닌 제일 작은 값이든 팝되고
        // 그때까지 입력된 값들 중 제일 큰 값 N개만 pq에 살아남는 것이다.
        if ((int)pq.size() > N) {
            pq.pop();
        }
    }

    // 그렇게 남은 pq에 pq.top()은 N번째 큰 수이다.
    cout << pq.top() << "\n";
    return 0;
}
