#include <bits/stdc++.h>
using namespace std;

// i, j번째 수 == arr[i-1], arr[j-1]를 의미. 
// 1 based   <=> 0 based 표현
// i번째 수부터 j번째 수까지의 합 <=> arr[i-1] + ... + arr[j-1]

// arr[i-1] + ... + arr[j-1] 
// => 

// (arr[0] + ... + arr[i-2] + arr[i-1] + ... + arr[j-1])
// - (arr[0] + ... + arr[i-2])
// =>

// (arr[0] + ... + arr[j-1]) - (arr[0] + ... + arr[i-2])
// = prefix[j] - prefix[i-1]

// "prefix[i] = 배열의 첫([0])번째 원소부터 i[i-1]번째 원소까지의 합

// prefix[0] = 0
// prefix[1] = arr[0]
// prefix[2] = arr[0] + arr[1]
// ...
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> prefix(N+1, 0); // 첫 자리는 prefix[0] = 0로 사용하기 위해.
    
    // 1 ≤ i ≤ j ≤ N이므로 만약 i = 1이면?
    // prefix[0] = 0이어야 i = 1일 때도 오류 x
    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }

    while(M--) {
        int i, j;
        cin >> i >> j;
        cout << prefix[j] - prefix[i-1] << '\n';
    }
}
