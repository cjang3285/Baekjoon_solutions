#include<bits/stdc++.h>
using namespace std;

int gcd_of_vector(const vector<int>& diff) {
    int result = diff[0]; 
    for (size_t i = 1; i < diff.size(); i++) { 
        result = gcd(result, diff[i]); // gcd(a, b, c) = gcd(gcd(a, b), c) : 결합법칙 성립
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    
    // tree는 나무들의 위치
    vector<int> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    
    // diff[i] = i번째 나무와 i+1번째 나무의 간격 => n-1개의 간격 도출
    vector<int> diff;
    for (int i = 1; i < n; i++) {
        diff.push_back(tree[i] - tree[i - 1]);
    } // diff의 크기는 n-1 : diff[0]부터 diff[n-1]까지 차있음
    
    // diff 값들의 최대 공약수 = 목표 나무 간격
    int spacing = gcd_of_vector(diff);
    
    int cnt = 0;
    for(int j = 0; j < n - 1; j++){// diff의 크기는 n-1
        cnt += (diff[j] / spacing) - 1; 
        // 실제 나무 간격들 목표 나무 간격으로 나눈 수에서 1은 이미 목표 간격인 나무 하나를 의미하니 제외한다 
        // 그렇게 나온 수가 cnt에 합산된다 => 목표 간격을 이루기 위해 더 심어야 하는 나무 수
    }
    cout << cnt;
}
