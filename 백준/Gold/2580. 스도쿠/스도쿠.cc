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
                // 1~9 후보 모두 시도
                for (int x = 1; x <= 9; x++) {
                    if (possible(i, j, x)) { // 후보 가능
                        board[i][j] = x; // 선택 → 보드 상태 변경
                        
                        // 선택한 x가 정답으로 이어지는지 재귀 탐색
                        // → 이때부터 보드는 완전히 새로운 상태가 되며,
                        // 모든 다른 빈칸들이 현재 선택에 영향을 받음
                        if (solve()) return true; 
                        // false 반환 시 → 이 선택은 모순 → 원상복구
                        // → 선택한 x로 인해 발생한 모든 하위 선택은 삭제됨
                        board[i][j] = 0; // 백트래킹
                    }
                }
                // 어떤 후보도 넣을 수 없음 → 현재 선택 자체가 모순
                // → false 반환 → 이 분기 전체가 제거되고
                // 부모 호출로 돌아가 다른 후보 또는 또다른 분기 탐색
                return false;
            }
            // 빈칸이 아니라면 그냥 다음 칸 탐색
        }
    }
    // 모든 칸이 채워짐 → 정답 발견
    // → 마지막 빈칸까지 모순 없이 채워진 유일한 세계선이 board에 남음
    // → 연쇄 true 반환을 통해 모든 부모 호출에서도 선택 확정
    // → false가 없으므로 이전 선택들이 되돌려지지 않고 그대로 유지
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
    // 자신이 넣은 숫자가 모순이면 false 반환 → 선택 삭제
    // 마지막까지 모순 없이 채워지면 연쇄 true 반환 → 선택 확정
    solve();

    // 완성된 보드 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}
