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
	for (j = 0; a[j]<=p[size]; j++)
	{
		double pro = 1;
		for (i = 0; i <size; i++)
		{
			if (p[i] == a[j])pro++;
		}
		if (a[j] == 0)break;
		if (a[j]<p[size])low = low + temp * (pro / (26 + size));
		else if (a[j] == p[size])high = low + temp * (pro / (26 + size));
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
			double pro = 1;
			for (i = 0; i <x; i++)
			{
				if (p[i] == a[j])pro++;
			}
			high = high + temp * (pro / (26 + x));
			if (left < high)
			{
				p[x] = a[j];
				temp = temp * pro / (26 + x);
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
	char p[100];
	int size;
	cin >> p;
	for (size=0; p[size]!=NULL; size++)
	{
		cout << p[size];
	}
	cout << endl;
	cout << size;
	int x;
	double low = 0, high = 1;
	for (int i = 0; i < size; i++)
	{
		x = width(high, low, i, p);
	}
	cout << "下界值为：" << low << "上界值为：" << high << endl;

	int machang = CLength(high, low);
	cout << "码长为" << machang << endl;

	/*编码过程*/
	cout << "编码结果为";
	double temp1 = high * 0.9999999999999999999;
	double left=0;

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
			left = left+pow(2, -(j+1));
		}
		
	}
    
	cout << endl;
	cout << left;

	/*译码过程*/
	cout << "译码结果为";
	yima(left, size);

	system("pause");
}