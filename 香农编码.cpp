#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	cout << "输入信源:";
	char p[100], temp;
	int size, o[100];
	cin >> p;
	for (size = 0; p[size] != NULL; size++)
	{
		cout << p[size];
	}
	cout << endl;
	cout << size << endl;
	int a = 0, b = 0, k = 0;
	double pro;
	for (int i = 0; i < size; i++)
	{
		a = 1;
		if (p[i] == 0)continue;
		for (int j = i + 1; j < size; j++)
		{
			if (p[i] == p[j])
			{
				a++;
				p[j] = 0;
			}
		}
		o[k] = a;
		k++;
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - i - 1; j++)
		{
			if (o[j] < o[j + 1])
			{
				temp = o[j];
				o[j] = o[j + 1];
				o[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << o[i];
	}
	cout << endl;

	int machang, sum = 0, sum1 = 0;
	double pro2, temp1 = 0;
	for (int i = 0; i < k; i++)
	{
		pro2 = static_cast<double>(o[i]) / size;
		machang = o[i] * ceil(log(1 / pro2) / log(2));
		temp1 = pro2;
		for (int j = 0; j < machang; j++)
		{
			temp1 = temp1 * 2;
			if (temp1 < 1)
			{
				cout << "0";
			}
			else
			{
				cout << "1";
				temp1 = temp1 - 1;
			}
		}
		sum = sum + machang;/*总码长*/
		sum1 = sum1 + pro2;/*累加概率*/
	}
	cout << "码长为" << sum;
	system("pause");
}