# Многомерни масиви

## Задача 1  - Сумирай

Имате предварително въведени стойности от естествени числа, принадлежащи на интервала `[10..99]`. Числата са въведени в квадратна таблица с размери 6 реда и 6 колони. Да се състави програма, чрез която се намира и извежда сумата на всички елементи за всяка колона с нечетен номер: 1, 3 и 5. Програмата да извежда и общата сума на всички колони.

```
int input[N][N] = {
	{11, 12, 13, 14, 15, 16}, 
	{21, 22, 23, 24, 25, 26}, 
	{31, 32, 33, 34, 35, 36}, 
	{41, 42, 43, 44, 45, 46}, 
	{51, 52, 53, 54, 55, 56}, 
	{61, 62, 63, 64, 65, 66}
};

Изход:
Row 1 sum is: 216 (сума от елементите 11, 21, 31, 41, 51, 61)
Row 3 sum is: 228 (сума от елементите 13, 23, 33, 43, 53, 63)
Row 5 sum is: 240 (сума от елементите 15, 25, 35, 45, 55, 65)
Total sum is: 684 (сума на елементите)
```

## Задача 2 - Positive diag 

Дадена е квадратна матрица с реални числа А с размерност `KxK`. Да се състави програма, която намира и извежда неотрицателните елементи върху главния диагонал.



## Задача 3 - Magic square
Да се напише програма, която въвежда квадратна матрица с размери *n* x *n*  от цели числа и използва функция, за да провери дали матрицата е "магически квадрат" (сумите по редовете и стълбовете да са равни).

```
Вход1:
3
1 1 1
1 1 1
1 1 1

Изход1:
Magic

Вход2:
3
1 2 3
3 2 1
2 3 1

Изход2:
Normal
```

## Задача 4 - Sum diagonal
При дадена матрица NxN (N не повече от 31) намерете сумата от числата по всички диагонали успоредни на главния диагонал.

```
Вход:
4
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

Изход:
4 11 21 34 30 23 13
```
**Обяснение на примера:**

Диагоналите са:  
4 = 4  
3 + 8 = 11  
2 + 7 + 12 = 21  
1 + 6 + 11 + 16 = 34  
5 + 10 + 15 = 30  
9 + 14 = 23  
13 = 13  

## Задача 5 - Симетрия

Да се състави функция, която установява дали матрица е симетрична относно главния си диагонал.

## Задача 6 - Max and Min
При дадена матрица NxN (N не повече от 31) намерете позициите,(като двойки ред и колона) които представляват най-голямата стойност за реда и **същевременно** най-малката стойност за колоната в която се намират.

```
Вход:
4
2 1 4 1
3 1 3 2
3 3 4 3
3 3 3 3

Изход:
1 2
3 2
```



**Обяснение на примера:**

На позиция 1 2 (започвайки броенето от 0) стои числото 3. Ако разгледаме ред 1, ще видим, че най-голямата стойност в него е точно 3. Ако се загледаме в колона 2, ще забележим, че най-малкото число е числото 3.
Същото може да се каже и за позиция 3 2.

---

## Задача 7 - Транспониране
Транспонирайте матрица *NxN* (*N* въведено от клавиатурата). Операцията транспониране представлява първия ред на дадена матрица да стане първа колона, втория ред на матрицата да стане втора колона и така всички редове да станат колони (a<sub>i,j</sub> -> a<sub>j,i</sub>)

```
Вход:
3
1 2 3
4 5 6
7 8 9

Изход:
1 4 7
2 5 8
3 6 9
```

## Задача 8 - Not on diagonal
Дадена е квадратна матрица А с размерност KxK. Да се състави програма, която намира произведението от елементите извън 
вторичния главен диагонал.

## Задача 9 - максимална подсума

Дадена е правоъгълна матрица **А** с размери **M<sub>x</sub>N**, съставена от цели числа. Дадени са числата **P** и **Q** (0<**P**<**N**, 0<**Q**<**M**). Намерете най-голямата сума, съставена от подматрица на **А** с размери **P<sub>x</sub>Q**.

**Ограничения**: 2 <= **N**, **M** <= 100

**Пример**:<br>
Вход:
```text
4 6
1 2 3 4 5 6
4 5 -1 6 7 8
-1 3 9 10 19 3
0 4 5 8 -13 2
2 3
```
Изход:
```text
53
```

Обяснение на примера (правилната подматрица е оцветена в червено):


$$
\begin{matrix}
1  & 2 & 3  & 4                   & 5                   & 6                  \\
4  & 5 & -1 & \textcolor{red}{6}  & \textcolor{red}{7}  & \textcolor{red}{8} \\
-1 & 3 & 9  & \textcolor{red}{10} & \textcolor{red}{19} & \textcolor{red}{3} \\
0  & 4 & 5  & 8                   & -13                 & 2
\end{matrix}
$$



## Задача 10 - Spiral

Дадена е квадратна матрица **A** с размери **n<sub>x</sub>n**. Изведете елементите й спираловидно, започвайки от горния ляв ъгъл.

**Ограничения**: 2 <= **n**, **m** <= 100

**Пример**:<br>
Вход:
```text
4
1 2 3 4
6 10 8 9
11 2 3 4
3 7 4 5
```
Изход:
```text
1 2 3 4 9 4 5 4 7 3 11 6 10 8 3 2
```


## Задача 11 - По-труден квадрат

 Изхождайки от определението за магически квадрат (сумата по редове, колони и двата диагонала да е равна), ще дефинираме магически палиндром като матрица, съдържаща палиндроми по редовете, колоните и двата си диагонала. По зададено число **N** (0<**N**<10) определете дали дадена матрица от символи (размер **N<sub>x</sub>N**) е магически палиндром.

**Пример**:<br>
Вход:
```text
3
a b a
b a b
a b a
```
Изход:
```text
Yes
```

---

Вход:
```text
4
a b b a
9 a a 9
k o k o
a b b a
```
Изход:
```text
No
```
