#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    /*
    priority_queue<int, vector<int>, greater<int>>

    - pq는 "하나의 힙 객체"
    - vector<int>는 노드가 아니라 → 전체 노드들을 담는 저장소
    - vector의 원소 하나 = 트리의 노드 하나 = 값 하나

    구조 개념:

        priority_queue (딱 하나)
             │
             └── 내부 vector 하나
                    [0] 값 하나 → 루트 노드
                    [1] 값 하나 → 왼자식
                    [2] 값 하나 → 오른자식

    ❌ 노드 안에 여러 값이 있는 게 아님  
    ❌ pq 여러 개가 트리로 연결된 것도 아님  
    ⭕ 값들이 vector 안에서 "트리 모양으로 해석"될 뿐
    */

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

    while(n--) {
        int x;
        cin >> x;

        if(x == 0) {
            // top()은 "vector 전체 탐색"이 아니라
            // 항상 vector[0] = 루트 = 최소값
            if(pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";   // O(1)
                pq.pop();                   // sift-down → O(log N)
            }
        }
        else {
            pq.push(x); // push_back + sift-up → O(log N)
        }
    }
}
