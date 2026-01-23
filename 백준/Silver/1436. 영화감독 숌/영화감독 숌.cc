#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int> v;
    int i = 665, N, n = 0;
    cin >> N;
    while (1) {
        i++; 
        int l = i;
        while (1) {
            if (l % 10) {
                v.push_back(l % 10); l /= 10;
                if (!l) break;
            }
            else {
                v.push_back(0); l /= 10;
                if (!l) break;
            }
        }
        bool b = false;
        //int cnt = count(v.begin(), v.end(), 6);
        for (int j = 0; j < v.size() - 2; j++) {
            if(v[j] == 6){
                if (v[j] == v[j + 1] ? (v[j + 1] == v[j + 2] ? 1 : 0) : 0) {
                    b = true;
                    break;
                }
            }
        }
        v = {};
        if (b) {
            n++; 
            if (n == N) {
                cout << i; break;
            }
        }
    }
    return 0;
}