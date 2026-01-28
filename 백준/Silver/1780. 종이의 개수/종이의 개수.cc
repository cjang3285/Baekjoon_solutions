#include <bits/stdc++.h>
using namespace std;

/*
- 첫 칸의 색을 기준(firstColor)으로 잡음
- 순회 중 하나라도 다른 값이 나오면
  → "섞임"이 즉시 확정 → 바로 9 구역으로 등분 재귀
- 끝까지 다 돌았으면 전부 같은 색
- 불필요한 연산 제거 (early exit)

- dividePaper(x, y, size)는
  → (x, y)에서 시작하는 size x size 종이가
     하나로 가능한지 판별하는 함수

- 격자 내 모두 단일 번호면: 해당 번호 종이 1장 카운트
- 다른 번호가 섞여 있으면: 9개의 size/3 정사각형으로 분할
*/

int N;
int paper[2200][2200];
int one_cnt = 0;
int minus_one_cnt = 0;
int zero_cnt = 0;

void dividePaper(int x, int y, int size) {
    int firstColor = paper[x][y];  // 기준 색

    // 현재 영역이 단색인지 검사
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {

            // 하나라도 다르면 → 섞임 확정
            if (paper[i][j] != firstColor) {

                // 섞임 발견 분할
                int trisection = size / 3;
                
                for(int m = 0; m < 3; m++)
                    for(int n = 0; n < 3; n++){
                        dividePaper(x + m * trisection, y + n * trisection, trisection);
                    }
                return;  // 위에서 9번의 함수호출로 현재 격자를 9등분해서 위임했으니 할 일 없음. return. 
            }
        }
    }

    // 여기 도착 = 전부 같은 색
    
    switch(firstColor){
        case 1:
            one_cnt++;
            break;
        case -1:
            minus_one_cnt++;
            break;
        case 0:
            zero_cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    dividePaper(0, 0, N);

    cout << minus_one_cnt << '\n' << zero_cnt << '\n' << one_cnt;
    return 0;
}
