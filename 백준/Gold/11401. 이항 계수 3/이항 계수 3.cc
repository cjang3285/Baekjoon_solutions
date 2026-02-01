#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007; // p = 소수

/*
    문제: nCk mod p, 단 p는 소수 (11401)

    핵심 아이디어:

    nCk = n! / (k! (n-k)!)
         = n! * (k!(n-k)!)^{-1}   (mod p)

    여기서 나눗셈은 mod 세계에서는 "역원"으로 바뀜.
*/

/*
    수학적 배경 요약:

    mod p 세계에서
        Z_p = {0,1,2,...,p-1}

    그 중 역원이 존재하는 집합:
        Z_p^* = {1,2,...,p-1}

    (p가 소수이므로 0만 빼고 전부 p와 서로소)

    따라서:
        a ∈ Z_p^*  <=>  gcd(a,p)=1  <=>  a ≠ 0 (mod p)

    이 집합은 곱셈에 대해 군(group).
*/

/*
    페르마 소정리:

        a ∈ Z_p^* 이면
        a^(p-1) ≡ 1 (mod p)

    양변에 a^{-1} 곱하면:

        a^(p-2) ≡ a^{-1} (mod p)

    즉:
        역원 = a^(p-2)
*/

ll modpow(ll a, ll b) {
    /*
        이 함수는 a^b mod p 를 계산.

        여기서:
            a ∈ Z_p^* (역원이 존재하는 원소)
            b는 지수 (여기서는 보통 p-2)

        수학적으로 우리가 계산하는 건:
            a^b = a^(b_0*2^0 + b_1*2^1 + ...)

        즉 b를 이진수로 분해해서:
            필요한 제곱들만 곱하는 것.
    */

    ll res = 1;

    while (b > 0) {

        /*
            b & 1 :

            b를 이진수로 봤을 때
            최하위 비트가 1인지 검사.

            예:
                b = 13 = 1101₂
                -> 1,0,1,1 순서로 처리됨

            의미:
                지금 보고 있는 2^i 항이
                실제로 지수에 포함되면 곱함.
        */
        if (b & 1) {
            res = res * a % MOD;
            /*
                res는 지금까지 선택된 항들의 곱.
                수학적으로:
                    res = Π a^{2^i}
            */
        }

        /*
            a = a * a :

            a를 제곱하는 이유:

                처음엔 a = a^(1)
                다음엔 a = a^(2)
                다음엔 a = a^(4)
                다음엔 a = a^(8)
                ...

            즉:
                a는 "밑"이 아니라
                현재 2^i에 해당하는 거듭제곱 값.
        */
        a = a * a % MOD;

        /*
            b >>= 1 :

            b를 오른쪽으로 1비트 shift.
            즉:
                b = floor(b / 2)

            다음 비트(2^(i+1))로 이동.
        */
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    /*
        문제 조건:
            n < p

        그래서 n! 안에는 p가 안 들어감.
        따라서:

            n! mod p ≠ 0
            k! mod p ≠ 0
            (n-k)! mod p ≠ 0

        즉:
            분모 a = k!(n-k)! ∈ Z_p^*
            → 역원 존재.
    */

    vector<ll> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        /*
            여기서 i는 그냥 1,2,3,...,n
            mod p의 환사상에 의해:
                (x*y) mod p = (x mod p)*(y mod p)
            이므로
                매 단계마다 mod p 붙여도 구조 보존.
        */
    }

    ll numerator = fact[n];
    ll denominator = fact[k] * fact[n-k] % MOD;

    /*
        denominator = a 라고 하면:

            a ∈ Z_p^*

        그래서:
            a^(p-1) ≡ 1
            a^(p-2) ≡ a^{-1}
    */

    ll inv = modpow(denominator, MOD-2);

    ll ans = numerator * inv % MOD;
    cout << ans << "\n";
}
