#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    /*
        sameRemCount[r]:
        지금까지 등장한 prefix 나머지들 중
        (prefix % M == r) 인 것이 몇 번 나왔는지 => 나머지 등장 빈도
    */
    vector<long long> sameRemCount(M, 0);

    /*
        remOfPrefix:
        현재까지 prefix 합의 '나머지 상태'
        실제 prefix 값은 버리고,
        prefix % M 만 유지한다.
    */
    long long remOfPrefix = 0; // prefix[0] % M

    // 조건을 만족하는 (i, j) 구간 개수
    long long validSubarrayCount = 0;

    /*
    
        원래 조건:
        A[i] + ... + A[j] = prefix[j] - prefix[i-1]

        i = 1 인 경우:
        A[1] + ... + A[j] = prefix[j] - prefix[0]

        따라서 prefix[0] = 0이 존재해야
        i = 1 인 구간도 같은 수식으로 처리할 수 있다.
    
    */
    
    /*
    
        prefix[0] % M = 0 이므로
        나머지 0이 한 번 등장한 것처럼
        sameRemCount[0] = 1 로 시작한다.
    
    */
    sameRemCount[0] = 1;
    
    /* 문제의 핵심:
    
        같은 나머지를 가진 두 prefix가 있으면,
        그 사이 구간합은 M으로 나누어 떨어진다.

        "같은 나머지를 가진 prefix 쌍의 개수"를
        순차적으로 세는 문제이다.
    */
    
    for (int j = 1; j <= N; j++) {
        int value; // A[j]
        cin >> value;
        
        // 이전까지 누적합에 이번 A 값을 더하면 이번 누적합이 나올 것이다.
        // prefix[j-1] + A[j] = prefix[j]!
        
        // 문제는 나머지가 중요하니까 prefix[j]의 나머지가 궁금한 상황이다.
        
        // By (x + y) % M = ((x % M) + (y % M)) % M
        
        // prefix[j]의 나머지 = prefix[j] % M
        // prefix[j] % M = (prefix[j-1] + A[j]) % M
        // = ((prefix[j-1] % M) + (A[j] % M)) % M
        // = (이전까지 누적합의 나머지 + 이번 A 값의 나머지) % M
        
        /*
            remOfPrefix:
            우변에서 계산 → (prefix[j-1] + A[j]) % M
            좌변의 변수 갱신 → prefix[j] % M
        */
        remOfPrefix = (remOfPrefix + value) % M;
        
        
        /*
            같은 나머지를 가진 N개의 prefix가 있을 때 
            한 prefix가 그들과 같은 나머지를 가지는 것을 알게되었다면,
            새 prefix와 기존 prefix들 간에 새롭게 생길 수 있는 쌍은 기존 prefix들의 개수인 N = N*1개이다.
            
            => 지금 remOfPrefix와 같은 나머지를 가진
            이전 prefix들 수 만큼 새로운 구간이 생길 것이다.
            
            => 새로운 구간 개수 sameRemCount[remOfPrefix]를 부분배열 개수에 더해준다.
        */
        validSubarrayCount += sameRemCount[remOfPrefix];

        /*
            이제 j번째 prefix도 자신의 나머지인 remOfPrefix가 된 모습으로 카운트 배열에 카운트수를 갱신해줌으로서
            추후 j+1에서 prefix[j] % M 계산과 새 prefix와 기존 prefix들 간에 새롭게 생길 수 있는 쌍 개수 계산을 돕는다.
        */
        sameRemCount[remOfPrefix]++;
    }

    cout << validSubarrayCount;
}
