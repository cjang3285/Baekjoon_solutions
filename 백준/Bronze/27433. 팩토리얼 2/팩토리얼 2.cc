#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 0; 
    long long fact = 1;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    cout << fact;
}
