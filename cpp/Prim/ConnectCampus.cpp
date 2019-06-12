//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1338
#include <bits/stdc++.h>
using namespace std;


#define MAX 800
#define INF 1e9

struct coor
{
	int x,y;
};

struct vertex_pair
{
	int a, b;
};

typedef pair<int, double> pid;
typedef pair<double, int> pdi;

int n, m, x, y;
vector <coor> data;
vector <pid> graph[MAX];
vector <vertex_pair> connected;
vector<double> dist(MAX, INF);
vector<bool> vis(MAX, false);

double Distance(coor a, coor b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}


bool isConnected(int a, int b){
	for (int i = 0; i < connected.size(); i++){
		if ((a == connected[i].a && b == connected[i].b) || 
			(b == connected[i].a && a == connected[i].b))
			return true;
	}
	return false;
}


void Prim(int s){
  priority_queue <pdi, vector<pdi> , greater<pdi > > pq;

  pq.push(pdi(0,s));
  dist[s] = 0;

  while (!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    vis[u] = true;

    for (int i = 0; i < graph[u].size(); i++){
      int v = graph[u][i].first;
      double w = graph[u][i].second;

      if (!vis[v] && dist[v] > w){
        dist[v] = w;
        pq.push(pdi(w,v));
      }
    }
  } 
}

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);
	while (cin >> n){

		data.clear();
		connected.clear();

		for (int i = 0; i < MAX; i++){
			graph[i].clear();
		}

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			coor tmp = {x, y};

			data.push_back(tmp);
		}

		cin >> m;

		for (int i = 0; i < m; ++i)
		{
			cin >> x >> y;
			vertex_pair tmp = {x - 1, y - 1};

			connected.push_back(tmp);
		}


		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; j++){

				if (!isConnected(i, j)){
					double d = Distance(data[i], data[j]);
					graph[i].push_back(pid(j, d));
					graph[j].push_back(pid(i, d));
				}
				else{
					graph[i].push_back(pid(j, 0));
					graph[j].push_back(pid(i, 0));
				}
			}

		}

		dist = vector <double> (MAX, 1e9);
		vis = vector <bool> (MAX, false);

		Prim(0);

		double res = 0;

		for (int i = 0; i < n; i++){
			res += dist[i];
		}

		printf("%.2lf\n", res);
	}


	return 0;
}