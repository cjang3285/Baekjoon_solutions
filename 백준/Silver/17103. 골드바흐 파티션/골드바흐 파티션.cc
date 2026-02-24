#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    // 1. N들을 다 받는다.
    // 짝수 N들이 들어갈 벡터
    vector<int> Ns(T, 0);
    for(int i = 0; i < T; i++){
        cin >> Ns[i];
    }
    
    // 2. 가장 큰 N을 가지고, N-2까지의 소수들을 모두 구하여 벡터에 모두 저장한다.
    int max = *max_element(Ns.begin(), Ns.end());
    vector<bool> isPrime(max + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i * i <= max; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= max; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for(int i = 2; i <= max; i++){
        if(isPrime[i])
            primes.push_back(i);
    }
    
    // 3. 각 N들에 대해 소수 벡터에서 2부터 N보다 작은 소수들까지의 범위를 초기범위로 해서 투 포인터로 합이 N인 경우 카운트
    for(const int& N : Ns){
        
        /*
        int i = 1;
        for(i = 1; primes[i] < N; i++){}... 각 N에 맞게 투포인터에서 R이 되어줄 소수벡터에서의 i를 찾는 건 사치일지도 모른다. R을 size로 주고 각 N들을 투 포인터에게 맡겨보자.
        */
        
        // 이 시점에서 prime[i]가 투포인터의 R이 된다.
        // L은 prime[1]이다.

        // 투포인터 시작
        int L = 0, R = (int)primes.size() - 1;
        int N_partition_cnt = 0;
    
        while (L <= R) {
            int sum = primes[L] + primes[R];
        
            if (sum == N) {
                N_partition_cnt++;
                L++;
                R--;
            } else if (sum < N) {
                L++;
            } else { // sum > x
                R--;
            }
        }
    
        cout << N_partition_cnt << '\n'; 
    }
    
    
    // 골드바흐 파티션: 2보다 큰 짝수를 두 소수의 합으로 나타내는 표현
    /*
    6 3 3
    8 3 5 
    10 3 7, 5 5
    12 5 7 
    100 ...
    */
    //   파티션의 개수!
}