#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "locale.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n, m, x, y, a[10][10], b[10][10];
	setlocale(LC_ALL, "rus");
	cout << "Введите количество вершин: ";
	cin >> n;
	cout << "Введите количество рёбер: ";
	cin >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = 0;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			b[i][j] = 0;
		}
	//cout << "Введите рёбра: " << endl;

	/*for(int j=1;j<=m;j++)
	{
	cin>>x >>y;
	a[x][y]++;
	} */

	int count = 1;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		if (x != y)
		{
			b[x][i] = 1;
			b[y][i] = -1;
		}
		else
			b[x][i] = 1;
		a[x][y]++;
		cout << "Введено " << count << " ребро" << endl;
		count++;
	}
	cout << endl;


	cout << "Матрица смежности: " << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "Матрица инцидентности: " << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << b[i][j] << " \t";
		}
		cout << endl;
	}
	cout << endl;


	system("pause");
	return 0;
}
