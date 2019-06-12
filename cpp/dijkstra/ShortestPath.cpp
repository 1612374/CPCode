//http://www.spoj.com/problems/SHPATH/en/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <fstream>
using namespace std;

#define MAX 10000
const int INF = 1e9;

typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

vector<vii> graph;
vector<int> dist(MAX+5, INF);

struct name
{
	int idx;
	string s_name;
};

void Dijkstra(int s){
	priority_queue<pii, vii, greater<pii> > pq;

	pq.push(pii(0, s));
	dist[s] = 0;

	while (pq.empty() == false){
		pii top = pq.top();
		pq.pop();

		int node = top.second;
		int d = top.first;

		for (int i = 0; i < graph[node].size(); i++){
			pii neigh = graph[node][i];
			if (neigh.second+d < dist[neigh.first]){
				dist[neigh.first] = neigh.second+d;
				pq.push(pii(dist[neigh.first], neigh.first));
			}
		}
	}
}

vector <name> v;

int find_idx(string s){
	int i = 0;
	for (i = 0; i < v.size(); i++){
		if (v[i].s_name == s)
			break;
	}
	return i + 1;
}

int main(){
	//freopen("x.txt", "r", stdin);

	int s, n;
	cin >> s;
	for (int y = 1; y <= s; y++)
	{
		graph = vector <vii>(MAX+5);
		dist = vector<int>(MAX+5, INF);
		v.clear();

		cin >> n;
		for (int i = 1; i <= n; i++){
			string s;
			int p;
			cin >> s;
			cin >> p;
			name tmp;
			tmp.s_name = s, tmp.idx = i;
			v.push_back(tmp);

			int nr, cost;
			for (int j = 0; j < p; j++){
				cin >> nr >> cost;
				graph[i].push_back(pii(nr, cost));
			}

		}

		int r;
		cin >> r;

		string s1, s2;
		for (int j = 0; j < r; j++){
			cin >> s1 >> s2;

			int idx1 = find_idx(s1);
			int idx2 = find_idx(s2);

			//cout << idx1 << " " << idx2 << endl;

			Dijkstra(idx1);

			cout << dist[idx2] << endl;

			dist = vector<int>(MAX+5, INF);

		}

	}


	return 0;
}
