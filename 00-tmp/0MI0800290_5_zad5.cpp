#include <iostream>
#include <windows.h>
#include <thread>

struct Console
{
public:
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	SHORT width;

	Console()
	{
		this->hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		this->GetWindowWidth();
		this->ShowConsoleCursor(false);
	}

	SHORT GetWindowWidth()
	{
		if (!GetConsoleScreenBufferInfo(hStdout, &this->csbiInfo))
		{
			printf("GetConsoleScreenBufferInfo (%d)\n", GetLastError());
			return 0;
		}
		return this->width = csbiInfo.dwSize.X;
	}

	Console& GoToXY(int x, int y)
	{
		/* 
			We only use this function because we want to draw multiple 
			vehicles that can go around from back to front when needed.
			If we ignore this function's usage from the drawing function,
			it is easy to see that the remaining code uses loops and 
			no multidimensional arrays.
		*/
		x %= this->width;
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(hStdout, coord);
		return *this;
	}

	template <typename T>
	Console& Print(T t)
	{
		std::cout << t << std::endl;
		return *this;
	}

	template<typename T, typename... Args>
	Console& Print(T t, Args... args) // recursive variadic function
	{
		std::cout << t;
		this->Print(args...);
		return *this;
	}

private:
	void ShowConsoleCursor(bool showFlag)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO cursorInfo;

		GetConsoleCursorInfo(out, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(out, &cursorInfo);
	}
};

struct TruckParams
{
	int xLoc = 0;
	int dx = 1;
	int backWindowsCount = 4;
	int topOffset = 0;
	int windowsWidth = 5;
	int mainHeight = 3;
	int frontWindowTopWidth = 2;
	char horizontalLine = '_';
	char verticalLine = '|';
	char bottomLine = '-';

	void Move(int width)
	{
		this->xLoc = (this->xLoc + this->dx) % width;
	}
};

void DrawTruck(
	Console& console,
	const TruckParams& tp)
{ //n := number of back windows
	if (tp.backWindowsCount < 4)
		throw "Back windows count should be > 3.";
	if (tp.windowsWidth < 3)
		throw "Main back windows' width should be > 2.";

	int windowsHeight = (tp.mainHeight + 1) / 2;
	
	int i, j, k, row = tp.topOffset, col, upperBound, endOfWindow, doorPart;
	std::string hor = " " + std::string(1, tp.horizontalLine);
	std::string ver = std::string(1, tp.verticalLine) + " ";

	/*  Draw Car's Top Line  */
	//console.GoToXY(time, row).Print(" ");
	upperBound = (tp.windowsWidth - 2) + 1 +
		        (tp.backWindowsCount - 2) * (tp.windowsWidth + 1) +
				(tp.windowsWidth - 1) + 1 +
		        (tp.windowsWidth / 3) + 1 +
				tp.frontWindowTopWidth;
	col = tp.xLoc + 1;
	for(i = 0; i < upperBound; i++)
		console.GoToXY(col++, row).Print(tp.horizontalLine);
	row++;
	
	/*  Draw Car's Main Part  */
	for (i = 1; i <= tp.mainHeight; i++, row++)
	{
		endOfWindow = int(i == windowsHeight);
		doorPart = int(i > windowsHeight);

		col = tp.xLoc;
		console.GoToXY(col++, row).Print(tp.verticalLine);
		for(j = 0; j < tp.windowsWidth - 2; j++) console.GoToXY(col++, row).Print(hor[endOfWindow]);
		console.GoToXY(col++, row).Print(ver[doorPart]);

		for (k = 0; k < tp.backWindowsCount - 2; k++)
		{
			for(j = 0; j < tp.windowsWidth; j++) console.GoToXY(col++, row).Print(hor[endOfWindow]);
			console.GoToXY(col++, row).Print(ver[doorPart]);
		}

		for(j = 0; j < tp.windowsWidth - 1; j++) console.GoToXY(col++, row).Print(hor[endOfWindow]);
		console.GoToXY(col++, row).Print(tp.verticalLine);

		for(j = 0; j < tp.windowsWidth / 3; j++) console.GoToXY(col++, row).Print(hor[endOfWindow]);
		console.GoToXY(col++, row).Print(tp.verticalLine);

		for(j = 0; j < tp.frontWindowTopWidth + i - 1; j++) console.GoToXY(col++, row).Print(hor[endOfWindow]);
		console.GoToXY(col++, row).Print("\\");
	}

	/*  Draw Car's Bottom Line  */
	col = tp.xLoc;
	console.GoToXY(col++, row).Print('`');
	for(i = 0; i < 2; i++) console.GoToXY(col++, row).Print(tp.bottomLine);
	for (i = 0; i < 2; i++)
	{
		console.GoToXY(col++, row).Print('(');
		console.GoToXY(col++, row).Print('o');
		console.GoToXY(col++, row).Print(')');
	}

	upperBound = 1 + upperBound + tp.mainHeight - 9 - 5 - 1;
	for(int i = 0; i < upperBound; i++) console.GoToXY(col++, row).Print(tp.bottomLine);
	console.GoToXY(col++, row).Print('(');
	console.GoToXY(col++, row).Print('o');
	console.GoToXY(col++, row).Print(')');
	for (i = 0; i < 2; i++) console.GoToXY(col++, row).Print(tp.bottomLine);
	console.GoToXY(col, row).Print('\'');
}

void loop()
{
	using namespace std::chrono_literals;
	Console console = Console();
	TruckParams trucks[] = { TruckParams(), TruckParams(), TruckParams() };
	trucks[0].dx = 3;
	trucks[1].topOffset = 8;
	trucks[1].backWindowsCount = 8;
	trucks[1].dx = 2;
	trucks[2].topOffset = 16;
	trucks[2].backWindowsCount = 5;
	trucks[2].windowsWidth = 8;
	trucks[2].mainHeight = 9;
	trucks[2].dx = 1;
	int trucksLength = sizeof(trucks) / sizeof(trucks[0]);
	while (true)
	{
		system("CLS");
		console.GetWindowWidth();
		for (int i = 0; i < trucksLength; i++)
		{
			DrawTruck(console, trucks[i]);
			trucks[i].Move(console.width);
		}
		std::this_thread::sleep_for(20ms);
	}
	
}

int main()
{
	loop();
	return 0;
}