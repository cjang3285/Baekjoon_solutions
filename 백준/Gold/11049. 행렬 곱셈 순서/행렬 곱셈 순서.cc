#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> p(n + 1);
    
    for (int i = 0; i < n; i++) {
        long long r, c;
        cin >> r >> c;
        if (i == 0) p[0] = r;
        p[i + 1] = c;
    }
    
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], 
                    dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j]);
            }
        }
    }
    
    cout << dp[1][n] << "\n";
    
    return 0;
}