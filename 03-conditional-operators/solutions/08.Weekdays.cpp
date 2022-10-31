#include <iostream>

int main()
{
    int day; // input 1-7
		std::cin >> day;

// Грешно решение! Дори да намери деня (например при day = 2), пак ще мине през всички останали проверки
    if (day == 1)
		std::cout << "Monday" << std::endl;
	if (day == 2)
		std::cout << "Tuesday" << std::endl;
	if (day == 3)
		std::cout << "Wednesday" << std::endl;
	if (day == 4)
		std::cout << "Thursday" << std::endl;
	if (day == 5)
		std::cout << "Friday" << std::endl;
	if (day == 6)
		std::cout << "Saturday" << std::endl;
	if (day == 7)
		std::cout << "Sunday" << std::endl;

// По-добро решение.
// В случай, че имаме невалиден вход ще изведе подходящо съобщение.
	if (day == 1)
		std::cout << "Monday" << std::endl;
	else if (day == 2)
		std::cout << "Tuesday" << std::endl;
	else if (day == 3)
		std::cout << "Wednesday" << std::endl;
	else if (day == 4)
		std::cout << "Thursday" << std::endl;
	else if (day == 5)
		std::cout << "Friday" << std::endl;
	else if (day == 6)
		std::cout << "Saturday" << std::endl;
	else if (day == 7)
		std::cout << "Sunday" << std::endl;
	else
		std::cout << "Invalid input" << std::endl;

// Вариант за решение със switch
    switch (day)
	{
        case 1: std::cout << "Monday" << std::endl; break;
        case 2: std::cout << "Tuesday" << std::endl; break;
        case 3: std::cout << "Wednesday" << std::endl; break;
        case 4: std::cout << "Thursday" << std::endl; break;
        case 5: std::cout << "Friday" << std::endl; break;
        case 6: std::cout << "Saturday" << std::endl; break;
        case 7: std::cout << "Sunday" << std::endl; break;
        default: std::cout << "Invalid input" << std::endl; 
	}


    return 0;
}