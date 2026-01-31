#include <bits/stdc++.h>
using namespace std;

//  [F(n+1) F(n)
//   F(n)   F(n−1)] = [1 1
//                     1 0]^n

using ll = long long;
const ll MOD = 1000000007;
const int N = 2; // 2x2 고정

vector<vector<ll>> mat_mul(const vector<vector<ll>>& X,
                           const vector<vector<ll>>& Y){
    vector<vector<ll>> Z(N, vector<ll>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                Z[i][j] = (Z[i][j] + X[i][k] * Y[k][j]) % MOD;
            }
        }
    }
    return Z;
}

vector<vector<ll>> mat_exp(vector<vector<ll>> A, ll B){
    if(B == 0){
        vector<vector<ll>> I(N, vector<ll>(N, 0));
        for(int i = 0; i < N; i++) I[i][i] = 1;
        return I;
    }
    
    auto half = mat_exp(A, B/2);
    auto res = mat_mul(half, half);
    
    if(B % 2 == 1)
        res = mat_mul(res, A);
    
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<vector<ll>> M = {
        {1, 1},
        {1, 0}
    };

    auto R = mat_exp(M, n);

    // F(n) = R[0][1] 혹은 R[1][0]
    cout << R[0][1] << '\n';
}
