#include <iostream>
#include <math.h>
using namespace std;
char a[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

int CLength(double high, double low)
{
	int i;
	i = ceil(log(1 / (high - low)) / log(2));
	return i;
}

int width(double &high, double &low, int size, char *p)
{
	int i = 0, j = 0;
	double temp = high - low;
	for (j = 0; a[j] <= p[size]; j++)
	{
		if (a[j] == 0)break;
		if (a[j] < a[6] && a[j]<p[size])low = low + temp * 0.1;
		if (a[j] >= a[6] && a[j]<p[size])low = low + temp * 0.02;
		if (a[j] < a[6] && a[j] == p[size])high = low + temp * 0.1;
		else if (a[j] >= a[6] && a[j] == p[size])high = low + temp * 0.02;
	}
	return 0;
}
int yima(double left, int size)
{
	double  high = 0;
	char p[100];
	int i = 0, j = 0, x = 0;
	double temp = 1;
	for (int k = 0; k < size; k++)
	{
		for (j = 0; a[j] <= a[25]; j++)
		{
			if (a[j]<a[6])high = high + temp * 0.1;
			else if (a[j] >= a[6])high = high + temp * 0.02;
			if (left <= high)
			{
				p[x] = a[j];
				if (a[j]<a[6])temp = temp * 0.1;
				else if (a[j] >= a[6])temp = temp * 0.02;
				high = high - temp;
				x++;
				break;
			}
		}
	}
	for (int k = 0; k < size; k++)
	{
		cout << p[k];
	}
	return 0;
}

int main()
{
	cout << "输入信源:";
	char p[100], a[10];
	double b[100];
	int size, x, c = 0, y = 0,d[100];
	cin >> p;
	for (size = 0; p[size] != NULL; size++);
	while (p[c] != NULL)
	{
		for (int j = 0; j < 10; j++)
		{
			if (p[c] == NULL)break;
			a[j] = p[c];
			c++;
			cout << a[j];
		}
		double low = 0, high = 1;
		for (int i = 0; i < c - y * 10; i++)
		{
			x = width(high, low, i, a);
		}
		cout << "下界值为：" << low << "上界值为：" << high << endl;

		int machang = CLength(high, low);
		cout << "码长为" << machang << endl;

		/*编码过程*/
		cout << "编码结果为";
		double temp1 = high * 0.999999999999999999999999;
		b[y] = temp1;
		for (int j = 0; j < machang; j++)
		{
			temp1 = temp1 * 2;
			if (temp1 < 1)cout << "0";
			else
			{
				cout << "1";
				temp1 = temp1 - 1;
			}
		}
		d[y] = c - y * 8;
		y++;
		cout << endl;
	}

	/*译码过程*/
	cout << "译码结果为：";
	double left1;
	for (int i = 0; i < y; i++)
	{
		left1 = b[i];
		size = d[i];
		yima(left1, size);
	}
	system("pause");
}