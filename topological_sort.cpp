#include <bits/stdc++.h>
using namespace std;


void topo_sort(std::vector<int> adj[],bool visited[],int s)
{
	queue<int>q;
	// q.push(s);
	vector<int>deg(5,0);
	for(int i=0;i<5;i++)
	{
		for(auto o:adj[i])
		{

			deg[o]++;
		}
	}
	for(int i=0;i<5;i++)
	{
		if(deg[i]==0)
		{
			q.push(i);
			// cout<<i;
		}
	}


	while(!q.empty())
	{
		int cut= q.front();
		cout<<cut<<" ";
		q.pop();

		for(auto i:adj[cut])
		{
			// deg[i]--;
			if(--deg[i]==0)
			{
				q.push(i);
			}
		}
	}

}

void topo_sort_dfs(int s,bool visited[],vector<int> adj[],stack<int>st)
{
	visited[s]=1;

	for(auto i:adj[s])
	{
		if(visited[i]==0)
		{
			topo_sort_dfs(i,visited,adj,st);
		}
	}

	st.push(s);
	return;
}

// }
void addEdge(vector<int>adj[],int u ,int v){
	adj[u].push_back(v);
	// adj[v].push_back(u);

}

int main(int argc, char const *argv[])
{
	
		int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3); 
    bool visited[V+1];
    memset(visited,0,sizeof(V));
	// for(auto i:adj[0])
	// {
	// 	cout<<i;
	// }
	 topo_sort(adj,visited,0);
	 stack<int>st;
	 // bool visited[V+1];
	 topo_sort_dfs(0,visited,adj,st);

	 while(!st.empty())
	 {
	 	cout<<st.top();
	 	st.pop();
	 }

	return 0;
}