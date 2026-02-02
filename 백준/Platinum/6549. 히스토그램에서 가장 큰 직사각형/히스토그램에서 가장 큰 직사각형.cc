#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<long long> histogram(n);
        for (int i = 0; i < n; i++) cin >> histogram[i];

        stack<int> barStack;
        long long maxRectangle = 0;

        histogram.push_back(0);
        n++;

        for (int currentBarIndex = 0; currentBarIndex < n; currentBarIndex++) {
            while (!barStack.empty() && histogram[barStack.top()] > histogram[currentBarIndex]) {
                int poppedBar_idx = barStack.top();
                barStack.pop();

                long long height = histogram[poppedBar_idx];
                int leftBoundary_idx = barStack.empty() ? -1 : barStack.top();
                long long width = (currentBarIndex - 1) - leftBoundary_idx;
                long long area = height * width;
                maxRectangle = max(maxRectangle, area);
            }
            barStack.push(currentBarIndex);
        }

        cout << maxRectangle << "\n";
    }

    return 0;
}

/*
질문 핵심 답변 종합 정리

0. 스택의 탑의 높이보다 현재 막대의 높이가 작을 때만 while 진입. 아니면 현재 막대는 스택에 푸시
1. 스택에는 히스토그램 인덱스만 저장, 높이는 pop 시 popped Bar idx로 참조.
2. 연쇄 pop: 현재 막대보다 높은 막대가 연속이면 pop마다 폭 계산 + 면적 계산 → maxRectangle 갱신.
3. 폭 계산: (currentBarIndex - 1) - leftBoundary_idx
   - 왼쪽 경계 idx는 스택 원래 상태에서 한번 팝된 두번째 높은 막대의 인덱스이므로 히스토그램에서 원래 탑 막대의 전 칸이다
   그대로 currentBarIndex의 전 칸에서 빼면 폭이 나온다. 팝한 뒤의 탑이기 때문에 이미 탑의 인덱스 - 1이 된 셈이다.
   - 현재 낮은 막대(currentBarIndex) 제외. 정확히는 그 막대의 바로 앞자리까지가 폭이니 - 1
4. 왼쪽 경계(leftBoundary_idx) = pop 후 스택 top
5. 높이가 같은 막대를 current bar로 만나는 경우는 pop 안 됨
7. 센티널 0 덕분에 마지막까지 스택에 남은 막대 처리 가능.
8. 연쇄 pop 시 각 pop마다 넓이 계산 후 max 갱신 
   → 높이가 같은 막대가 앞 방향으로 이어져도 다 계산하고 그 중 최대값만 남기니
   -> 높이가 같은 막대가 최대한 이어지는 경우의 넓이만 max로 남음.
9. 폭 계산에 왼쪽 경계는 인덱스만 필요, 높이는 신경 안 써도 됨.
10. 시간 복잡도: O(n) → 각 막대 최대 1번 push, 1번 pop
11. 공간 복잡도: O(n) → 스택 최대 n개
12. 에지 케이스:
    - 모든 높이 0, 중간에 하나만 높은 경우, 사인/코사인 형태, 급격한 높이 변동 등 모두 처리 가능
*/
