#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 11;
int n, path[N];
bool col[N], diag[N][N];

bool is_in(int a, int b)
{
    return a >= 1 && a <= n && b >= 1 && b <= n;
}

void block(int a, int b)
{
    for (int i = 1; i <= n; i++)
        diag[i][b] = true;
    for (int i = a, j = b; is_in(i, j); i++, j++)
        diag[i][j] = true;
    for (int i = a, j = b; is_in(i, j); i--, j--)
        diag[i][j] = true;
    for (int i = a, j = b; is_in(i, j); i++, j--)
        diag[i][j] = true;
    for (int i = a, j = b; is_in(i, j); i--, j++)
        diag[i][j] = true;
}

void unlock(int a, int b)
{
    for (int i = 1; i <= n; i++)
        diag[i][b] = false;
    for (int i = a, j = b; is_in(i, j); i++, j++)
        if (!col[j]) diag[i][j] = false;
    for (int i = a, j = b; is_in(i, j); i--, j--)
        if (!col[j]) diag[i][j] = false;
    for (int i = a, j = b; is_in(i, j); i++, j--)
        if (!col[j]) diag[i][j] = false;
    for (int i = a, j = b; is_in(i, j); i--, j++)
        if (!col[j]) diag[i][j] = false;
}

bool check(int a, int b)
{
    return !diag[a][b];
}

bool dfs(int u)
{

    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            char str[n];
            memset(str, '.', sizeof str);
            str[path[i] - 1] = 'Q';
            for (int i = 0; i < n; i++)
                cout << str[i];
            cout << endl;
        }
        cout << endl;
        return true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check(u + 1, i))
        {
            col[i] = true;
            block(u + 1, i);
            path[u] = i;

            dfs(u + 1);

            col[i] = false;
            path[u] = 0;
            unlock(u + 1, i);
        }
    }

    return false;
}

int main()
{

    cin >> n;

    dfs(0);

    return 0;
}