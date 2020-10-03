// Author : Subhodeep Kundu
#include<iostream>
#include<climits>
#define ll long long int
using namespace std;
void allPairShortestPathAlgo(int**edges, int V, int E) {

	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (edges[i][k] + edges[k][j] < edges[i][j])
					edges[i][j] = edges[i][k] + edges[k][j];
			}
		}

	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V, E;
	cin >> V >> E;
	int**edges = new int*[V];
	for (int i = 0; i < V; i++) {
		edges[i] = new int[V];
		for (int j = 0; j < V; j++) {
			if (i == j) {
				edges[i][j] = 0;
				continue;
			}
			edges[i][j] = 100000000;
		}
	}
	for (int i = 0; i < E; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
	}
	cout << "Given graph is:" << "\n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << edges[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\nAll Pair Shortest Path" << endl;
	allPairShortestPathAlgo(edges, V, E);
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << edges[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
