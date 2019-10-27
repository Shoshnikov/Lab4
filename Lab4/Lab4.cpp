#include <iostream>
#include <locale.h>

using namespace std;

bool addressCheck(string adr, int& zonedom);

int main()
{
	string dom;
	setlocale(LC_ALL, "RUS");
	cout << "Введите адрес\n";
	cin >> dom;
	int zonedom = 0;
		bool flag = true;
		if (addressCheck(dom, zonedom))
		{
			for (int i = dom.length() - 1; i > dom.length() - zonedom;i--)
				if (dom[i] < 64 || dom[i] > 90 && dom[i] < 97 || dom[i] > 122)
					flag = false;
			cout << flag;
		}
		else
			cout << "Не адрес\n";
}

bool addressCheck(string adr, int &zonedome)
{
	int countBeforeSobaka = 0;
	int countAfterSobaka = 0;
	bool sobaka = false;
	for (int i = 0; i < adr.length(); i++)
	{
		if ((int)adr[i] != 64 && sobaka == false)
			countBeforeSobaka++;
		else if (sobaka == true)
			countAfterSobaka++;

		if ((int)adr[i] == 64)
			sobaka = true;
	}
	if (sobaka && countAfterSobaka && countBeforeSobaka)
		for (int i = adr.length() - 1; (int)adr[i] != 46; i--)
			zonedome++;

	if (sobaka && countAfterSobaka && countBeforeSobaka)
		return true;
	return false;
}