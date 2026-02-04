#include<bits/stdc++.h>
using namespace std;

bool isPrime = false;

int main(){
        long long M, N; 
        cin >> M >> N;
        
        
        for(long long m = M; m <= N; m++){
            // 가정한다
            bool isPrime = true; 
            
            // 1 ≤ m이므로 예외처리
            if(m == 1) isPrime = false; // 1은 소수 아니다
            
            // 2 이상의 정수로 m이 나누어 떨어지는지 확인하자
            // d ≤ √m ⟺ d^2 ≤ m
            for(long long d = 2; d*d <= m; d++){ 
                if(m % d == 0){ // 나누어 떨어지면
                    isPrime = false; // 소수가 아니다
                    break; // m + 1로 시도해보자
                }
            }
            if(isPrime){ // 위 두가지 판정을 통과했다면
                cout << m << '\n'; // 그 수가 소수다
                continue; // 다음 테스트 케이스로 넘어가자
            }
        }
}