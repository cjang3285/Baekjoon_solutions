#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long M;
    cin >> N >> M;

    vector<int> trees(N);
    int max_height = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (trees[i] > max_height) max_height = trees[i];
    }

    long long start = 0;
    long long end = max_height;
    long long result = 0;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long total = 0;

        // 현재 설정한 높이(mid)로 잘랐을 때 얻는 나무 양 계산
        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) { // mid보다 큰 나무들만 잘리니까
                total += (trees[i] - mid); // 잘린 길이 누적
            }
        }

        if (total >= M) {
            // 나무가 충분하면: 높이를 더 높여본다 (최댓값 찾기)
            result = mid;
            start = mid + 1;
        } else {
            // 나무가 부족하면: 높이를 낮춰야 한다
            end = mid - 1;
        }
    }

    cout << result << "\n"; // 어차피 마지막 mid가 답이라 mid를 출력해도 된다.

    return 0;
}