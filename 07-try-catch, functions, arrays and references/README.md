# Try-catch

## Задача Име
Дадено е име, съставено от N<1000 символа с графично представяне(напр. 1, А, о \*, ?, и тн, изключваме празни места и нови редове... ). 
Името е валидно, ако
първият му символ е главна латинска буква, а всички останали символи са малки латински букви. Напишете програма, която при дадени N и самите символи на нов
ред проверява дали името е валидно. Ако то е невалидно а) да се хвърли грешка с throw и/или б) да се прихване грешката и отпечата съобщение за грешка. Ако името е валидно - да се отпечата, но само с главни букви.  
**Пример:**  
Вход:
```text
4
Pe6o
```
Изход:
```
invalid name
```
Вход:
```text
5
Pesho
```
Изход:
```
PESHO
```

## Задача Числа
Дадени са на вход две цели числа n и k < 10^9. Входът е валиден точно когато двете числа са неотрицателни, имат равен брой цифри и 
всяко едно число не съдържа в себе си еднакви цифри.
Напишете програма която а) хвърля грешка и/или б) хваща грешката и отпечатва съобщение за грешка ако входът е невалиден. Ако входът е валиден, да отпечата сбора на числата.  
**Пример:**  
Вход:
```text
12345 12234
```
Изход:
```
invalid input - repeating digits
```
Вход:
```text
1234 4321
```
Изход:
```
5555
```

# Функции
Напишете демонстрация на вашите функции в main-функцията, прихванете евентуални грешки с catch и ги обработете(например изписвайки съобщение
за грешка).

## Задача Вектори
Напишете функция, <code>void addVectors(???)</code>, която приема за аргументи два масива a и b с равен брой елементи, както и самия брой - n<1000.
Функцията да добави втория масив към първия. Тоест за всяко $0 \leq i < n$ трябва <code>а[i] += b[i]</code>. Резултатът от действието
да бъде видим и извън функцията.

## Задача Цифри
Напишете функция, <code>int getDigits(???)</code>, която приема за аргументи цяло число n, масив **а** и size - броя на елементите му. В масива **a**
да се запишат цифрите на числото (няма значение в какъв ред) и функцията да върне броя на цифрите.  Ако някое от числата n или size е отрицателно, или броя на
цифрите на n е повече от size функцията да хвърли грешка с throw. Не е нужно при хвърляне на грешка масива **a** да е запазил първоначалните си стойности

## Задача Swap
Напишете функция <code>void mySwap(???)</code>, която приема за аргументи две променливи от целочислен тип, и разменя стойностите им. Резултата от размяната да бъде видим и извън
тялото на функцията.

## Задача Дроби
Напишете функция <code>void addFractions(int a, int b, int c, int d, ??? e, ??? f)</code>, която приема аргументи a,b,c,d,e,f и пресмята
сбора на дробите $a/b + c/d = e/f$. Резултата да бъде видим извън тялото на функцията. Ако подадените дроби са невалидни да се хвърли грешка.

## Задача Максимум
Напишете функция <code>??? getMax(???)</code> , която приема масив от цели числа заедно с броя на елементите му и дава директен достъп до максималния му елемент.  
**Пример:**  
```text
int arr[] = {1,2,3,4};  
getMax(arr,4) = -2;  
std::cout << arr[3] << " " << getMax(arr) << std::endl;
```
Изход:
```text
-2 3
```

# Бонус
## Задача Bubble Sort
Напиешете функция <code>void bubbleSort(???)</code>, която приема масив и боря на елемнтите му, и го сортира използвайки алгоритъма Bubble Sort.
Можете да ползвате вашата функция mySwap

## Задача Selection Sort
Напиешете функция <code>void selectionSort(???)</code>, която приема масив и боря на елемнтите му, и го сортира използвайки алгоритъма Selection Sort.

## Задача Двоично търсене
Напиешете функция <code>bool find(???)</code>, която приема сортиран масив, броя на елементите му, и цяло число. Функцията да върне true ако това число
е сред елементите на масива, false в противен случай. Използвайте двоично търсене.