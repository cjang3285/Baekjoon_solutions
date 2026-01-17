#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    cin >> N >> M;

    vector<long long> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    // 1. 내림차순 정렬 (높은 나무부터 처리)
    sort(trees.begin(), trees.end(), greater<long long>());
    
    // 마지막에 가상의 높이 0인 나무를 추가하여 경계값 처리
    trees.push_back(0);

    long long current_height = trees[0];
    long long wood_collected = 0;
    long long tree_count = 0;

    for (int i = 0; i < N; i++) {
        tree_count++; // 현재 높이에서 함께 잘리는 나무의 수 (기울기)
        
        // 다음 나무와의 높이 차이 계산
        long long height_diff = trees[i] - trees[i+1];
        long long potential_wood = tree_count * height_diff;

        if (wood_collected + potential_wood >= M) {
            // [핵심 공식] 더 이상 내려가지 않고 여기서 정답을 바로 계산
            // 필요한 만큼만 더 자르면 됨: (남은 목표량 / 현재 잘리는 나무 수)
            long long needed = M - wood_collected;
            long long additional_cut = (needed + tree_count - 1) / tree_count; // 올림 처리
            
            cout << trees[i] - additional_cut << endl;
            return 0;
        }

        wood_collected += potential_wood;
    }

    return 0;
}