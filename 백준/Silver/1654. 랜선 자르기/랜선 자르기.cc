#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    vector<long long> lan(K);

    // 범위 설정
    long long low = 1;          // 자를 수 있는 최소길이
    long long high = 0;         

    for(int i = 0; i < K; i++) {
        cin >> lan[i];
        high = max(high, lan[i]);   // 가장 긴 랜선 = 최댓값 후보
    }

    long long answer = 0; // 우리가 맞춰야 할 정답 L

    while (low <= high) { // low가 high보다 커지면 중단.
        // 긴 배열을 왼쪽, 오른쪽 배열로 두 조각으로 나누어 간단하게 생각해보자. 
        // mid는 정수형이라 /2하면 소수점 아래 소거되기 때문에
        // mid는 전체 칸이 홀수개든 짝수개든 항상 왼쪽 배열 조각의 마지막 값이 된다. 
        long long mid = (low + high) / 2;

        // 부른 길이로 개수 세보니 그 개수가
        long long count = 0;
        for(int x : lan) {
            count += x / mid;
        }
        
        // L (길이) 증가 ->
        // 100 110 120 130 140 150 160 170 180
        // S   S   S   S   S   F   F   F   F
        // 일반적인 흐름은 실패 반복하면서 왼쪽구간만 남기며 자르는 길이(중앙값) L을 줄여간다. 
        // 그러다 연속 성공하면서 마지막에 성공에서 low가 high보다 커지고 
        // while (low <= high) 탈출해서 최대 L을 출력.
        
        // 예시. 숫자 = 정렬됐다는 가정 하에 그 값이 중앙값이 되는 순서.
        // [       3(첫 성공)     4   5  67(마지막 성공)  2                   1(첫 실패) ]
        // [ F F F ... F | S S S ... S ]
        // 실패(F) 구간 → 반복하면서 high 줄여서 왼쪽만 남김
        // 첫 성공 → answer 갱신 → low = mid+1 → 오른쪽 탐색
        // 연속 성공(S) 구간 → answer 계속 갱신 → 최대 L 확보
        // 마지막 성공(mid) → low > high 돨때까지 low = mid + 1 → 반복 종료
        // 한번 성공하면 이후 절대 다시 실패 구간으로 돌아가지 않음
        if (count >= N) { // N개 이상 나왔다면 성공.
            answer = mid; // mid는 성공했으니 답으로 기록. 
                          // 이번엔 mid의 다음 칸부터 high까지의 구간을 설정해서 
            low = mid + 1; // 다음 반복에서는 mid 제외된 오른쪽 구간의 중앙값(즉 더 큰 길이)으로 잘라보자.
        } 
        else { // N개보다 적게 나왔으면 실패. 
            high = mid - 1; // mid가 실패했으니 mid도 제외하기 위해 
            // 원래 low 값부터 mid의 이전 칸까지 구간을 설정해서 
            // 다음 반복에서는 mid 제외된 왼쪽 구간의 중앙값(즉 더 짧은 길이)으로 잘라보자.
        }
    }
    // 반복 탈출 후 정답 출력
    cout << answer;
    return 0;
}
