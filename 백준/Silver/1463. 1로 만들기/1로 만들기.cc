#include <bits/stdc++.h>
using namespace std;

/*

N = 10 기준:

dp[1] = 0
dp[2] = dp[1] + 1
dp[3] = min(dp[2], dp[1]) + 1
dp[4] = min(dp[3], dp[2]) + 1
dp[5] = dp[4] + 1
dp[6] = min(dp[5], dp[3], dp[2]) + 1
dp[7] = dp[6] + 1
dp[8] = min(dp[7], dp[4]) + 1
dp[9] = min(dp[8], dp[3]) + 1
dp[10] = min(dp[9], dp[5]) + 1

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    // bfs에서 사용한 visited 배열과 같음. 인덱스는 현재 수, 값은 그 수까지 오는데 한 연산횟수.
    vector<int> dp(N + 1); // 모든 수 연산횟수는 0으로 초기화됨
    dp[1] = 0; // 현재 수를 N로 시작하는 bfs와 반대로 1로 시작

    for (int i = 2; i <= N; i++) { // 현재 수를 1씩 올리며 최소 연산횟수만 min으로 남기며 나아간다.
        // 무조건 가능한 연산으로 먼저 연산횟수를 채운다.
        /*
            “-1 연산이 있어야
            dp[i] 계산할 때 dp[i-1]을 참고할 수 있고
            그래야 dp 배열이 안 끊긴다” 
            
            -1 연산이 없었다면 
            다음 수의 dp 값 계산과정에서 참조할 이전 dp 값이 없어질 수 있고 그러면 연산이 끊어진다.
            
            Bottom-up DP가 가능하려면
            모든 상태가
            “이전 상태들로부터 도달 가능”해야 한다.
        */    
        dp[i] = dp[i - 1] + 1;   
        // 마지막 pass에서 dp[N]에 N에 도달하기까지 시도된 최소 연산횟수가 채워질 것이다.
        
        // 그리고 2로 나누거나 3으로 나눌 수 있는 경우의 연산횟수랑 비교해서 
        // 만약 1을 더한 경우보다 연산횟수가 적다면 적은 수로 채택한다
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1); // 1을 더한 경우와 2로 나눈 경우 중 더 연산횟수가 더 적은 경우를 i(다음 수)의 연산횟수(값)으로 넣어주자.

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1); // 1을 더한 경우와 3로 나눈 경우 중 더 연산횟수가 더 적은 경우를 i(다음 수)의 연산횟수(값)으로 넣어주자.
    }

    cout << dp[N];
}

/* BFS로 푼다면?
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
*/
