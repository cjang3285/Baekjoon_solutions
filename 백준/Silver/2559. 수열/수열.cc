#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    
    // 정수 수열 입력
    for(int i = 0; i < N; i++) 
        cin >> v[i];

    // 수열의 첫 수부터 K번째 수까지의 합 구하기
    int cur = 0;
    for(int i = 0; i < K; i++) 
        cur += v[i];
    
    // 첫 구간 합을 토대로 한칸씩 앞으로 가며 
    // 새 cur을 구하고 이전 ans보다 더 크다면 
    // 더 큰 cur을 ans에 복사한다.
    int ans = cur;
    // K+1번째(i = (K+1)-1) 수부터 오른쪽 추가, 1번째(i = (1)-1 = 0) 수부터 왼쪽 제거 
    // ~ N번째(i = (N)-1) 수까지 오른쪽 추가, N-K번째(i = (N-K)-1) 수까지 왼쪽에서 제거
    for(int i = K; i < N; i++) { 
        cur += v[i];     // 오른쪽 추가
        cur -= v[i-K];  // 왼쪽 제거
        ans = max(ans, cur);
    }

    cout << ans;
}
