#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
unordered_map<char, int> pr{ {'+', 1}, {'*', 2} };

int main()
{
    
    cout << pr['+'] << endl;
    cout << pr.size() << endl;
    cout << pr['*'] << endl;
    pr.insert({ '/', 3 });
    cout << pr.size() << endl;
    cout << pr['/'] << endl;
    cout << pr['a'] << endl;

    return 0;
}