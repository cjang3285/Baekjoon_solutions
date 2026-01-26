#include <bits/stdc++.h>
using namespace std;

/*
행렬곱의 본질 (선형대수 시각)

C = A x B

C[i][j] 는
A의 i번째 "행 벡터" 와
B의 j번째 "열 벡터" 의 내적(dot product)

A (N x M)                B (M x K)

      k=0   k=1   k=2        j
     ┌────┬────┬─────┐      ↓
i ─▶│ a  │ a  │ a  │   ┌──────────┐
     │ i0 │ i1 │ i2 │   │ b 0j    │
     └────┴─────┴────┘   │ b 1j    │
                        │ b 2j    │
                        └──────────┘

C[i][j] = a[i][0]*b[0][j]
        + a[i][1]*b[1][j]
        + a[i][2]*b[2][j]
        + ...

즉, "가로 한 줄" 과 "세로 한 줄" 을 곱해서 더한 값
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> A[i][j];

    cin >> M >> K;
    vector<vector<int>> B(M, vector<int>(K));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            cin >> B[i][j];

    vector<vector<int>> C(N, vector<int>(K, 0));

    // 핵심: i행 j열 = A의 i행 벡터 · B의 j열 벡터
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}