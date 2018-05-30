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
	for (int k = 0; k < size; k++)/*完全统计编码过程*/
	{
         for (j = 0;a[j] <= p[k]; j++)
	     {
		    double pro = 0;
		    for (i = 0; i < size; i++)
		    {
			    if (p[i] == a[j])pro++;
	    	}
		    if (pro == 0)continue;/*如果该字母没有在信源中出现过，则跳出本次循环*/
			if (a[j] < p[k])low = low + temp * (pro / size);
			else if (a[j] == p[k])high = low + temp * (pro / size);
	      }
		 temp = high - low;
	}
	return 0;
}

void Xnong(char p[])
{
	char temp;
	int size, o[100];
	for (size = 0; p[size] != NULL; size++);
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
}

int main()
{
	cout << "输入信源:" << endl;
	char p[100];
	cin >> p;

	cout << "-----------完全统计算术编码----------";

	int size;
	for (size = 0; p[size] != NULL; size++);
	cout << endl;
	cout << size;

	double low = 0, high = 1;
	width(high, low,size,p);
	cout << "下界值为：" << low << "上界值为：" << high << endl;

	int machang = CLength(high,low);
	cout << "码长为" << machang << endl;

	/*编码过程*/
	cout << "编码结果为";
	double temp1 = high * 0.9999999999999999999;
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

	cout << endl;
	cout << "----------香农编码----------";
	Xnong(p);

	system("pause");
}