#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
int q[N], hh = 0, tt = 0;

void push(int x)
{
	q[tt++] = x;
	if (tt == N) tt = 0;
}

void pop()
{
	hh ++;
	if (hh == N) hh = 0;
}

bool empty()
{
	return hh == tt;
}

int front()
{
	return q[hh];
}

int back()
{
	return q[tt];
}

int main()
{
	for (int i = 1; i <= 5; i++)
		push(i);
	pop();

	for (int i = hh; i <= tt; i++)
		cout << q[i] << ' ';
	cout << endl;

	return 0;
}

