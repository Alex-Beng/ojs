#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
 
char maze[50][50];                  //地图
int visited[50][50];                //访问标记
int m, n;
int cnt;                            //计数
int dx[8] = {0,1,1,1,0,-1,-1,-1};   //8联通
int dy[8] = {1,1,0,-1,-1,-1,0,1};
 
typedef struct Point
{
    int x;
    int y;
}point;
 
int main()
{
    queue<point> q;
    point s;
    while(cin >> m >> n >> s.x >> s.y && (s.x!=0||s.y!=0||n!=0||m!=0))
    {
        //初始化
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        while(!q.empty())
            q.pop();
 
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                cin >> maze[i][j];
        //第一列最后一列初始化为。
        for(int i = 0; i <= m+1; i++)
        {
            maze[i][0] = '.';
            maze[i][n+1] = '.';
        }
        //第一行最后一行初始化为。
        for(int j = 0; j <= n+1; j++)
        {
            maze[0][j] = '.';
            maze[m+1][j] = '.';
        }
 
        q.push(s);              //放入初始结点
        visited[s.x][s.y] = 1;  //标记已访问
        while(!q.empty())
        {
            s = q.front();
            q.pop();
 
            for(int i = 0; i < 8; i ++)
            {
                point temp;
                temp.x = s.x + dx[i];
                temp.y = s.y + dy[i];
 
                if(temp.x>=1 && temp.x<=m && temp.y>=1 && temp.y<=n &&          //未越界
                   maze[temp.x][temp.y]=='X' && !visited[temp.x][temp.y])       //可达且未访问
                {
                    q.push(temp);
                    visited[temp.x][temp.y] = 1;
                }
            }
        }
 
        //计算边长
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(visited[i][j])
                {
                    if(maze[i-1][j] == '.')
                        cnt ++;
                    if(maze[i][j-1] == '.')
                       cnt ++;
                    if(maze[i+1][j] == '.')
                        cnt ++;
                    if(maze[i][j+1] == '.')
                        cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
