#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);      // 인접 리스트
    vector<int> indegree(n + 1, 0);      // 각 노드의 진입차수
    
    // 간선 입력
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    
    // 위상정렬 (Kahn's 알고리즘)
    queue<int> q;
    
    // 진입차수가 0인  i 노드들을 큐에 추가. 가장 먼저 방문하기 위함.
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    // bfs 탐색트리에서 레벨을 indegree로 하여 탐색하는 경우.
    // indegree가 0인 노드들이 루트로서 레벨 0에 쭉 있다.
    // 각 루트 노드들을 출력하면서 그 루트의 인접 노드들의 차수를 1씩 줄이고 
    // 만약 줄여서 이번에 0이 된 노드가 있으면 큐에 추가한다. 
    // -> 당장 처리 중인 indegree 값을 기준으로 레벨을 나눈다면 
    // 맨 뒤에 추가된 노드는 다음 레벨이라고 볼 수 있다 
    // 현재 indegree 레벨의 노드들이 전부 처리된 뒤에야 
    // 그 다음 indegree 레벨에 추가한 노드를 처리한다. bfs의 레벨 개념을 생각하자.
    
    // 큐가 빌 때까지 처리
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " "; // 진입차수가 0인 노드들을 가장 먼저 방문하게 됨.
        
        // 현재 노드에서 나가는 간선들 처리
        for(int next : adj[curr]){ // 방문한 노드의 다음으로 오는 노드들 중
            indegree[next]--; // 진입차수가 1 줄었을때
            if(indegree[next] == 0){ // 바로 방문 가능하면
                q.push(next); // 다음 indegree 레벨에 추가.
            }
        } // 만약 현재 노드에서 나가는 간선들이 없으면 for문 통째로 스킵된다.
    }
    
    cout << "\n";
    
    return 0;
}