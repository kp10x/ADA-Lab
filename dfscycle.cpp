#include <iostream>
#include<set>
using namespace std;

int g[5][5]= {
	{0, 1, 1, 0, 0},
	{1, 0, 1, 0, 0},
	{1, 1, 0, 1, 1},
	{0, 1, 1, 0, 1},
	{0, 0, 1, 1, 0}
};

int dfs(int vertex, set<int> &visited, int parent, int n)
{
	visited.insert(vertex);
	for(int v=0; v<n; v++)
	{
		if(g[vertex][v]==1)
		{
			if(v!=parent)
			{
				if(visited.find(v)!=visited.end())
					return 1;
				if(dfs(v, visited, vertex, n))
					return 1;
			}
		}
	}
	return 0;
}

int hasCycle(int n)
{
	set<int> visited;
	for(int v=0; v<n; v++)
	{
		if(visited.find(v)==visited.end())
			if(dfs(v, visited, -1, n))
				return 1;
	}
	return 0;
}

int main()
{	
	int n=5;
	if(hasCycle(n))
		cout<<"Cycle";
	else
		cout<<"No Cycle";
}