#include<iostream>
using namespace std;

int main(){
    int sum = 0;
    for(int i =0; i < 5; i++){
        int j =0;
        cin >> j;
        sum += j;
    }
    cout << sum;
}