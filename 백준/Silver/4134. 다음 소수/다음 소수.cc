#include<bits/stdc++.h>
using namespace std;

bool isPrime = false;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        long long N; 
        cin >> N;
        
        
        for(long long n = N; ; n++){
            // 가정한다
            bool isPrime = true; 
            
            // 0 ≤ n이므로 예외처리
            if(n == 1 || n == 0) isPrime = false; // 1은 소수 아니다
            
            // 2 이상의 정수로 나누어 떨어지는지 확인하자
            // sqrt(n)은 실수 연산 → 느림 + 오차 가능성
            // d*d <= n은 정수 연산 → 빠르고 정확
            // d ≤ √n ⟺ d^2 ≤ n
            for(long long d = 2; d*d <= n; d++){ // sqrt를 애초에 안쓴다
                if(n % d == 0){ // 나누어 떨어지면
                    isPrime = false; // 소수가 아니다
                    break; // n + 1로 시도해보자
                }
            }
            if(isPrime){ // 위 두가지 판정을 통과했다면
                cout << n << '\n'; // 그 수가 소수다
                break; // 다음 테스트 케이스로 넘어가자
            }
        }
    }
}