#include <iostream>
#include <locale.h>

using namespace std;
int main()
{
	string dom;
	setlocale(LC_ALL, "RUS");
	cout << "Введите домен\n";
	cin >> dom;
		bool flag = true;
		for (int i = 0; i < dom.length(); i++) 
			if (dom[i] < 64 || dom[i] > 90 && dom[i] < 97 || dom[i] > 122)
				flag = false;
		cout << flag;
}