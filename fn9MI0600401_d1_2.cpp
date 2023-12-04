#include <iostream>

void makeAllElementsZero(int arr[], size_t size){
    
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
}

int printOccurencies(int frequenceArray[], size_t size){
    
    int sum = 0;
    for(int i = 2; i < size; i++){
        std::cout << "Number:" << i << " have: " << frequenceArray[i] <<" occurences"<< std::endl;
        if(frequenceArray[i] > 0){
            sum+=i+1;
        }
    }
    return sum;
}

void getCurrentOccurencies(const int arr[], size_t size){
   
    const int maxSize = 1000;
    int frequenceArray[maxSize];
    makeAllElementsZero(frequenceArray, size);

    for(int i = 0; i < size; i++){
        frequenceArray[arr[i]]++;
    }
    std::cout << printOccurencies(frequenceArray, size) << std::endl;
    //return numberOfOccurencies;
}

int main(){

    unsigned int answers;
    std::cin >> answers;
    int arr[answers];

    unsigned int sum1 = 0;
    unsigned int sum2 = 1;

    if(!(answers >=1 && answers <= 1000)){
        std::cout << "Incorrect input!" << std::endl;
        return -1;
    }

    for(int i = 0; i < answers; i++){
        std::cin >> arr[i];
        if(arr[i] < 0 || arr[i] > 1000)
        {
            std::cout << "Incorect input!";
            return -1;
        }
    }
    
    getCurrentOccurencies(arr, answers);

    // for(int i = 0; i < answers; i++){
    //     if(arr[i] == 1){
    //         sum1++;
    //     }
    //     if(arr[i] == 0){
    //         sum1++;
    //     }
    //     if(arr[i] > 1){
    //         sum2+= arr[i];
    //     }
    //     if(arr[i] + 1 % sum2 != 0){
                
    //        }
    // }

    // int total = sum1 + sum2;
    // std::cout << "sum1: "<< sum1 << std::endl;
    // std::cout << "sum2: "<< sum2 << std::endl;
    // std::cout << "total: "<< total << std::endl;
   
    return 0;
}