#include <bits/stdc++.h>
using namespace std;

long long N, K;

// 2. 배열 A에서 mid 이하인 수가 몇 개인지 = "수위 mid일 때 잠긴 칸 수"
long long HowManyLeqTo(long long mid) {
    long long cnt = 0;

    // i단 구구단을 한 줄씩 보면서
    for (int i = 1; i <= N; i++) {

        // i단: i, 2i, 3i, ... , Ni
        // 배열 A의 원소가 i*j이다.
        // 배열 A의 i 행에서 값이 mid 이하인 원소 개수를 세는 행위를 그걸 1~N단까지 행마다 해서 누적합하면 
        // 배열 A에서 mid 이하인 수들을 모두 셀 수 있다.
        // ij ≤ mid 인 j 개수는 곧 i행에서 mid 이하인 원소 개수와 동치다. j가 1 이상인 양수이기 때문.
        // i를 이항하면
        // j ≤ mid / i인 j의 개수는 곧 i행에서 mid 이하인 원소 개수다.
        // j의 최대값인 바닥(mid / i)가 i행에서 mid 이하인 원소 개수다.
        long long j_max = mid / i;
        
        // 하지만 한 단에는 N개까지만 존재하므로 i행에서 mid 이하인 원소 개수의 최대값 j_max는 
        // N보다 커지면 안된다.
        cnt += min((long long)N, j_max); 
    }
    
    // 배열 A에서 각 행을 순회하여 
    // mid 이하인 원소 총 개수를 센 cnt를 얻었다.
    return cnt; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    long long low = 1; // 배열 A의 첫 값
    long long high = N * N; // 마지막 값 N은 10^5보다 작거나 같은 자연수다. 
    // 그럼 그 제곱은 최대 10^10가 발생하고 int 범위를 넘긴다. long long을 사용해야 한다. 
    // low, mid, answer, cnt, j_max 등 high -> mid -> j_max -> cnt
    long long answer = 0;
    
    // B 오름차순 정렬 조건
    // N * N 배열을 직접 계산하려면 O(N^2)이라 시간, 메모리 초과 가능성
    
    // HowManyLeqTo(mid) + 이분탐색으로 위 조건들을 해결
    
    // 1. 문제서 요구하는 K번째 값을 이분탐색(mid)으로 찍음
    while (low <= high) {
        long long mid = (low + high) / 2;

        // 2. 각 단에서 j*i≤x 만족 개수 세서 전부 더함
        // HowManyLeqTo(x)는 단조 증가 함수이므로 이분탐색 적용 가능
        long long rank = HowManyLeqTo(mid);   // mid의 등수

        // 3. 그 등수가 K 이상인지 비교
        // rank ≥ K 라는 것은
        // "정렬된 배열 B에서 mid의 위치가 K번째 이상"이라는 뜻이다.
        // 따라서 mid는 K번째 수이거나 그보다 큰 값 중 하나이며,
        // 우리는 그중 '최소의 mid'를 찾아야 하므로 왼쪽 탐색을 한다.
        if (rank >= K) {
            // rank ≥ K 인 mid는 "정렬 후 K번째 이상의 위치"를 의미하므로 정답 후보
            // mid는 실제 배열 값이 아닐 수 있지만,
            // 위치 관계 판단으로는 충분하다.
            // 성공한 mid 중 최소 mid가 실제 K번째 값이다.
            
            // 배열 B : ... [K-1번째]  [K번째]  [K+1번째] ...
            // K번째 수보다 작은 애들은 K개 미만
            // K번째 수부터는 K개 이상
            // 👉 경계선이 딱 K번째 수.
            // 우리 이분탐색은
            // “K개 이상이 처음 되는 지점”
            // 을 찾으니 실제 K번째 값이 마지막 mid가 된다.
            answer = mid;        // 후보
            high = mid - 1;     // 더 낮은 후보 탐색
        } else {
            low = mid + 1;     // 더 높은 후보 탐색
        }
    }

    cout << answer;
}
