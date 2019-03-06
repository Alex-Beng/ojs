
#include <iostream>
#include <queue>
using namespace std;

int m, n, step[10000000];
queue<int> q;

int bfs();
int moveto(int key, int dir);

int main()
{
    cin >> m >> n;

    cout << bfs() << endl;
}

int bfs()
{
    step[m] = 0;
    q.push(m);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int v = moveto(u, i);
            if (v == n)
                return (step[u] + 1);

            if (v < n && step[v] == 0) // step[v] == 0!!!!!
            {
                step[v] = step[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int moveto(int key, int dir)
{
    switch (dir)
    {
    case 0:
        key++;
        break;
    case 1:
        key = key * 2;
        break;
    case 2:
        key = key * key;
        break;
    }

    return key;
}
