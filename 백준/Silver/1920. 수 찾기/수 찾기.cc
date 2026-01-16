#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 존재 여부가 중요하지 정렬 여부는 중요하지 않아서 unordered_set 사용.
    // 버킷, 해시 기반. 조회 시간복잡도 O(1). 
    // set 사용시 bst이고 조회시 O(logN) 걸림.
    unordered_set<int> s;
    s.reserve(n);        // 해시 재할당 줄여서 속도 안정

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int m;
    cin >> m;

    while(m--) {
        int x;
        cin >> x;
        // count()는 O(1), s.find(x) != s.end() 조건으로도 가능. 
        cout << (s.count(x) ? 1 : 0) << '\n';
    }

    return 0;
}
