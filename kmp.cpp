#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;
char p[N], s[M];
int ne[N];

int main()
{

	int n, m;
	// 数组下标从1开始
	cin >> n >> p + 1 >> m >> s + 1;

	// 求解next数组
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}

	// kmp
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j++;
		if (j == n)
		{
			printf("匹配成功！首地址为：%d\n", i - n);
			j = ne[j];
		}
	}

	return 0;
}