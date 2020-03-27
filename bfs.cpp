#include <bits/stdc++.h> 
using namespace std;

vector<int> v;
vector<vector<int>> mat;

void bfs(int u)
{
	queue<int> q;

	q.push(u);
	v[u] = 1;  //mark it visited

	while(!q.empty())
	{
		int f = q.front();
		q.pop();

		cout<<f+1<<" ";

		for(auto i=mat[f].begin(); i!=mat[f].end(); i++)
		{
			if(v[*i]==0) {
				q.push(*i);
				v[*i] = 1;
			}
		}
	}
}

int main()
{	
	int n, e; 
    cin>>n>>e; 

	v.assign(n, 0);
    mat.assign(n, vector<int>());

    int a, b; 
    for (int i=0; i<e; i++) { 
        cin >>a>>b; 
        mat[a-1].push_back(b-1);
    } 
  
    for (int i=0; i<n; i++) { 
        if (v[i]==0) bfs(i); 
    } 
  
    return 0; 
}