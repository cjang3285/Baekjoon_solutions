#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> d(N-1), p(N);
    for (int i = 0; i < N-1; i++) cin >> d[i];
    for (int i = 0; i < N; i++) cin >> p[i];

    long long ans = 0;
    long long minPrice = p[0]; // 지금까지 방문한 도시(1..i(지금위치)) 중 가장 싼 주유소 가격

    for (int i = 0; i < N-1; i++) {
        // 1번째부터 n번째 도시까지 있다 
        // 2에 가는데 1의 기름을 사고 
        // 3에 가는데 1,2중 더 싼 곳의 기름을 사고 
        // 4에 가는데 1,2,3 중 제일 싼 곳의 기름을 사고 
        // ... 
        // n에 가는데 1,2,3,...,n-1 중 제일 싼 곳의 기름을 사고 왔다. 
    
        // 그럼 항상 더 싼 곳의 기름을 산거니 최소비용이 들었을 것이다.
        
        // i+1번째 도시로 갈 때 쓰는 기름은
        // 1,2,...,i 중 가장 싼 곳의 기름으로 이미 사서 왔다고 생각하자.
        // 따라서 i+1번째 도시로 갈 때 지나가는 i번째 도로를 갈 때 드는 기름비용은
        // 최소값(minPrice)으로 고정된다.
        minPrice = min(minPrice, p[i]);

        // (i -> i+1) 구간 d[i]를 지나는 비용:
        // "1..i 중 최저가" * d[i]
        ans += minPrice * d[i];
    }
    
/*  가격
     5 |--| 불가피 => p[0]
     4 |  |
     3 |  |
     2 |  |--| min(p[0], p[1]) => p[1]
     1 |     |-- -- --| min(p[2], p[3,4]) => p[2]
        1  2  3  4  5 (구간) */
    cout << ans;
}

