#include <bits/stdc++.h>
using namespace std;

// LIS = Longest Increasing Subsequence
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> raw(N);
    for(int i = 0; i < N; i++)
        cin >> raw[i];
    
    // Longest Increasing Subsequence -> tails
    // tails[i] = 길이 i+1인 증가수열이 가질 수 있는 최소 끝값
    vector<int> tails;

    for(const int& ele : raw) {
        // ele 이상(≥ ele)인 첫 번째 원소의 위치
        auto pos = lower_bound(tails.begin(), tails.end(), ele);
        
        // ele 이상이 없으면
        if(pos == tails.end())
            tails.push_back(ele); // 가장 마지막에 추가
        else // 있었으면
            *pos = ele; // ele 이상인 첫 원소를 같거나 더 작은 ele로 바꿔치기 => 이후 올 꼬리가 더 많아지게
    }

    cout << tails.size();
}
