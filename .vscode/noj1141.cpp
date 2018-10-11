#include <iostream>
#include <stdio.h>
using namespace std;
 
int sx,sy,fx,fy;
int row,col;
int maze[25][25];
int visited[25][25];
int flag = 0;
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
 
void dfs(int x,int y)
{
	if(x == fx&&y == fy)
	{
		flag = 1;
		return;
	}
	visited[x][y] = 1;
	for(int i = 0;i < 4;i++)
	{
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if(nx >= 0 && nx < row && ny >= 0 && ny < col && maze[nx][ny] == 0 && visited[nx][ny] == 0)
			dfs(nx,ny);
	}
}
 
int main()
{
	cin >> row >> col;
	cin >> sx >> sy;
	cin >> fx >> fy;
 
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			cin >> maze[i][j];
		}
	}
	dfs(sx,sy);
	if(flag == 1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
