#include <bits/stdc++.h>
using namespace std;

void addedge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void print(std::vector<int> adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(int  x:adj[i])
		{
			cout<<x<<" ";
		}
		cout<<"\n";
	}
}
void bfs(std::vector<int> adj[],int n,bool visited[])
{
	queue<int>q;
	q.push(n);
	while(!q.empty())
	{
		int cur = q.front();
		cout<<cur<<" ";
		q.pop();
		for(auto i:adj[cur])
		{
			if(visited[i]==false)
			{
				visited[i]=1;
				q.push(i);
			}
		}
	}
}
void dfs(std::vector<int> adj[],bool visited[],int i)
{
	visited[i]=true;
	cout<<i<<" ";

	for(auto j:adj[i])
	{
		if(visited[j]==false)
		{
			dfs(adj,visited,j);
		}
	}
}
int main(int argc, char const *argv[])
{
	
	int v=5;
	std::vector<int> adj[v];
	addedge(adj,0,1);
	addedge(adj,0,2);
	addedge(adj,0,3);
	addedge(adj,1,2);
	addedge(adj,1,3);
	addedge(adj,2,4);

	bool visited[v+1];
	memset(visited,0,sizeof(visited));

	// for(int i=0;i<v;i++)
	// {
	// 	if(visited[i]==0)
	// 	{
	// 		visited[i]=1;
	// 		bfs(adj,i,visited);
	// 	}
	// }
	 dfs(adj,visited,0);

	// print(adj,v);



	return 0;
}