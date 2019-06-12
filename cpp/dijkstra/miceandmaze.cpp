#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

#define MAX 101
const int INF = 1e9;
typedef pair<int, int> pii;
typedef vector<pii> vii;



vector <vii> graph;
vector <int> dist(MAX, INF);
int path[MAX];


void Dijkstra(int s){

	priority_queue<pii, vii, greater<pii> >pq;
	pq.push(pii(0, s));

	dist[s] = 0;

	while (!pq.empty()){
		pii top = pq.top();
		pq.pop();

		int node = top.second;
		int d = top.first;

		for (int i = 0; i < graph[node].size(); i++){
			pii neighbor = graph[node][i];
			if (d + neighbor.second < dist[neighbor.first]){
				dist[neighbor.first] = d + neighbor.second;
				pq.push(pii(dist[neighbor.first], neighbor.first));
				path[neighbor.first] = node;
			}
		}
	}
}

int n, e, t, m;

int main(){

	cin >> n >> e >> t >> m;
	graph = vector<vii>(MAX+5);
	int a, b, w;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> w;
		graph[b].push_back(pii(a,w)); // reverese, count from exit to other cells
	}

	Dijkstra(e);

	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (dist[i] <= t) cnt++;
	}

	cout << cnt;

	return 0;
}
