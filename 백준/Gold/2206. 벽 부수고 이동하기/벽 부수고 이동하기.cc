#include <bits/stdc++.h>
using namespace std;

// state: (x, y, broken)
// broken = 0 아직 안 부숨
// broken = 1 이미 부숨

int n, m;
int board[1001][1001];
int dist[1001][1001][2];   // dist[x][y][broken]

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs() {
    queue<tuple<int,int,int>> q;
    
    q.push({1,1,0});
    dist[1][1][0] = 1;   // 시작도 거리 1로 카운트

    while(!q.empty()) {
        auto [x,y,broken] = q.front();
        q.pop();

        // 도착
        if(x == n && y == m)
            return dist[x][y][broken];

        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

        if(nx < 1 || ny < 1 || nx > n || ny > m)
            continue;

            // 1. 다음 칸이 길(0)인 경우
            if(board[nx][ny] == 0 
               && dist[nx][ny][broken] == 0) {
                
                dist[nx][ny][broken] = dist[x][y][broken] + 1; // 방문체크
                q.push({nx, ny, broken});
            }

            // 2. 다음 칸이 벽(1)이고 아직 안 부순 상태고 방문체크(dist) 안했으면
            if(board[nx][ny] == 1 
               && broken == 0 
               && dist[nx][ny][1] == 0) {
                
                dist[nx][ny][1] = dist[x][y][0] + 1; // 방문체크
                q.push({nx, ny, 1});
            }
        }
    }

    return -1;   // 도달 불가
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        string s; cin >> s;
        for(int j=1;j<=m;j++)
            board[i][j] = s[j-1] - '0';
    }
    cout << bfs();
}
