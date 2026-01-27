#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    // 정렬하거나 min, max를 따로 찾아도 됨
    sort(v.begin(), v.end());
    // 가장 작은 값과 가장 큰 값을 곱하면 원래 수 N
    cout << (long long)v.front() * v.back() << '\n';
    return 0;
}