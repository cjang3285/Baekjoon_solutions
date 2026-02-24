#include<bits/stdc++.h>
using namespace std;

bool isPrime = false;

int main(){
    while(1){
        int N; 
        cin >> N;
        if(N == 0){ // 입력의 마지막에는 0이 주어진다.
            return 0;
        }
        
        int prime_cnt = 0;
        // n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력
        for(int n = N + 1; n <= 2 * N; n++){
            // 가정한다
            bool isPrime = true; 
            
            // 0 ≤ n이므로 예외처리
            if(n == 1 || n == 0) isPrime = false; // 1은 소수 아니다
            
            // 2 이상의 정수로 나누어 떨어지는지 확인하자
            // d ≤ √n ⟺ d^2 ≤ n
            for(long long d = 2; d*d <= n; d++){ // sqrt를 애초에 안쓴다
                if(n % d == 0){ // 나누어 떨어지면
                    isPrime = false; // 소수가 아니다
                    break; // 이제 n+1이 소수인지 확인해보자
                }
            }
            if(isPrime){ // 위 두가지 판정을 통과했다면
                prime_cnt++; // 그 수가 소수다
            } // 이제 n+1이 소수인지 확인해보자
        }
        
        cout << prime_cnt << '\n';
        prime_cnt = 0;
    }
}