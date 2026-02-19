#include<bits/stdc++.h>
using namespace std;

vector<int> a(11);
vector<int> o(5);
int N, result, tmp, min_res = 1e9, max_res = -1e9;

void backtrack(int depth) {
    if(depth == N) { //depth 1~N-1까지 N-1개의 연산 완료. N에서 결과 출력
        min_res = min(min_res, result);
        max_res = max(max_res, result);
        return;
    }

    for(int i = 1; i <= 4; i++) {
        if(o[i] > 0) {
            int tmp = result;
            if(i == 1)
                result += a[depth];
            else if(i == 2)
                result -= a[depth];
            else if(i == 3)
                result *= a[depth];
            else if(i == 4)
                result /= a[depth];
             // 선택
            o[i]--;
            
            backtrack(depth+1); // 다음 단계
            
            if(i == 1)
                result -= a[depth];
            else if(i == 2)
                result += a[depth];
            else if(i == 3)
                result /= a[depth];
            else if(i == 4) // 나머지는 나누면서 사라져서 그냥 tmp로 되돌림
                result = tmp;            // 되돌리기
            
            o[i]++;
        }
    }
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> a[i];

    for(int i = 1; i <= 4; i++)
        cin >> o[i];
    
    result = a[0];
    backtrack(1);
    
    cout << max_res << '\n' << min_res;
}