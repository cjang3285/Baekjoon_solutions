#include <iostream>
#include <algorithm>
using namespace std;

int n, c[501], cost[501][501], total_cost[501][501]; // 1based mat

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> c[i];

        // cost[i][j]: i~j 한 번 합치는 비용 (크기 합, k와 무관하게 불변)
        // total_cost[i][j]: i~j 합치는 모든 과정의 cost 누적 최솟값
        // total_cost[i][i] = 0: 혼자는 합칠 게 없음
        // total_cost[i][j] = 1e9: min() 초기값
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j++) {
                cost[i][j] = cost[i][j-1] + c[j];
                total_cost[i][j] = (i == j) ? 0 : 1e9;
            }
        }
        // len = 대각선 인덱스. len이 고정되면 j-i가 고정 → 같은 대각선
        // len 순서로 채우면 작은 구간 먼저 보장
        // → 큰 구간 계산 시 작은 구간 값이 항상 이미 채워져 있음
        //
        // N=8 상삼각행렬 (len 표시)
        //       1    2    3    4    5    6    7    8
        //   1 [L1] [L2] [L3] [L4] [L5] [L6] [L7] [L8]
        //   2      [L1] [L2] [L3] [L4] [L5] [L6] [L7]
        //   3           [L1] [L2] [L3] [L4] [L5] [L6]
        //   4                [L1] [L2] [L3] [L4] [L5]
        //   5                     [L1] [L2] [L3] [L4]
        //   6                          [L1] [L2] [L3]
        //   7                               [L1] [L2]
        //   8                                    [L1]
        //
        // total_cost[1][7] (len=7) 계산 시 참조하는 칸: L1 + L7 / L2 + L5 / L3 + L4 이런 식으로 결국 길이가 7이 되는 것에 집중하자. 참조하는 자리들을 줄로 연결하면 두 줄이 교차하는 규칙을 볼 수 있다.
        // k=1: total_cost[1][1](L1) + total_cost[2][7](L6)
        // k=2: total_cost[1][2](L2) + total_cost[3][7](L5)
        // k=3: total_cost[1][3](L3) + total_cost[4][7](L4)
        // k=4: total_cost[1][4](L4) + total_cost[5][7](L3)
        // k=5: total_cost[1][5](L5) + total_cost[6][7](L2)
        // k=6: total_cost[1][6](L6) + total_cost[7][7](L1)
        for (int len = 2; len <= n; len++) // len은 위의 Li Lj에서 i j의 합입니다. 최소 L1 + L1 = 2(len)이므로 초기값을 2로 합니다.
            for (int i = 1; i + len - 1 <= n; i++) { 
                // len이 2(L2)면 구간의 시작점 i는 1~n-1까지 j는 2~n이 가능할 것이다. 
                // len이 3(L3)면 구간의 시작점 i는 1~n-2까지 j는 3~n이 가능할 것이다. 
                // ...
                // len이 len면 구간의 시작점 i는 1~n-(len-1)까지 j는 len~n이 가능할 것이다. 
                // i <= n-(len-1)
                // i + len - 1 <= n라는 조건문이 도출된다.
                // 또한, j는 i에서 len만큼 앞으로 갔다가 -1한 지점이라는 규칙을 알 수 있다.
                // 즉, j = i + len - 1
                int j = i + len - 1; 
                // i와 j가 결정됐으니 둘 사이를 k 지점으로 
                // [i~k] + [k+1~j] 두 덩어리로 쪼갬
                for (int k = i; k < j; k++)
                    // total_cost[i][k] + total_cost[k+1][j]: 두 덩어리 내부 누적 비용
                    // cost[i][j]: 두 덩어리를 하나로 합치는 비용 (min 바깥, k 무관)
                    total_cost[i][j] = min(total_cost[i][j], total_cost[i][k] + total_cost[k+1][j] + cost[i][j]);
            }

        cout << total_cost[1][n] << "\n";
    }
}