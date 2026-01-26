#include <bits/stdc++.h>
using namespace std;

int N;
int paper[130][130];
// 단색 → "숫자" 하나 출력
// 섞임 → "(자식들)" 출력

void dividePaper(int x, int y, int size) {
    // 현재 보고 있는 격자의 첫 칸 색
    int firstColor = paper[x][y];

    // 현재 격자 내 다른 칸들을 보면서 첫 칸과 다른 색이 있는지 검사
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != firstColor) {
                // 섞임 → 분할노드
                // “분할노드 = 색이 섞여 있는 격자”
                int half = size / 2;
                cout << '(';
                dividePaper(x, y, half);                 // 왼쪽 위
                dividePaper(x, y + half, half);          // 오른쪽 위
                dividePaper(x + half, y, half);          // 왼쪽 아래
                dividePaper(x + half, y + half, half);   // 오른쪽 아래
                cout << ')';
                return;
            }
        }
    }

    // 여기 오면 단색
    cout << firstColor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; // 입력 형태상 정수로 받으면 안됨 
        cin >> s;
        for (int j = 0; j < N; j++)
            paper[i][j] = s[j] - '0'; // 정수 문자를 - '0'하여 정수로 바꿔 저장
    }
    
    dividePaper(0, 0, N);
    return 0;
}

