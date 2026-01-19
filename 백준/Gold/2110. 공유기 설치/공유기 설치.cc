#include <bits/stdc++.h>
using namespace std;

// house_pos : 집 좌표들
// desired_installed_router_count : 설치해야 할 공유기 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int house_count, desired_installed_router_count;
    cin >> house_count >> desired_installed_router_count;

    vector<int> house_pos(house_count);
    for (int i = 0; i < house_count; i++) {
        cin >> house_pos[i];
    }

    // 1. 집 좌표 정렬
    sort(house_pos.begin(), house_pos.end());

    // 2. 이분 탐색 범위
    int left = 1;   // 가능한 최소 거리
    int right = house_pos.back() - house_pos.front(); // 최대 거리
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        // 이 거리로 공유기 몇 개 설치 가능한지 체크해보자
        int installed_router_count = 1;  // 첫 집에 무조건 설치하므로 1개 이미 설치한 상태에서 시작
        int last_installed_pos = house_pos[0]; // 첫집 위치가 첫 마지막으로 설치한 위치 값으로 들어간다.
        
        // 이번 mid 거리로 최대한 많이 공유기를 설치해보자.
        // 첫번째 집은 이미 설치, 위치 저장했으니
        // i = 1로 시작. 두번째 집부터 순회.
        for (int i = 1; i < house_count; i++) {
            if (house_pos[i] - last_installed_pos >= mid) { // 최소 거리 이상이면 설치가능하니까
                installed_router_count++; // 설치한 개수 늘리고
                last_installed_pos = house_pos[i]; // 마지막 설치 위치를 이번 위치로 갱신
            }
        }

        // 공유기를 최대한 설치했으니 설치된 공유기 수가 요구사항에 미치는지 체크하자
        if (installed_router_count >= desired_installed_router_count) {// 요구사항 이상 달성했다.
            answer = mid; // 일단 성공한 이번 거리를 저장하고
            left = mid + 1; // 그럼 거리를 더 늘려보자 -> 오른쪽 조각으로
        } 
        else { // 요구사항 달성 실패
            right = mid - 1; // 더 촘촘히 설치하자 -> 왼쪽 조각으로
        }
    }

    cout << answer;
    return 0;
}
