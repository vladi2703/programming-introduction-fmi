credits: Dimitrina Vasileva

int A[]; ERROR
int A[10]; 

******************************************************************
int A[] = {0}; // ---> size 1
int A[5] = {0}; // ---> size 5

int A[] = {1,2,3,4}; // ---> 4 елемента - масив с размерност 4 - int
int A[4] = {1,2,3,4}; 

int A[10] = {2}; // -> // 2 0 0 0 0 0 0 0 0 0

int A[5] = {1,4.3,7,8,9}; // --> ERROR
	Why do we have an error? Here we have an array of type integer and we initialize it with a number of type float.

int A[3] = {1,2};
	Explanation:
values: 	   1       2        0       
addresses:   dkjsdls jfsldjfs jdlkdsd

int A[3] = {1,2,3,4}; // --> ERROR
	Explanation + Why do we have an error?
values: 			1       2       3         4
addresses:		dkjsdls jfsldjfs jdlkdsd   ???????	--> ERROR

*********************************************************************
int A[4] = {1,2,4,5}; 

Индексацията на масиви започва от 0 до N(размерността на масива)
Първи елемент на масива // --> A[0] ---> 1
Останалите елементи на масива:
A[1] --> 2
A[3] --> 5
A[2] --> 4

*********************************************************************
реда - 3 колони 4 3x4
{1,2,3,4} //0
{4,5,6,5} //1
{7,8,9,8} //2
 0 1 2 3
 
int Matrix[3][4]; // int Matrix[ред][колона]

int Matrix[3][4] = {
					{1,2,3,4},
					{4,5,6,5} ,
					{7,8,9,8}
				   };
// int Matrix[броя масиви][броя елементи за всеки от 3-те масива]

for(int i = 0; i <= 2; i++ ) //row
	for(int j = 0; j <=3; j++) //col
		cout << Matrix[i][j] << " ";
		

B --> 3 масива с размерност 4 за всеки масив
int B[3][] = { //ERROR
				{1,2,3,4},
				{4,5,6,5},
				{7,8,9} -- // 3 4 ??? ERROR
              };
			  
!!! При многомерни масиви --> int B[може да се пропусне][задължително не се пропуска]

**********************************************************************************
Подаване на масиви във функции. Каква е разликата между подаване на променлива и масив по стойност във функции?

int fun1 (int a)
{
    // ...
    a = 5;
    // ...
    return a;
}

//...
int var = 10;
int var2 = fun1 (var);
// var = 10, var2 = 5;

int fun2 (int arr[7])
{
    //...
    arr[3] = 8;
    // ... 
    return 3;
}

int arr[7] = {1, 2, 3, 4, 5, 6, 7};
int var3 = fun2(arr);
// arr[3] = 8;
// arr = {1, 2, 3, 8, 5, 6, 7};

int fun3 (const int arr[])
{
    // arr[3] = 5; // compile time error
    int b = arr[3];
    return b;
}



int arr2[4][5];
int fun4(int arr[][5]) // int arr[4][5]
{
    arr[1][4] = 3;
    return arr[1][3];
}
fun4(arr2);
// arr[1][4] == 3

int arr3[1][5];
fun4(arr3); // here we have overflow
// !!! arr[1][4]
// arr[0][x]

// int arr[1][5] != int arr[5]

int arr4[1][5] = { 
    { 1, 2, 3, 4, 5}
};


int arr5[3][5] = { 
    { 1, 2, 3, 4, 5}
    // 0, 0, 0, 0, 0
    // 0, 0, 0, 0, 0
};
