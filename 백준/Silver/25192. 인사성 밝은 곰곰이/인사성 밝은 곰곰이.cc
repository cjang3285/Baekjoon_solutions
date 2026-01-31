#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    // 1. 입출력 속도 최적화 (이 부분이 없으면 시간 초과 가능성이 높음)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    unordered_set<string> gomgom;
    int total_greetings = 0;
    string input;

    while (N--) {
        cin >> input;

        if (input == "ENTER") {
            // ENTER가 들어오면 셋을 비움 (새로운 그룹 시작)
            gomgom.clear();
        } else {
            // insert의 반환값(pair)을 이용해 한 번에 확인 및 삽입
            // .second는 새로 삽입되었을 때만 true를 반환함
            if (gomgom.insert(input).second) {
                total_greetings++;
            }
        }
    }

    cout << total_greetings << "\n";

    return 0;
}