#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
(A 곱하기 B)의 나머지 C는
(A의 나머지 C) 곱하기 (B의 나머지 C)를
다시 C로 나눈 나머지와 같다.
    
A를 B번 곱한 값은 다음처럼 계산할 수 있다.

만약 B가 짝수라면:
A를 B/2번 곱한 값을 한 번 구하고,
그 값을 자기 자신과 한 번 더 곱한다.

만약 B가 홀수라면:
A를 B/2번 곱한 값을 한 번 구하고,
그 값을 자기 자신과 곱한 다음,
거기에 A를 한 번 더 곱한다.
*/
ll modpow(ll a, ll b, ll c) {
    if (b == 0) return 1;
    
    ll half = modpow(a, b / 2, c); // 원래 a^b를 c로 나눈 나머지가 궁금한 것이었다
    // 그러나 분할정복을 위해 a^(b/2)를 c로 나눈 나머지를 저장한다.
    half = (half * half) % c; // 그 수의 제곱의 나머지가 곧 a^b를 c로 나눈 나머지다.
    
    if (b % 2 == 1) // b가 홀수였다면 한번 더 a를 곱한 수의 나머지를 구해야한다.
        half = (half * a) % c;
    // b가 짝수라면 한번 더 곱할 필요가 없다.
    return half;
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    cout << modpow(A, B, C);
}
