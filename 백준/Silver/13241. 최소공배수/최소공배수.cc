#include<bits/stdc++.h>
using namespace std;

// a와 b의 최대공약수를 구하는 함수 (유클리드 호제법)
long long int gcd(long long int a, long long int b) {
    while (b != 0) {           // 나머지가 0이 될 때까지 반복
        long long int r = a % b;         // a를 b로 나눈 나머지 r 계산
        a = b;                 // a를 b로 바꿔서 다음 반복 준비
        b = r;                 // b를 나머지 r로 바꿔서 다음 반복
        // 핵심: GCD(a, b) == GCD(b, r) 성질 이용
    }
    return a;                  // 나머지가 0이 되면 a가 최대공약수
}

// a와 b의 최소공배수를 구하는 함수
long long int lcm(long long int a, long long int b) {
    // 핵심 원리: LCM(a, b) = (a*b) / GCD(a, b)
    return (a / gcd(a, b)) * b;  // a*b / GCD 순서로 계산하면 overflow 위험 줄임
} // (a / gcd(a, b))는 항상 정수
  // 이유: gcd(a, b)는 a와 b를 동시에 나누는 수니까, a를 gcd로 나누면 나머지가 0임 → 정수 보장
  // * b 순서를 나누기 먼저 한 것도 overflow 방지용 트릭.

int main(){
        long long int A, B;
        cin >> A >> B;
        cout << lcm(A, B) << '\n';
}