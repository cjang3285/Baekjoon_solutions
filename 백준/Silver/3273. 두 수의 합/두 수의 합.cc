#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cin >> x;
    
    sort(v.begin(), v.end());
    
    int left = 0, right = n - 1;
    int count = 0;
    
    while (left < right) {
        int sum = v[left] + v[right];
        
        if (sum == x) {
            // L만 또는 R만 움직이면 다시 x가 될 수 없음(입력들이 서로 다른 양수였기 때문에 중복이 없으므로)
            // 그러므로 둘 중 하나만 이동하는 건 배제
            // L++, R--로 둘 다 이동
            // (L--, R++로 돌아가면 이미 검사한 조합을 다시 검사하게 되므로 금지)
            count++;
            left++;
            right--;
        } else if (sum < x) {
            // R++은 과거에 이미 시도되었거나 배제된 쌍이므로
            left++;
        } else { // sum > x
            // L--은 과거에 이미 시도되었거나 배제된 쌍이므로
            right--;
        }
    }
    
    cout << count << endl;
    
    return 0;
}