#include <iostream>
using namespace std;

// 최대공약수(GCD) 함수: 유클리드 호제법
int gcd(int x, int y) {
    while (y != 0) {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d; // 두 분수 a/b, c/d 입력

    // 분수 합 공식: a/b + c/d = (a*d + b*c) / (b*d)
    int numerator = a * d + b * c; // 분자 계산
    int denominator = b * d;       // 분모 계산

    // 분자와 분모의 최대공약수 계산
    int g = gcd(numerator, denominator);

    // 분자와 분모를 최대공약수로 나눠 기약분수로 만들기
    numerator /= g;
    denominator /= g;

    // 결과 출력 (기약분수 형태)
    cout << numerator << " " << denominator << "\n";

    return 0;
}
