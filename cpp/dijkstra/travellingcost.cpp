#include <bits/stdc++.h>
using namespace std;

#define MAX 501
const int INF = 1e9;
vector <vector <pair<int, int> > > graph;
vector <int> dist(MAX, INF);
int path[MAX];

void Dijkstra(int s, vector <vector <pair<int, int> > > &v, vector <int> &distance){

	priority_queue<pair<int, int>, vector <pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(pair <int, int> (0, s));

	distance[s] = 0;

	while (!pq.empty()){


		pair<int, int> top = pq.top();
		pq.pop();

		int node = top.second;
		int d = top.first;

		for (int i = 0; i < v[node].size(); i++){
			pair <int, int> neighbor = v[node][i];
			if (d + neighbor.second < distance[neighbor.first]){

				distance[neighbor.first] = d+neighbor.second;
				pq.push(pair <int, int> (distance[neighbor.first], neighbor.first));
				path[neighbor.first] = node;
			}
		}
	}

}

int n, u, q;
int main(){

	cin >> n;

	graph = vector <vector <pair<int, int> > > (MAX+5, vector <pair<int, int> >() );
	int d = 0;

	int a, b, w;
	for (int i = 0; i < n; i++){
		cin >> a >> b >> w;

		graph[a].push_back(pair<int, int> (b, w));
		graph[b].push_back(pair<int, int> (a, w));
	}

	cin >> u >> q;

	Dijkstra(u, graph, dist);
	int dest;
	for (int i = 0;  i < q; i++){
		cin >> dest;

		if (dist[dest] == INF)
			cout << "NO PATH\n";
		else
			cout << dist[dest] << endl;
	}


	return 0;
}