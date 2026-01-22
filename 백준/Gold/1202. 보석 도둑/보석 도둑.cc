#include <bits/stdc++.h>
using namespace std;

// 가장 작은 가방부터 최대한 큰 보석을 담으려고 해보자. 그리디 패턴.
// 그러려면 가방 무게, 보석 무게 둘다 오름차순 정렬 필요.
// 정렬 후 용량 적은 가방부터 가벼운 보석부터 무거운 보석 순으로 담기 시도.
// 담기면 가격 제일 비싼거 찾기 by pq
// 위 과정을 각 가방마다 반복.
// 그럼 가방에 한 보석이 매칭이 됐다 치자. 그럼 그 보석은 이제 다른 가방에 또 들어갈 수도 있는 거 아닌가?

// 보석을 담을 수도 못 담을 수도 있는 가방 여러개 가정. 
// 그럼 쥬얼즈 벡터는 담을 수 있는 가방 개수만큼 겹치지 않는 구간을 쪼갤 수 있다.
// 각 가방은 해당 구간에서 최대로 비싼 보석을 담는 거고 
// 한 가방에 한번이라도 시도된 쥬얼은 반복문 밖의 변수기 때문에 
// ++에 의해 다음 가방에서 다시 검사되지 않음. 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int jewelCount, bagCount;
    cin >> jewelCount >> bagCount;

    vector<pair<int,int>> jewels(jewelCount); 
    // jewels[i] = {weight, value}

    for (int i = 0; i < jewelCount; i++) {
        cin >> jewels[i].first >> jewels[i].second; // first : 무게 / second : 가격
    }

    vector<int> bagCapacities(bagCount);
    for (int i = 0; i < bagCount; i++) {
        cin >> bagCapacities[i];
    }

    // 1) 보석은 무게(first)로 오름차순
    sort(jewels.begin(), jewels.end());

    // 2) 가방이 버티는 무게도 오름차순
    sort(bagCapacities.begin(), bagCapacities.end());

    // 3) 가격 최대힙
    priority_queue<int> price;

    long long answer = 0;
    int jewel = 0; // 아직 후보에 안 넣은 가장 가벼운 보석

    // 4) 용량 적은 가방부터 시도 <= 가방 무게 오름차순 정렬 덕분
    for (const int& bagCapacity : bagCapacities) {
        
        // 이 가방이 감당 가능한 보석 전부 후보에 추가
        while (jewel < jewelCount && // 아직 모든 보석 시도 x, 
               jewels[jewel].first <= bagCapacity) { // 가벼운 보석부터 순회 <= 보석 오름차순 정렬 덕분
               
               // 작은 가방부터, 들어갈 수 있는 보석 중 가장 비싼 것을 담아
               // 큰 가방이 더 무거운 보석을 담을 기회를 남겨두기 위함.
               // “작은 것부터 최대한 이득을 취하는 패턴.”
            
            price.push(jewels[jewel].second); // 감당 가능한 보석의 가격을 price pq에 추가
            jewel++; // 한번 어떤 가방에 들어가는지 확인해본 보석은 다른 가방에서 시도조차 하지 않는다.

// 보석을 담을 수도 못 담을 수도 있는 가방 여러개 가정. 
// 그럼 쥬얼즈 벡터는 담을 수 있는 가방 개수만큼 겹치지 않는 구간을 쪼갤 수 있다.
// 각 가방은 해당 구간에서 최대로 비싼 보석을 담는 거고 
// 한 가방에 한번이라도 시도된 "쥬얼은 반복문 밖의 변수"기 때문에 
// "++에 의해 다음 가방에서 다시 검사되지 않음"
        
        }
        // 보석 무게 오름차순 정렬 안 했으면 가방이 가장 가벼운 것도 감당 못하면 그 가방은 스킵하는 논리가 조건문에서 구현 안됨
        
        // 이번 가방에 들어갈 수 있는 보석 후보 중 가장 비싼 것 선택
        if (!price.empty()) {
            answer += price.top();
            price.pop();
        }
        // 후보 가격이 없으면 그 가방이 감당할 보석이 없었던 것이므로 그 가방은 스킵
    }

    cout << answer << "\n";
    return 0;
}
