#include <bits/stdc++.h>
using namespace std;

long long N, B;

vector<vector<long long>> mat_mul(const vector<vector<long long>>& X,const vector<vector<long long>>& Y){
    vector<vector<long long>> Z(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                Z[i][j] = (Z[i][j] + X[i][k] * Y[k][j]) % 1000; // mod 적용
            }
        }
    }
    return Z;
}

vector<vector<long long>> mat_exp(vector<vector<long long>> A, long long B){
    if(B == 0){
        vector<vector<long long>> I(N, vector<long long>(N, 0));
        for (int i = 0; i < N; i++) {
            I[i][i] = 1; // 대각선 1
        }    
        return I;
    }
    
    vector<vector<long long>> mat(N, vector<long long>(N, 0));
    mat = mat_exp(A, B/2);
        
    if (B % 2 == 0){ // B가 짝수면
        mat = mat_mul(mat, mat);
    }
    else{ // 홀수면
        mat = mat_mul(mat, mat);
        mat = mat_mul(mat, A);
    }
    return mat; // A^B
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> B;
    
    // 행렬 A 입력
    vector<vector<long long>> A(N, vector<long long>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> A[i][j];
    
    // 연산부
    A = mat_exp(A, B);
    
    // 결과 출력
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}
