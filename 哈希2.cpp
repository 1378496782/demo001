#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 3;

struct Info
{
	string name;
	int score;

	bool operator < (const Info& a) const
	{
		return score < a.score;
	}
};
Info info[N] = { {"zfw", 10} , {"mcx", 10} , {"zs", 2} };
void show()
{
	for (Info i : info)
		cout << i.name << ' ' << i.score << endl;
}

int main()
{
	show();
	sort(info, info + N);
	show();
	return 0;
}

