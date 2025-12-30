#include <bits/stdc++.h>
using namespace std;
// 회문 검사
string recursion(const string& s, int l, int r, int& cnt){
    cnt++;
    if(l >= r) { // 좌측 문자와 우측 문자가 만나거나 지나치면 회문 검사 통과 
        return "1 " + to_string(cnt) + '\n';
    }
    else if(s[l] != s[r]) { // 좌측 우측 문자가 다르면 회문 아님
        return "0 " + to_string(cnt) + '\n';
    }
    else { // 좌우측 문자가 아직 안 만났고 같으면 좌우 모두 한칸씩 안쪽으로 가며 일치하는지 검사.
        return recursion(s, l+1, r-1, cnt);
    } // else 블록 안에 cnt를 넣으면 안되는 이유 : 처음부터 if, else if로 들어가면 호출이 되었어도 cnt가 증가되지 않음.
}

string isPalindrome(const string& s, int& cnt){
    // s.length()는 부호 없는 정수(size_t)를 반환합니다. 만약 빈 문자열("")이 입력되면 0 - 1이 되어 아주 큰 양수(언더플로우)가 발생할 수 있습니다.
    // 안전하게 하려면 (int)s.length() - 1로 형변환
    return recursion(s, 0, (int)s.length()-1, cnt);
}

int main(){
    int t; 
    cin >> t;
    while(t--){
        int cnt = 0;
        string str;
        cin >> str;
        cout << isPalindrome(str, cnt);
    }
}