#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // 시작 정수 N
    cin >> N;

    // 인덱스를 현재 수로 할 수 있는 이유는 
    // BFS 특성상 어떤 수(인덱스)에 처음 도달하면 그게 곧 최단 연산횟수를 의미하기 때문  
    // 그리고 같은 인덱스에 중복 접근할 일이 없음. 
    // 미방문인 경우만 분기하기 때문에 사이클 생성되지 않음.
    vector<int> visited(N + 1, -1); // 인덱스는 현재 수 : 값은 현재 수에 도달하기까지의 연산횟수
    queue<int> q;

    q.push(N); // 주어진 시작 정수 N
    visited[N] = 0; // 처음은 연산 횟수 0로 시작

    while (!q.empty()) { // BFS
        int x = q.front(); // 처음은 x = 시작 정수로 시작
        q.pop();

        if (x == 1) { // 1에 도착했으면 끝이니
            cout << visited[x]; // 1에서의 연산횟수 출력
            return 0;
        }
        
        // 아직 1이 아니면
        // 3개의 자식노드가 가능. 최소 1개 자식노드 가짐.
        
        // 1. x - 1 빼도 1 이상이고 미방문이면
        if (x - 1 >= 1 && visited[x - 1] == -1) {
            visited[x - 1] = visited[x] + 1;
            q.push(x - 1);
        }

        // 2. x / 2 나누어 떨어지고 미방문이면
        if (x % 2 == 0 && visited[x / 2] == -1) {
            visited[x / 2] = visited[x] + 1;
            q.push(x / 2);
        }

        // 3. x / 3 나누어 떨어지고 미방문이면
        if (x % 3 == 0 && visited[x / 3] == -1) {
            visited[x / 3] = visited[x] + 1;
            q.push(x / 3);
        }
        
        // if문들이 끝인 이유는?
        // “상태 전이 함수만 정확히 정의하면
        // 나머지는 자료구조와 BFS 모델이 알아서 최적해를 만들어준다.”
        // → 최단경로 보장
        // → 레벨 순회
        // → 중복은 패스
        // → 종료 조건 관리
    }
}
