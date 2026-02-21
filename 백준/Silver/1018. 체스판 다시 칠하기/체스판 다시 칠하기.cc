#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int N, M; string S; int cnt[2]{ 0 };
	vector<int> v, V;
	cin >> N >> M;
	//2차원 배열 동적 할당
	int** board = new int* [N];

	for (int i = 0; i < N; i++)
		board[i] = new int[M];

	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < M; j++) {
			board[i][j] = !(S[j] - 'B'); // 1은 B 0은 W
			//cout << board[i][j] << " ";
		}
		//cout << endl;
	}//board 값 할당에는 문제 x


	for (int n = 0; n + 7 < N; n++) {
		for (int m = 0; m + 7 < M; m++) {
			for (int i = n; i < n + 8; i++) {
				int line[8] = { 0 }; //각 라인의 정답
				// 매 S마다 답지 line 생성
				for (int w = 0; w < 2; w++) {
					if (!w) { //B 먼저
						for (int e = 0; e < 8; e++) {
							if (e % 2 == 0)
								line[e] = 1;
							else
								line[e] = 0;
						}
					}
					else { //W 먼저
						for (int e = 0; e < 8; e++) {
							if (e % 2 == 0)
								line[e] = 0;
							else
								line[e] = 1;
						}
					}

					for (int o = m; o < m + 8; o++) {
						if (board[i][o] != line[o - m]) {
							cnt[!w]++;
						}
					}
					//b,w 답안 틀린 수 집계 완료
					v.push_back(cnt[!w]);
				}
				cnt[0] = 0; cnt[1] = 0;
			}//박스 처리 완료

			//int b = 0 + 16 * (n + m), sum = 0, base_b = 0 + 16 * (n + m);
			//int b = 16*(n+1)*(m+1)-16, sum = 0, base_b = 16 * (n + 1) * (m + 1) - 16;
			int b = v.size() - 16, sum = 0, base_b = v.size() - 16;
			while (1) {
				sum += v[b];
				b += 3;
				sum += v[b];
				if (b - base_b == 15) { //만들어지는 박스 개수 다 돌고 break;
					V.push_back(sum);
					break;
				}
				b += 1;
			}

			sum = 0;
			//b = 1 + 16 * (n + m); base_b = 1 + 16 * (n + m);
			b = v.size() - 15; base_b = v.size() - 15;
			while (1) {
				sum += v[b];
				b += 1;
				sum += v[b];
				if (b - base_b == 13) {
					V.push_back(sum);
					break;
				}
				b += 3;
			} //한 박스의 B, W 각 답안에 의해 틀린 수 집계 완료
		}
	}
	cout << *min_element(V.begin(), V.end()); //int 배열에서 최소값 찾을 때는 arr, arr+size
}