#include<bits/stdc++.h>
using namespace std;

/* 메모리 크기 문제: tmp 배열이나 A 배열의 크기가 매우 큽니다(최대 50만). 
함수 내부(스택 영역)에 큰 배열을 선언하면 스택 오버플로우(Stack Overflow)가 
발생하여 프로그램이 강제 종료될 수 있습니다. 

전역 변수는 힙/데이터 영역을 사용하여 훨씬 큰 메모리를 안전하게 쓸 수 있습니다.

재귀 함수의 복잡성 방지: 

cnt나 K, result를 지역 변수로 만들면, 
모든 재귀 함수마다 이 값들을 참조자(&)로 계속 넘겨줘야 합니다. 

함수 인자가 많아지면 코드가 복잡해지고 실수하기 쉽습니다. */

int tmp[500001]; // 수도코드의 tmp 배열
int cnt = 0;     // 저장 횟수를 셀 변수
int K;           // 찾고자 하는 K번째 저장
int result = -1; // K번째 저장된 수를 담을 변수 (기본값 -1)

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.

// 병합 정렬(Merge Sort)은 배열을 쪼갠 뒤 다시 합치면서 정렬하는데, 
// 합칠 때마다 tmp 배열에 순서대로 나열한 뒤, 그걸 다시 배열 A에 복사합니다. 
// 이 복사(대입) 과정이 '저장'입니다.
void merge(vector<int>& A, int p, int q, int r) {
    int i = p; 
    int j = q + 1; 
    int t = 1;
    while (i <= q && j <= r) { // 다루는 왼쪽 원소가 왼쪽 배열에 속하고 오른쪽 원소가 오른쪽 배열일 때
        if (A[i] <= A[j]){
            tmp[t++] = A[i++]; // tmp[t] = A[i]; t++; i++;
        }
        else {
            tmp[t++] = A[j++]; // tmp[t] = A[j]; t++; j++;
        }
        
    }
    while (i <= q) // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    while (j <= r) // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    
    i = p; t = 1;    /////////////////////////////////////////////////////
    while (i <= r){  // 결과를 A[p..r]에 저장 => 여길 k번째 지나며 저장한 수가 k 번째 저장한 수
        cnt++;
        if (cnt == K) result = tmp[t]; // K번째 저장되는 순간을 포착
        A[i++] = tmp[t++]; 
    }
}

void merge_sort(vector<int>& A, int p, int r) { // A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = (p + r) / 2;       // q는 p, r의 중간 지점, 정수형 / 2라서 이미 바닥 처리
        merge_sort(A, p, q);      // 전반부 정렬
        merge_sort(A, q + 1, r);  // 후반부 정렬
        merge(A, p, q, r);        // 병합
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    if (!(cin >> n >> K)) return 0; // 전역 변수 K에 직접 입력받음
    
    /* vector<int> A;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a; // cin >> A[i] 가능?
        A.push_back(a);
    } */
    
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    // merge_sort 호출 (시작 인덱스 0, 끝 인덱스 n-1)
    merge_sort(A, 0, n-1);
    // K번째 저장된 수 출력 (없으면 초기값 -1 출력)
    cout << result;
    
    return 0;
}