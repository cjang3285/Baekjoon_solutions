#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 입력 개수 n 받기
    int n;
    cin >> n;
    
    // 수들을 저장할 배열과 합 계산용 변수
    vector<int> arr(n);
    int sum = 0;
    
    // 모든 수 입력받기
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    // 1. 산술평균 (반올림) 
    // sum을 n으로 나누면 평균이 나옴
    // round()는 소수점 첫째 자리에서 반올림 (예: 3.5 → 4)
    int mean = round((double)sum / n);
    cout << mean << "\n";
    
    // 2. 중앙값
    // 중앙값을 구하려면 먼저 정렬해야 함
    sort(arr.begin(), arr.end());
    // n이 홀수이므로 arr[n/2]가 중앙값 (예: n=5일 때 0 1 "arr[2]" 3 4가 중앙)
    int median = arr[n / 2];
    cout << median << "\n";
    
    // 3. 최빈값
    // map: 각 숫자를 key로, 나타난 횟수를 value로 저장
    // map은 자동으로 key를 오름차순 정렬함
    map<int, int> freq;
    for (int x : arr) {
        freq[x]++;  // x가 나타날 때마다 카운트 증가
    }
    
    // 가장 많이 나타난 횟수(최대 빈도) 찾기
    int maxFreq = 0;
    for (auto& p : freq) {
        // p.first: 숫자, p.second: 나타난 횟수
        maxFreq = max(maxFreq, p.second);
    }
    
    // 최대 빈도를 가진 모든 숫자들을 modes 벡터에 모으기
    // (최빈값이 여러 개일 수 있음)
    vector<int> modes;
    for (auto& p : freq) {
        if (p.second == maxFreq) {
            modes.push_back(p.first);
        }
    }
    
    // 최빈값이 여러 개면 두 번째로 작은 값 선택
    // 최빈값이 1개면 그것 선택
    int mode = (modes.size() > 1) ? modes[1] : modes[0];
    cout << mode << "\n";
    
    // 4. 범위
    // 배열이 정렬되어 있으므로 arr[n-1]이 최댓값, arr[0]이 최솟값
    int range = arr[n - 1] - arr[0];
    cout << range << "\n";
    
    return 0;
}