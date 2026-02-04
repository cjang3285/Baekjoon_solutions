#include <bits/stdc++.h>
using namespace std;

// 전역 보드: 모든 재귀 호출에서 공유되는 실제 상태
int board[9][9];

// (r, c) 위치에 x를 넣을 수 있는지 검사
bool possible(int r, int c, int x) {
    // 가로 검사: 같은 행에 x가 있으면 넣을 수 없음
    for (int j = 0; j < 9; j++)
        if (board[r][j] == x) return false;

    // 세로 검사: 같은 열에 x가 있으면 넣을 수 없음
    for (int i = 0; i < 9; i++)
        if (board[i][c] == x) return false;

    // 3x3 격자 검사
    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;
    for (int i = sr; i < sr + 3; i++)
        for (int j = sc; j < sc + 3; j++)
            if (board[i][j] == x) return false;

    return true; // 겹치는 수 없음 → 넣을 수 있음
}

// 스도쿠 완전 탐색 + 백트래킹
bool solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) { // 빈칸 발견
                // 1~9개의 자식 노드 발생
                for (int x = 1; x <= 9; x++) {
                    if (possible(i, j, x)) { // 9개 중 가능한 노드들만 추리기
                        board[i][j] = x; // 3개 남았다 치면 그 3개만 자식노드로 분기
                        
                        if (solve()) return true; // 이번 자식 노드도 또 같은 원리로 분기
                        
                        board[i][j] = 0; // 그 자식노드들이 끝에 가서 결국 잘못된 수 선택이었다면 원상복구
                        
                        // 이후 다음 자식 노드를 분기시켜 본다
                    }
                }
                return false;
            }
        }
    }
    // 모든 칸이 채워짐 → 정답 발견
    // → 마지막 빈칸까지 모순 없이 채워진 유일한 세계선이 board에 남음
    // → 연쇄 true 반환을 통해 모든 부모 호출에서도 선택 확정
    // → solve()가 반환하는 false가 없으므로 이전 선택들이 되돌려지지 않고 그대로 유지
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 보드 입력
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    // 재귀 호출 시작
    // 전역 보드를 직접 수정하며, 각 재귀 호출은
    // 자신이 선택한 수들로 모순이 생기면 false 반환 → 그 때까지 가정한 수들 전부 초기화 -> 다음 자식노드로 분기(수 선택) 시도
    // 마지막까지 모순 없이 채워지면 연쇄 true 반환 → 선택 확정
    solve();

    // 완성된 보드 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}
