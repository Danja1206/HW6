#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a;
    while (true)
    {
		cin >> a;

		if (cin.good() && cin.peek() == '\n')
		{
			break;
		}

		cin.clear();
		cout << "Ошибка ввода. Попробуйте ещё раз: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    cout << a << endl;
	return 0;
}
