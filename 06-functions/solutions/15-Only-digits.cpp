#include<iostream>

/*KUDOS to Enislav Enchev*/

bool isDigit(char symbol) {
    return (symbol >= '0' && symbol <= '9');
}

void filterDigits(char* str) {
    bool flag = false; // Показва дали сме стигнали до цифра в масива
    int i = 0, t = 0, arr[100], begin = -1, end = -1, num = 0;
    while (str[i]) {
        if (isDigit(str[i])) {
            if (begin == -1) {
                flag = true;
                    begin = i; //индекса на първата цифра на числото
            }
            end = i; //индекса на последната цифра от числото
        }
        else {
            if (flag) {
                for (int k = begin; k <= end; k++) { //от поредица от символи '1''2''3' строим цялото число 123
                    num = (num * 10) + str[k] - '0';  // ако от целочислената репрезентация на цифрата извадим '0' ще получим стойността на цифрата
                        // пример -  int('9') = 57; int('0') = 48; '9' - '0' = 57 - 48 = 9;
                }
                arr[t] = num; //прибавяме числото в изходния масив 
                num = 0;
                t++;
            }
            flag = false;
            begin = -1;
            end = -1;
        }
        i++;
    }
    for (int f = 0; f < t; f++) {
        std::cout << arr[f] << ' ';
    }

}
int main(){
    char crr[100] = "В 9 ч. тръгвам към ФМИ с автобус 94 или 120.";
    filterDigits(crr); 
}
