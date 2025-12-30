#include <iostream>
#include <string>

using namespace std;
// 정석 풀이 저장 //
// 1. 재귀 함수: 오직 '판별' 결과만 int로 반환합니다.
int recursion(const string& s, int l, int r, int& cnt) {
    cnt++; // 호출 횟수 기록
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1, cnt);
}

// 2. 인터페이스 함수: 외부에서 호출하기 편하게 감싸줍니다.
int isPalindrome(const string& s, int& cnt) {
    return recursion(s, 0, (int)s.length() - 1, cnt);
}

int main() {
    // 입출력 가속
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int cnt = 0;
        
        // 3. main에서 결과값과 cnt를 분리해서 출력합니다.
        int result = isPalindrome(str, cnt);
        cout << result << " " << cnt << "\n";
    }
    return 0;
}