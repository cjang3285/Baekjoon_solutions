#include<bits/stdc++.h>
using namespace std;

int factorial(int x){
    int result = 1;
    for(int i = 1; i <= x; i++){
        result *= i;
    }
    return result;
}

void print_combination(const int& n, const int& k){
    cout << factorial(n) / (factorial(k) * factorial(n - k)); 
}

int main(){
    int n,k;
    cin >> n >> k;
    
    print_combination(n,k);
    return 0;
}