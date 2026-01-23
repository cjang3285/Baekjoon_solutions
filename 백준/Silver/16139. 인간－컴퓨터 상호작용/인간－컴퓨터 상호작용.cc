#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // [원본 세계] 문자열 = 시간축
    string S;
    cin >> S;
    int N = S.size();

    // [상태공간] 26개의 문자 전용 통로(시간 로그북)
    // prefix[c][i] = S[0..i]까지 문자 c의 누적 등장 횟수
    vector<vector<int>> prefix(26, vector<int>(N, 0));

    // [시간 0 초기화]
    // i = 0에서는 i-1이 존재하지 않으므로 따로 처리
    prefix[S[0] - 'a'][0] = 1;

    // [시간 전개] i = 1부터 N-1까지
    for (int i = 1; i < N; i++) {

        // (1) 모든 문자 세계에 과거 상태를 복사
        // → 누적합의 본질: 상태의 지속
        for (int c = 0; c < 26; c++)
            prefix[c][i] = prefix[c][i - 1];

        // (2) 현재 시점에 발생한 문자 통로만 +1
        // → 사건 기록
        prefix[S[i] - 'a'][i]++;
    }

    int Q;
    cin >> Q;

    while (Q--) {
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        int c = alpha - 'a';  // 알파벳 → 통로 인덱스

        // [구간 추출]
        // r까지 누적된 개수에서,
        // l 이전까지 누적된 개수를 제거
        if (l == 0)
            cout << prefix[c][r] << '\n';
        else
            cout << prefix[c][r] - prefix[c][l - 1] << '\n';
    }
}
