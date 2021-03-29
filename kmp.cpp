#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;
char p[N], s[M];
int ne[N];

int main()
{

	int n, m;
	// �����±��1��ʼ
	cin >> n >> p + 1 >> m >> s + 1;

	// ���next����
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
			printf("ƥ��ɹ����׵�ַΪ��%d\n", i - n);
			j = ne[j];
		}
	}

	return 0;
}