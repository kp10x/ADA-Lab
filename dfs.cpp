#include<iostream>
using namespace std;

int g[5][5]= {
	{0, 1, 1, 0, 0},
	{1, 0, 1, 0, 0},
	{1, 1, 0, 1, 1},
	{0, 1, 1, 0, 1},
	{0, 0, 1, 1, 0}
};

void dfs(int u, int visited[])
{
	visited[u] = 1;

	for(int v=0; v<5; v++)
	{
		if(g[u][v]){
			if(!visited[v])
				dfs(v, visited);
		}
	}
}

int isConnected()
{
	int *vis = new int[5];

	for(int u=0; u<5; u++)
	{
		for(int i=0;i<5;i++)
				vis[i]=0;
		dfs(u, vis);
		for(int i=0;i<5;i++)
			if(!vis[i])
				return 0;
	}
	return 1;
}

int main()
{
	if(isConnected())
		cout<<"Connected";
	else
		cout<<"Not Connected";
}