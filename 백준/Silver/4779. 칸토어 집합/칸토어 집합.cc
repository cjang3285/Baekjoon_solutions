#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// str: 전체 문자열 (참조자 &를 사용하여 메모리 복사를 방지)
// start: 현재 작업할 구간의 시작점
// size: 현재 작업할 구간의 길이
void solve(string &str, int start, int size) {
    // 1. 기저 조건: 길이가 1이면 더 이상 쪼갤 수 없으므로 종료
    if (size == 1) return;

    // 2. 3등분한 한 구간의 길이 계산
    int next_size = size / 3;

    // 3. 중앙 구간을 공백으로 바꿈
    // 인덱스: start + next_size 부터 next_size 개수만큼
    for (int i = start + next_size; i < start + 2 * next_size; i++) {
        str[i] = ' ';
    }

    // 4. 왼쪽 1/3 구간에 대해 재귀 호출
    solve(str, start, next_size);

    // 5. 오른쪽 1/3 구간에 대해 재귀 호출
    // 중앙(1/3)은 이미 공백이므로 재귀를 돌릴 필요가 없음
    solve(str, start + 2 * next_size, next_size);
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // EOF(파일 끝)까지 입력 받기
    while (cin >> n) {
        // 3의 n승 계산
        int total_len = 1;
        for (int i = 0; i < n; i++) total_len *= 3;

        // 전체 길이만큼 '-'로 채워진 문자열 생성
        string str(total_len, '-');

        // 재귀 함수 시작
        solve(str, 0, total_len);

        // 결과 출력
        cout << str << "\n";
    }

    return 0;
}

