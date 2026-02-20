#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    unordered_set<string> dance;
    dance.insert("ChongChong");

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;

        if (dance.count(a) || dance.count(b)) {
            dance.insert(a); // 키던
            dance.insert(b); // 밸류던
        }  // 총총이 등장한 문자열부터 그 아래로 
    }      // 총총이 등장한 문자열에서 총총과 함께 나온 사람이름을 토대로 전파된다
           // 총총이 등장하기 전 문자열들은 모두 무시가능하다 만남은 시간순서로 입력됐기 때문이다 
    cout << dance.size();
}