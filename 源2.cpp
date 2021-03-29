#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N], cnt[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i, cnt[i] = 1;
    while (m--)
    {
        string op;
        int a, b;
        cin >> op >> a;
        if (op == "Q2")
        {
            cout << cnt[find(a)] << endl;
            continue;
        }
        cin >> b;
        if (op == "C")
        {
            a = find(a), b = find(b);
            if (a == b) continue;
            p[a] = b, cnt[b] += cnt[a];
        }
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}