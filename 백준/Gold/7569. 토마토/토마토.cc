#include <bits/stdc++.h>
using namespace std;

int M, N, H; // M: x(가로), N: y(세로), H: z(높이)

// state[z][y][x]
//  1 : 익은 토마토
//  0 : 안 익은 토마토
// -1 : 토마토 없음
int state[101][101][101];

// ripe_date[z][y][x] : 이 칸의 토마토가 익은 날짜
int ripe_date[101][101][101];

int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dx[6] = {0, 0, 1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;

    queue<tuple<int, int, int>> q;

    // 입력 + 초기 BFS 시작점 설정
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> state[z][y][x];
                ripe_date[z][y][x] = 0;

                // 이미 익은 토마토는 동시에 시작
                if (state[z][y][x] == 1) {
                    q.push({z, y, x});
                }
            }
        }
    }

    // BFS
    while (!q.empty()) {
        auto [z, y, x] = q.front();
        q.pop();

            for (int dir = 0; dir < 6; dir++) {
                int nz = z + dz[dir];
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)
                    continue;

            // 토마토가 아예 없는 칸 → 전파 불가
            if (state[nz][ny][nx] == -1)
                continue;

            // 이미 익은 토마토 → 다시 처리할 필요 없음
            if (state[nz][ny][nx] == 1)
                continue;

            // 여기까지 왔다는 건 "안 익은 토마토(0)"뿐
            state[nz][ny][nx] = 1;
            ripe_date[nz][ny][nx] = ripe_date[z][y][x] + 1;
            q.push({nz, ny, nx});
        }
    }

    int answer = 0;

    // 결과 확인
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                // 끝났는데도 안 익은 토마토가 남아 있다면 실패
                if (state[z][y][x] == 0) {
                    cout << -1;
                    return 0;
                }
                answer = max(answer, ripe_date[z][y][x]);
            }
        }
    }

    cout << answer;
    return 0;
}
