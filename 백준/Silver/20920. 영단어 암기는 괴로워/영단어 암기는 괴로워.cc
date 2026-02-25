#include<bits/stdc++.h>
using namespace std;

struct Compare {
    const map<string, int>& word_freq;
    // 멤버변수 word_freq가 wf로 받은 메인 함수의 word_freq를 참조
    Compare(const map<string, int>& wf) : word_freq(wf) {}
    
    // 자주 나오는 단어일수록 앞에 배치한다. <- map(키, 밸류 형태/정렬상태)과 map의 at 메서드 사용. [키]로 키의 밸류 접근시 존재하지 않는 키(워드)면 임의로 map에 새 키가 만들어질 수 있어 사용 자제. 
    // 해당 단어의 길이가 길수록 앞에 배치한다. <- length() 사용
    // 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다 <- a < b
    bool operator()(const string& a, const string& b) const {
        if (word_freq.at(a) != word_freq.at(b)) return word_freq.at(a) > word_freq.at(b);
        if (a.length() != b.length()) return a.length() > b.length();
        return a < b;
    }
};

int main(){
    // 단어의 개수 N, 외울 단어의 길이 기준이 되는 M
    int N; int M;
    cin >> N >> M;
    
    vector<string> words;
    
    while(N--){
        string word;
        cin >> word; // 입력은 알파벳 소문자로만 주어지며 단어의 길이는 
                     // 10을 넘지 않는다.
                     // 단어장에 단어가 반드시 1개 이상 존재하는 입력만 주어진다.
        words.push_back(word);
    }
    
    map<string, int> word_freq;
    // 키들과 0 입력
    // map은 자동으로 [word]로 접근 시 키 word가 없으면 word, 0으로 생성됨
    // 입력된 단어 등장할 때마다 해당 단어 카운트 증가
    for(const string& word : words){
        word_freq[word]++;  // map에는 push_back이 없고 한 줄로 충분
    }

    // sort()는 내부적으로 두 원소를 비교할 때마다 비교자를 호출한다.
    // Compare(word_freq)는 생성자 호출.
    // 비교자는 메인의 지역변수 word_freq를 멤버변수인 word_freq으로 입력받은 상태다.
    // 그래서 sort함수가 words 벡터의 두 원소를 골라서 
    // Compare의 () 연산자를 호출하면 
    // 이미 Compare 객체는 메인의 word_freq을 인자로 받아서 alias를 가지고 있으니 
    // () 연산자 호출 시 alias로 접근하여 정렬기준에 부합하게 true, false를 반환한다.
    // sort()가 true/false에 따라 words 배열을 재배열한다.
    sort(words.begin(), words.end(), Compare(word_freq));
    
    // unique()는 정렬된 배열에서 중복된 원소를 뒤로 밀어내고, 고유 원소들만 가진 벡터가 생겼다 할 때에 그 고유 원소들만 가진 벡터의 end()를 반환한다.
    // 그러면 그 고유 원소 구간의 end()와 원래 words의 end()를 인자로 사용해 
    // 중복된 원소들은 erase()로 제거한다. -> 고유 원소들만 남긴다.
    words.erase(unique(words.begin(), words.end()), words.end());
    
    // 정답 출력
    for(const string& word : words){
        if(word.length() >= M) {  // M 이상인 단어만
            cout << word << '\n';
        }
    }
}