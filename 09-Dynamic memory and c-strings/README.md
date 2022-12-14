# Динамична памет
За задачите използвайте динамично заделени масиви. Гарантира се, че размерите на масивите са цели числа, но те трябва да се валидират по друга причина.

## Задача 1 - Едномерен масив
Напишете програма, която приема цялото число n и редица от n цели числа. Напишете функция, която приема n и редицата с числа и връща броя на двойките съседни числа, които се различават с не повече от 1.  
**Пример:**  
Вход:
```
4
1 2 6 5
```
Функцията връща:
```
2
```

## Задача 2 - Двумерен масив
Дадена е матрица с m реда и n колони, елементите на която са цели числа. Напишете програма, която приема на вход целите числа m и n,
и на всеки следващ ред от стандартния вход - елементите от съответния ред на матрицата. Напишете функия, която приема матрицата и размерите й, и я променя по следния начин:
- намира средното аритметично на всички елементи
- замества всеки елемент с 0 ако е по-малък или равен от средното аритметично и с 1 ако е по-голям.
- подрежда 0те и 1ците във всеки ред така, че всички нули да са в началото на реда.  

**Пример:**  
Вход:
```
3 4
0 3 7 4
7 9 9 12
4 2 13 2
```
Резултат:
```
0 0 0 1
1 1 1 1
0 0 0 1
```

## Задача 3 - Назъбен двумерен масив
В една социална мрежа са регистрирани n човека и са номерирани с числата от 1 до n. Всеки човек може да последва всеки друг. Двама човека се приятели, ако са се последвали взаимно. На първия ред на стандартния вход е дадено цяло число n - броя на хората. На всяка следваща двойка редове са дадени **естественото** число count_i, и count_i на брой естествени числа, чиито стойности са между 1 и n.  
i е номера на поредната двойка редове от стандартния вход. Числото count_i представлява броя на хората, които са последвани от човека i, a на следващия ред - самите номера на хората, които е последвал.(вижте пояснението)  
Гарантирано е, че тези данни на входа са коректни: count_i е естествено, човек не е последвал себе си, не е последвал несъществуващ човек, както и не е последвал друг два пъти.  
Напишете **функция**, която приема списъка с последванията, броя на последванията на всеки човек и броя на хората, и връща броя на приятелствата в социалната мрежа.  
Ограничения: **Не използвайте излишна динамична памет**. Достатъчно е да заделите памет за толкова елементи колкото са последванията + 2*n + 2. 
 
**Пример:**  
Вход:
```
4
2
2 4
1
3
3
1 2 4
2
1 3
```
Резултат от функцията:
```
3
```

<details><summary>Пояснение</summary>
Човек 1 е последвал хора 2 и 4. Човек 2 е последвал човек 3. Човек 3 е последвал хора 1, 2 и 4. Човек 4 е последвал хора 1 и 3.
Приятелствата са (1-4), (2-3), (3-4).
</details>

# C-Низове
В задача 4 можете да позлвате функциите от ``` <cstring> ```  За да разрешите небезопасните версии на функциите, напишете   
``` #define _CRT_SECURE_NO_WARNINGS ```
преди всичко останало във вашата програма.

## Задача 4 - Речник
На стандартния вход е дадена дума myword, на следващия ред естествено число n и на следващите n реда - n думи, които представляват съдържанието на речник.
Напишете функция, която приема речника, думата myword, броя на думите в речника, и връща коя поред е myword в речника. Ако в речника я няма думата myword, функцията
да върне -1.  
Ограничения: всички думи са съставени от малки латински букви имат дължина не повече от 20 символа. **Не заделяйте излишна динамична памет.**

**Пример:**  
Вход:
```
apple
5
array
room
application
apple
grade
```
Резултат от функцията:
```
4
```

## Задача 5
Напишете функция myStrcat_s, която приема низ dest; число destsz - размера на масива, чиито първи елемент е сочен от dest; низ src и премества src в края на dest. Ако размера на новополучения низ би бил по-голям от destsz, функцията да не записва след dest+destsz-1 и да хвърли грешка.  
**Пример:**
```
char str1[100] = "abc";
mystrcat_s(str1,20,"def");
std::cout<<str1<< std::endl;
```
Изход:
```
abcdef
```
