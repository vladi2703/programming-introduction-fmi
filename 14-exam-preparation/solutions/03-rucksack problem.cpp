#include <iostream>
const int MAX_COUNT = 20;

int weights[MAX_COUNT], price[MAX_COUNT], n, w;

bool taken[MAX_COUNT] = {}; // булевите масиви ни трябват само ако искаме да знаем кои точно
bool best_solution[MAX_COUNT] = {}; // са елементите, които образуват най-доброто решение

int max_value = 0; // стойността на най-доброто решение намерено досега

// функцията проверява решението при текуща обща стойност cur_value, текущо тегло cur_weight на предметите
// и проверява какви други решения има при добавяне на още предмети, намиращи се на и след позиция pos
void findMaxValue(int cur_value, int cur_weight, int pos)
{
	if (cur_weight > w)
		return;

	if (cur_value > max_value)
	{
		max_value = cur_value;
		for (int i = 0; i < n; i++)
			best_solution[i] = taken[i]; // записваме текущия набор от взети предмети
	}

	if (pos == n)
		return;

	// разглеждаме случаите, в които не взимаме елемента на позиция pos
	findMaxValue(cur_value, cur_weight, pos + 1);


	// разглеждаме случаите, в които взимаме елемента на позиция pos
	taken[pos] = true;
	findMaxValue(cur_value + price[pos], cur_weight + weights[pos], pos + 1);
	taken[pos] = false;
}

int main()
{
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> price[i] >> weights[i];

	std::cin >> w;

	max_value = 0;
	findMaxValue(0, 0, 0);

	std::cout << "Value of best solution: " << max_value << std::endl;
	std::cout << "Elements in best solution: ";
	for (int i = 0; i < n; i++)
		if (best_solution[i])
			std::cout << i+1 <<", ";

	std::cout << std::endl;
}
/*
4
30 12
10 11
10 1
30 1
13
*/