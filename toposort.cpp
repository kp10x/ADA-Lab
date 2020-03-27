#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> mat;

void topo(int v, bool vis[], stack<int> &Stack)
{
	vis[v] = true;
	vector<int>::iterator i;
	for(i=mat[v].begin(); i!=mat[v].end(); i++)
		if(!vis[*i])
			topo(*i, vis, Stack);
	Stack.push(v);
}

int main()
{	
	int n, e; 
    cin>>n>>e; 

	bool *vis = new bool[n];
   	for (int i = 0; i < n; i++)
   		vis[i] = false;

    mat.assign(n, vector<int>());

    int a, b; 
    for (int i=0; i<e; i++) { 
        cin >>a>>b; 
        mat[a].push_back(b);
    } 
  
   	stack<int> Stack;
   	for(int i=0; i<n; i++)
   		if(vis[i]==false)
   			topo(i,vis,Stack);

   	while(Stack.empty()==false)
   	{
   		cout<<Stack.top()<<" ";
   		Stack.pop();
   	}
  
    return 0; 
}