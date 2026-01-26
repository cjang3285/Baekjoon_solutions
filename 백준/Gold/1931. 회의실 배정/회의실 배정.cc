#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    // 각 회의의 <시작하는 시간, 끝나는 시간> 입력받기
    vector<pair<int,int>> meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 시작시간 기준 정렬 (같으면 끝시간 기준)
    sort(meetings.begin(), meetings.end());
    
    int answer = 0; // 시간표에 배정한 회의 개수
    int chosenEnd = -1; // 현재 고려중인 회의의 끝나는 시간으로 사용할 변수

    for (auto &cur : meetings) {
        int curStart = cur.first, curEnd = cur.second;

        // 첫 pass에서는 가장 이른 시간의 회의이므로 무조건 배정
        if (chosenEnd == -1) {
            chosenEnd = curEnd;
            answer++;
        }
        // 직전 pass에서 배정한 회의의 끝나는 시간과 
        // 현재 고려 중인 회의의 시작시간이 겹치지 않음 
        // → 확정 + 새 회의로 이동
        else if (curStart >= chosenEnd) {
            answer++;
            chosenEnd = curEnd;
        }
        // 직전 pass에서 배정한 회의의 끝나는 시간보다 
        // 현재 고려 중인 회의의 끝나는 시간이 더 이르다 
        // 교체하는 게 더 이득이니 직전에 배정한 회의 취소
        // -> 새 회의로 배정, answer++는 이미 됐으니 chosenEnd만 더 이른 curEnd로 수정
        else {
            if (curEnd < chosenEnd) {
                chosenEnd = curEnd;
            }
        }
    }

    cout << answer;
}
