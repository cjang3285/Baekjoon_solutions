#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int l;
        cin >> l;

        int sx, sy;
        cin >> sx >> sy;
        int sp = sy * l + sx;

        int tx, ty;
        cin >> tx >> ty;
        int tp = ty * l + tx;

        vector<int> MoveCnt(l * l, -1);
        queue<int> q;

        q.push(sp);
        MoveCnt[sp] = 0;

        // 나이트 이동 8방향
        int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
        int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

        while (!q.empty()) {
            int cp = q.front(); q.pop();

            if (cp == tp) {
                cout << MoveCnt[cp] << '\n';
                break;
            }
            // 여기선 괜찮은 이유는 cp는 코드 진행상 항상 검증된 p이기 때문.
            int cx = cp % l;
            int cy = cp / l;

            for (int d = 0; d < 8; d++) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                // 반드시 좌표 상태에서 먼저 검사
                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;

                int np = ny * l + nx;

                if (MoveCnt[np] != -1) continue;

                MoveCnt[np] = MoveCnt[cp] + 1;
                q.push(np);
            }
        }
    }
    return 0;
}