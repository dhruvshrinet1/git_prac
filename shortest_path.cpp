#include <bits/stdc++.h>
using namespace std;



void shortest(std::vector<int> adj[],bool *visited,int * dest,int src)
{
	queue<int>q;
	q.push(src);
	dest[src]=0;
	visited[src]=1;

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();

		for(auto i:adj[cur])
		{
			if(visited[i]==0)
			{
				visited[i]=1;
			dest[i] = dest[cur]+1;
			q.push(i);
		}
		}
	}
}

void addedge(vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main(int argc, char const *argv[])
{
	int v=5;
	vector<int> adj[v];
	bool visited[v+1];
	memset(visited,0,sizeof(visited));

	addedge(adj,0,1);
	addedge(adj,1,2);
	// addedge(adj,0,1);
	addedge(adj,1,3);
	addedge(adj,2,3);
	addedge(adj,2,4);

	
	int dest[v];

	shortest(adj,visited,dest,1);
	for(auto i:dest)
	{
		cout<<i<<" ";
	}

	return 0;
}