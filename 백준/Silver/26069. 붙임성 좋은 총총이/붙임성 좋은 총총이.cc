#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
        
    // 정렬 x
    // 존재 여부 확인 o
    // 중복 자동 제거 o => unordered set
    unordered_set<string> dance;
    dance.insert("ChongChong");

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        // unorder set 의 count 메서드는 해당 인자가 컨테이너에 존재하면 1 아니면 0을 반환
        if (dance.count(a) || dance.count(b)) {
            dance.insert(a); // 키던
            dance.insert(b); // 밸류던
        }  // 총총이 등장한 문자열부터 그 아래로 
    }      // 총총이 등장한 문자열에서 총총과 함께 나온 사람이름을 insert해뒀기 때문에 총총과 그 사람을 시작으로 전파된다
           // 만약 총총과 그 사람 이름 둘 중 하나가 이후 문자열에서 다른 사람 이름과 함께 나오면 그 사람 이름도 insert된다
           // 위 과정을 반복한다
           // 총총이 등장하기 전 문자열들은 모두 무시가능하다 만남은 시간순서로 입력됐기 때문이다 
    cout << dance.size();
}
