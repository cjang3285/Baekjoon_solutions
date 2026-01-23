#include<iostream>
#include<string>
#include<unordered_set> // 필요
#include<algorithm>
using namespace std;

int main(){
    unordered_set<string> S; // 해시 테이블 (문자열 집합)
    int n,m, cnt = 0;
    cin >> n >> m;
    
    // 집합 S에 n개 문자열 저장
    for(int i =0; i< n; i++){
        string str;
        cin >> str;
        S.insert(str); // O(1) 삽입
    }
    
    // m개 문자열이 S에 있는지 확인
    for(int j =0; j < m; j++){
        string str;
        cin >> str;
        if(S.find(str) != S.end()) // O(1) 탐색, 있으면 반복자(그 자리) 반환, 없으면 .end() 반환 
            cnt++;
    }
    
    // 시간 복잡도 : O(N + M) - 해시 테이블
    cout << cnt << '\n';
}