#include <bits/stdc++.h>
using namespace std;
#define v 5
void topsort(vector<int> adj[],int s,stack<int>&st,vector<bool> &visited)
{
	visited[s]=1;

	for(auto u:adj[s])
	{
		if(visited[u]==0)
		{
			topsort(adj,u,st,visited);
		}
	}
	st.push(s);

}

void dfs(std::vector<int> adj[],int s,vector<bool> &visited)
{
	visited[s]=1;
	cout<<s<<" ";
	for(auto i:adj[s])
	{
		if(visited[i]==0)
		{
			dfs(adj,i,visited);
		}
	}
}

void printssc(vector<int> adj[])
{

stack<int>s;

vector<bool> visited(v,0);

// memset(visited,0,sizeof(visited));

for(int i=0;i<v;i++)
{
	if(visited[i]==0)
	{
		topsort(adj,i,s,visited);
	}
}

for(int i=0;i<v;i++){
	for(auto j:adj[i])
	{
		adj[i].push_back(j);
	}
}

// memset(visited,0,sizeof(visited));
for (int i = 0; i < v; ++i)
{
	visited[i]=0;
}

	/* code */


while(s.empty()==0)
{
	int g = s.top();
	s.pop();

	if(visited[g]==0)
	{
		dfs(adj,g,visited);
		cout<<endl;
	}
}

}

void addEdge(std::vector<int> adj[],int u,int w)
{
	adj[u].push_back(w);
}


int main(int argc, char const *argv[])
{
	std::vector<int> adj[v];

	addEdge(adj,1, 0); 
	addEdge(adj,0, 2); 
	addEdge(adj,2, 1); 
	addEdge(adj,0, 3); 
	addEdge(adj,3, 4);

	printssc(adj);


	return 0;
}