// Run Time: 0.000
#include <iostream>
#include <cstring>
using namespace std;

int graph[101][101];
bool visited[101];
int num_of_nodes;
int visit_order[101];
int c = 0;

void DFS(int i)
{
	for (int j = 1; j < num_of_nodes; j++)
		if (graph[i][j] && !visited[j])
		{
			visited[j] = true;
			DFS(j);
			visit_order[c++] = j;
		}
}

void traversal()
{
	for (int i = 1; i < num_of_nodes; i++)
		visited[i] = false;

	for (int i = 1; i < num_of_nodes; i++)
		if (!visited[i])
		{
			visited[i] = true;
			DFS(i);
			visit_order[c++] = i;
		}
}

int main()
{
	int n, m, i, j;

	while (true)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));
		memset(visit_order, 0, sizeof(visit_order));
		c = 0;

		num_of_nodes = n + 1;

		for (int x = 0; x < m; x++)
		{
			cin >> i >> j;
			graph[i][j] = 1;
		}

		traversal();

		for (int x = c - 1; x >= 0; x--)
		{
			cout << visit_order[x];
			if (x != 0)
				cout << " ";
			else
				cout << endl;
		}
	}

	return 0;
}