// #include <queue>
// #include <iostream>
// using namespace std;
// inline int plus1(int a) {
//     return a+1;
// }
// inline int time2(int a) {
//     return 2*a;
// }
// inline int sqrt(int a) {
//     return a*a;
// }
// int step[100000];
// int main(int argc, char const *argv[])
// {
//     std::queue<int> qrq;
//     int begin,end;
//     int ans = 0;
//     cin>>begin>>end;
//     step[begin] = 0;
//     qrq.push(begin);
//     while (!qrq.empty()) {
//         int tmp = qrq.front();
//         qrq.pop();
//         if (tmp>end) {
//             continue;
//         }

//         if (plus1(tmp) == end) {
//             step[plus1(tmp)] = step[tmp] + 1;
//             // cout<<step[end]<<endl;
//             break;
//         }
//         else if (step[plus1(tmp)] == 0 && plus1(tmp) <end){
//             step[plus1(tmp)] = step[tmp] + 1;
//             qrq.push(plus1(tmp));
//         }

//         if (time2(tmp) == end) {
//             step[time2(tmp)] = step[tmp] + 1;
//             // cout<<step[end]<<endl;
//             break;
//         }
//         else if (step[time2(tmp)] == 0 && time2(tmp) <end) {
//             step[time2(tmp)] = step[tmp] + 1;
//             qrq.push(time2(tmp));
//         }

//         if (sqrt(tmp) == end) {
//             step[sqrt(tmp)] = step[tmp] + 1;
//             // cout<<step[end]<<endl;
//             break;
//         }
//         else if (step[sqrt(tmp)] == 0 && sqrt(tmp) <end) {
//             step[sqrt(tmp)] = step[tmp] + 1;
//             qrq.push(sqrt(tmp));
//         }
//     }
//     cout<<step[end]<<endl;
//     return 0;
// }

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
