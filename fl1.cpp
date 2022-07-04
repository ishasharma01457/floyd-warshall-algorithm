#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
void display(int distance[][V]);
void floyd(int graph[][V])
{
    	int distance[V][V], i, j, k;
       for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			distance[i][j] = graph[i][j];
        for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (distance[i][j] > (distance[i][k] + distance[k][j])
					&& (distance[k][j] != INF
						&& distance[i][k] != INF))
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
	display(distance);
}
void display(int distance[][V])
{
	cout << "shortest distanceance\n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (distance[i][j] == INF)
				cout << "INF"
					<< "	 ";
			else
				cout << distance[i][j] << "	 ";
		}
		cout << endl;
	}
}
int main()
{
	int graph[V][V] = { { 1, 4, INF, 9 },
						{ INF, 1, 3, INF },
						{ INF, INF, 1, 2 },
						{ INF, INF, INF, 1 } };

	floyd(graph);
	return 0;
}
