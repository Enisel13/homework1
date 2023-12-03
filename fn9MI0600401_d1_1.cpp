#include <iostream>

int findDivisorsCount(int number){
    int counter = 0; 
    for(int i = 1; i<= number; i++){
        if(number % i == 0){
            counter++;
        }
    }
    return counter;
}

bool pairsMatch(int k, int x, int y){
    if(k*findDivisorsCount(x)*findDivisorsCount(y)==x*y){
        return true;
    }
    return false;
}

int main(){
    unsigned int n, k;
    std::cin >> n >> k;
    if(n <= 0 && k <= 0){
        std::cout << "Incorrect input!";
        return -1;
    }

    int counter = 0;

    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= i; j++){
            if (i>=j)
            {
                if (pairsMatch(k,j,i)){
                    counter++;
                }
            }
        }
        
    }
    std::cout << counter << std::endl;
    return 0;
}