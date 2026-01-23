#include<iostream>

int main(){
    int n,x,v= 0;
    std::cin >> n >> x;
    int a[n];
    
    for(int i=0; i<n; i++){
        std::cin >> v;
        
        a[i] = v;
    }
    
    for(int i = 0; i<n; i++){
        if(x>a[i])
            std::cout << a[i] << " ";
    }
}