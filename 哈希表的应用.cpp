#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int a[] = { 4, 6, 2, 3 };
set<int> s(a, a + 4);
set<int>::iterator it;

void show()
{
	for (it = s.begin(); it != s.end(); it++) 
		cout << *it << " ";
	cout << endl;
}

int main()
{
	
	show();
	cout << *s.begin() << endl;
	if ((it = s.find(2)) != s.end())	// ²éÑ¯	
		cout << *it << endl;
	if (s.count(2)) puts("success!");
	if (s.count(1)) puts("1success!");
	else puts("1failure!");
	cout << s.size() << endl;
	cout << s.empty() << endl;
	s.erase(s.begin());
	show();
	s.insert(5);	// ²åÈë
	s.erase(3);	// É¾³ý
	show();
	return 0;
}