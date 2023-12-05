#include <iostream>


bool isValidInput(int firstYear, int firstMonth, int firstDay, int lastYear, int lastMonth, int lastDay){
    if((firstDay < 1 || firstDay > 31) || (firstMonth < 1 || firstMonth > 12) || (firstYear < 1600 || firstYear > 2100)){
        return false;
    }
    return true;
}

bool isDateChronological(int firstYear,int firstMonth, int firstDay, int lastYear,int lastMonth, int lastDay){
    if((firstYear > lastYear) || (firstYear == lastYear && (firstMonth > lastMonth || (firstMonth == lastMonth && firstDay >= lastDay)))){
        return false;
    }
    return true;
}
void printDate(int year, int month, int day) {
    std::cout << year << "-" << month << "-" << day;
}

void splitDateRange(int firstYear, int firstMonth, int firstDay, int lastYear, int lastMonth, int lastDay, int n) {
    int currentStartDateYear = firstYear; 
    int currentStartDateMonth = firstMonth; 
    int currentStartDateDay = firstDay;
    // 2023-2-23
    
    
    while (isDateChronological(currentStartDateYear, currentStartDateMonth, currentStartDateDay, lastYear, lastMonth, lastDay)) {
        
        int currentEndDateYear = currentStartDateYear;
        int currentEndDateMonth = currentStartDateMonth;
        int currentEndDateDay = currentStartDateDay + n - 1; 
        // 2023-2-27
        // 2023-2-28
        // 2023-2-28 + 5 - 1 = 2023-2-32
        
        if (currentStartDateDay > 31) {
            currentStartDateDay -= 31;
            currentStartDateMonth += 1;
        }
        if (currentStartDateMonth > 12) {
            currentStartDateMonth -= 12;
            currentStartDateYear += 1;
        }

        if (!isDateChronological(currentEndDateYear, currentEndDateMonth, currentEndDateDay, lastYear, lastMonth, lastDay)) { 
            currentEndDateDay = lastDay;
            //2023-2-27 - 2023-3-4
        }

        printDate(currentStartDateYear, currentStartDateMonth, currentStartDateDay);
        std::cout << " - ";
        printDate(currentEndDateYear, currentEndDateMonth, currentEndDateDay);
        std::cout << std::endl;
   
        currentStartDateDay = currentEndDateDay + 1;
    }
}

int main()
{
    int firstYear=2023, firstMonth=2, firstDay=23;
    int lastYear=2023, lastMonth=3, lastDay=4;

    // std::cin >> firstYear >> firstMonth >> firstDay;
    // std::cin >> lastYear >> lastMonth >> lastDay;

    if(!(isValidInput(firstYear, firstMonth, firstDay, lastYear, lastMonth, lastDay))){
        std::cout<< "Incorect input!" << std::endl;
        return -1;
    }

    if(!isDateChronological(firstYear,firstMonth,firstDay,lastYear,lastMonth,lastDay)){
        std::cout<< "Incorect input!" << std::endl;
        return -1;
    }

    int n = 5;
    //std::cin >> n;
    if(n < 1 || n > 365){
        std::cout << "Invalid input!";
        return -1;
    }

    splitDateRange(firstYear, firstMonth, firstDay, lastYear, lastMonth, lastDay, n);
    return 0;
}