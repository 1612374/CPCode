//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
using namespace std;

#define MAX 20001
const int INF = 1e9;

typedef pair<int, int> pii;
typedef vector<pii> vii;


vector <vii> graph;
vector <int> dist;

void Dijktra(int s){

	priority_queue<pii, vii, greater<pii> > pq;

	pq.push(pii(0, s));

	while (!pq.empty()){

		pii top = pq.top();
		pq.pop();

		int node = top.second;
		int d = top.first;

		for (int i = 0; i < graph[node].size(); i++){
			pii neigh = graph[node][i];
			if (neigh.second + d < dist[neigh.first]){
				dist[neigh.first] = neigh.second + d;
				pq.push(pii(dist[neigh.first], neigh.first));
			}
		}
	}

}

int main(){

	//freopen("x.txt", "r", stdin);
	int t;
	cin >> t;

	int n, m, s, e;
	for (int i = 0; i < t; i++){
		graph = vector<vii>(MAX + 5);
		dist = vector<int>(MAX+5, INF);

		cin >> n >> m >> s >> e;

		int u, v, w;
		for (int j = 0; j < m; j++){
			cin >> u >> v >> w;
			graph[u].push_back(pii(v, w));
			graph[v].push_back(pii(u, w));
		}

		Dijktra(s);
		printf("Case #%d: ", i + 1);

		(dist[e] == INF) ? cout << "unreachable\n" : cout << dist[e] << endl; 

	}

	return 0;
}