#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int currNum;
    std::cin >> currNum;
    int min_val = currNum, max_val = currNum;
    int sum = currNum;
    
    for(unsigned i=1; i<n; ++i)
    {
        std::cin >> currNum;
        sum +=currNum;
        if(min_val > currNum) {
            min_val = currNum;
        }
        if(max_val < currNum){
            max_val = currNum;
        }
    }

    sum -= min_val;
    sum -= max_val;

    int resultWholePart = (( sum*100 ) / ( n-2 )) / 100;
    int resultFractionPart = (( sum* 100 )/( n-2 ) ) % 100;

    std::cout << resultWholePart ;
    if(resultFractionPart >= 10 && resultFractionPart % 10 != 0) // дробната част е от две цифри
        std::cout << '.' << resultFractionPart; 
    else if(resultFractionPart >= 10 && resultFractionPart % 10 == 0) // една цифра е нужна за дробна част
        std::cout << '.' << resultFractionPart/10;       
    else if(resultFractionPart >= 1)                     // 2 цифри са нужни, но първата е 0
        std::cout << ".0" << resultFractionPart;
    // else  resultFractionPart == 0 then do nothing
    std::cout << '\n';

    return 0;
}