//Freckles
#include <bits/stdc++.h>
using namespace std;


#define MAX 800
#define INF 1e9

struct coor
{
	double x,y;
};

struct vertex_pair
{
	int a, b;
};

typedef pair<int, double> pid;
typedef pair<double, int> pdi;

int n;
double x, y;
vector <coor> data;
vector <pid> graph[MAX];
vector <vertex_pair> connected;
vector<double> dist(MAX, INF);
vector<bool> vis(MAX, false);

double Distance(coor a, coor b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
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
	int test;
	cin >> test;
	while (test--){

		cin >> n;
		data.clear();

		for (int i = 0; i < MAX; i++){
			graph[i].clear();
		}

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			coor tmp = {x, y};

			data.push_back(tmp);
		}

		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; j++){

				double d = Distance(data[i], data[j]);
				graph[i].push_back(pid(j, d));
				graph[j].push_back(pid(i, d));
				
			}

		}

		dist = vector <double> (MAX, 1e9);
		vis = vector <bool> (MAX, false);

		Prim(0);

		double res = 0;

		for (int i = 0; i < n; i++){
			res += dist[i];
		}

		printf("%.2lf", res);

		if (test) cout << endl << endl;
	}

	cout << endl;

	return 0;
}