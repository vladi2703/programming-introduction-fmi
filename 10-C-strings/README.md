# Символни низове
Разрешено е да се ползва ``` <cstring> ```. За да разрешите небезопасните версии на функциите от ``` <cstring> ```, напишете  
```#define _CRT_SECURE_NO_WARNINGS``` на ред 1 във вашия код. 
## Задача 1 - Изтриване
Да се напише функция ``` void deleteFirst(char* str, const char* findWhat) ```, която променя низа str, като
изтрива първото срещане на findWhat. Ако няма такова, низа да остане непроменен.  
Бонус: Не ползвайте наготово strstr в задачата.    
**Пример**:  
```cpp
char str[] = "I don't like c-strings.";
deleteFirst(str,"don't ");
std::cout << str;
```
Изход:
```text
I like c-strings.
```


## Задача 2 - MaxWord
Дума в низ ще наричаме последователност от малки или главни латински букви, заобиколена от други символи или краищата на низа. Напишете функция ``` void printMax(const char * str) ```, която приема низ с произволна дължина и отпечатва на стандартния изход лексикографски най-голямата дума. Приемаме, че малките букви са лексиографски по-големи от всички главни букви(както са и в ASCII таблицата).  
Бонус: При сравненията да се пренебрегне това дали една буква е малка или главна.  
Ограничения: **Във функцията не заделяйте памет, която не използвате.**  
**Пример**:  
```cpp
printMax("I love samples and c-strings!");
```
Изход:
```text
strings
```



## Задача 3 - Паролата
Професор Х крие парола. На всеки ред от библиотеката му са подредени книги, най-много 20 реда книги, с до 30 книги на ред. Книгите на някои от редовете са подредени по азбучен ред на заглавията си, всяко от които е до 100 символа.

Паролата за сейфа на професор X се определя от числата, които задават последователните дължини на думите в заглавията на книгите, разположени точно в средата на редовете, в които книгите са подредени в азбучен ред. Ако на реда има четен брой книги, за паролата се използва книгата, намираща се по-близо до началото на  реда.  Думите  в  заглавията  на  книгите  са  разделени  от  точно  един  интервал.  Дължините  на  думите формират паролата в реда, в който се срещат, от най-горния към най-долния ред на библиотеката.

Библиотеката  на  Х  може  да  се  представи  като  двумерен  масив **a** от  низове  с **m** реда  по **n** низа  всеки, представящи заглавията на книгите. Да се дефинира функция ***revealPassword***, която по подадени **a**, **m** и **n**, извежда на стандартния изход паролата на професор X като последователност от числа, разделени с по един интервал.

**Пример:**<br>
|                                |                             |                             |
| ------------------------------ | --------------------------- | --------------------------- |
| Algebra                        | Analytic Geometry           | Calculus                    |
| Databases                      | Artificial Intelligence     | Functional Programming      |
| Data Structures and Algorithms | Introduction to Programming | Object-oriented Programming |

Тогава паролата на професор X е поредицата от числа `8 8 12 2 11`, получена от дължините на подчертаните думи. Думите “Artificial Intelligence” не участват в паролата, защото книгите на втория ред не са подредени по азбучен ред на заглавията си.



## [Задача 4 - Шоколад](http://www.math.bas.bg/infos/files/2008-12-02-D3.pdf)



## Задача 5 - Отдалечени близнаци

Да се състави функция, която приема като параметър низ с произволна дължина и връща като резултат позициите на двойката **еднакви** символи, които са максимално отдалечени един от друг. Ако в низа съществуват няколко двойки максимално отдалечени символи, функцията да връща позициите на най-ляво разположената двойка. Счита се, че номерата на позициите започват от 0.

**Пример**:<br>
Вход:
```cpp
"this is just a simple example"
```
Изход:
```text
4 21
```

Пояснение: символи ' ' (интервали) са на позиции, съответно 4 и 21, намират се на разстояние 17 символа един от друг и няма друга двойка еднакви символи, които са на по-голямо разстояние един от друг.