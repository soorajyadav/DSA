// shortest path for a Binary Graph
#include<bits/stdc++.h>
using namespace std;

#define V 9

vector<pair<int,int>> g[V];

// vector<int> level(V,INT_MAX); //this can also be used as level array

void zeroOneBFS(int src , int n)
{
	int level[V];
	for (int i=0; i<n; i++)
		level[i] = INT_MAX;

	deque<int> Q;
	level[src] = 0;
	Q.push_back(src);

	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop_front();

		for (auto i: g[v])
		{
            int child=i.first;
            int wt=i.second;
			
			if (level[v] + wt < level[child])
			{
				level[child]=level[v]+wt;

				if (wt==0)
					Q.push_front(child);
				else
					Q.push_back(child);
			}
		}
	}

	for (int i=0; i<V; i++)
		cout << level[i] << " ";
}

void addEdge(int u, int v, int wt)
{
g[u].push_back({v, wt});
g[v].push_back({u, wt});
}

int main()
{
	addEdge(0, 1, 0);
	addEdge(0, 7, 1);
	addEdge(1, 7, 1);
	addEdge(1, 2, 1);
	addEdge(2, 3, 0);
	addEdge(2, 5, 0);
	addEdge(2, 8, 1);
	addEdge(3, 4, 1);
	addEdge(3, 5, 1);
	addEdge(4, 5, 1);
	addEdge(5, 6, 1);
	addEdge(6, 7, 1);
	addEdge(7, 8, 1);
    int src=0;
    
	zeroOneBFS(src,V);

	return 0;
}
