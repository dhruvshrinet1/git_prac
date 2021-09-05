#include <bits/stdc++.h>
using namespace std;
#define V 6

int selectmin(int   dst[],bool bmst[])
{
	int minimum =INT_MAX;
	int vertex;
	// int V=6;

	for (int i = 0; i < V; ++i)
	{
		/* code */
		if(bmst[i]==false &&  dst[i] < minimum)
			{
				vertex=i;
				minimum=dst[i];
			}
	}
	return vertex;
}

void findgraph(int graph[V][V])
{
	int dst[V];
	dst[0]=0;
	for (int i = 1; i < V; ++i)
	{
		/* code */
		dst[i]=INT_MAX;
	}
	int parent[V];
	memset(parent,0,sizeof(parent));
	parent[0]=-1;

	bool bmst[V];
	memset(bmst,0,sizeof(bmst));
	bmst[0]=0;

	for(int i=0;i<V-1;i++)
	{
		int u = selectmin(dst,bmst);
		bmst[u]=1;

		for (int j = 0; j < V; ++j)
		{
			/* code */
			if(graph[u][j]!=0 && bmst[j]==0 && graph[u][j]<dst[j])
			{
				dst[j]=graph[u][j];
				parent[j]=u;
			}

		}
	}
	for(int i=0;i<V;i++)
	{
		cout<<"U-> V => "<<parent[i]<<" -> "<<i<<" wt "<<graph[parent[i]][i]<<"\n";
	}
}

int main(int argc, char const *argv[])
{
	 
	int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };



	findgraph(graph);
	return 0;
}