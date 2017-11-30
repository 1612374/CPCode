//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541
#include <bits/stdc++.h>
using namespace std;

#define MAX 107
#define INF 1e9

struct edge
{
	int u, v, w;
};

typedef pair<int, int> pii;
typedef vector<pii> vii;

vii graph[MAX];
vii graph_tmp[MAX];
vector<edge> save; 
vector<bool> vis(MAX, false);
vector<int> dist(MAX, INF);
vector<int> path(MAX, -1);

int test, m, n;

void Prim(int s){

	priority_queue <pii, vii, greater<pii> > pq;

	pq.push(pii(0,s));

	dist[s] = 0;

	while (!pq.empty()){

		pii tmp = pq.top();
		pq.pop();

		int  u = tmp.second;
		vis[u] = true;

		for (int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			if (!vis[v] && dist[v] > w){
				dist[v] = w;
				pq.push(pii(w, v));
				path[v] = u;		
			}
		}

	}

}


void Prim_nopath(int s){

	priority_queue <pii, vii, greater<pii> > pq;

	pq.push(pii(0,s));

	dist[s] = 0;

	while (!pq.empty()){

		pii tmp = pq.top();
		pq.pop();

		int  u = tmp.second;
		vis[u] = true;

		for (int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			if (!vis[v] && dist[v] > w){
				dist[v] = w;
				pq.push(pii(w, v));		
			}
		}

	}

}

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);
	scanf("%d", &test);

	int u, v, w;
	while (test--){

		scanf("%d%d", &n, &m);

		vis = vector<bool>(MAX, false);
		dist = vector<int> (MAX, INF);
		path = vector<int> (MAX, -1);
		save.clear();

		for (int i = 0; i < MAX; i++){
			graph[i].clear();
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v >> w;
			edge tmp = {u, v, w};

			save.push_back(tmp);
			
			graph[u].push_back(pii(v, w));
			graph[v].push_back(pii(u, w));

		}

		Prim(1);


		int res1 = 0; 
		for (int i = 1; i <= n; i++)
			res1 += dist[i];

		cout << res1;

		// --------------
		
		int res2 = INF;


		for (int i = 2; i <= n; i++)
		{

			//cout << "\\" <<  i << " " << path[i] << endl;

			for (int j = 0; j < MAX; j++)
			{
				graph[j].clear();
			}

			for (int j = 0; j < save.size(); j++)
			{
				
				u = save[j].u;
				v = save[j].v;
				w = save[j].w;

				//cout << u << " " << v << " " << w << " "; 

				if ((u == path[i] && v == i) || (u == i && v == path[i]))
					continue;
				else
				{
					//cout << "ok";
					graph[u].push_back(pii(v, w));
					graph[v].push_back(pii(u, w));
				}
				//cout << endl;
			
			}

			//cout << "*************\n";

			/*for (int k = 1; k <= n; k++){
				for (int h = 0; h < graph[k].size(); h++){
					cout << k << " "  << graph[k][h].first << " " << graph[k][h].second << endl;
				}
			}

			cout << "-------------\n";
			*/

			vis = vector<bool>(MAX, false);
			dist = vector<int> (MAX, INF);

			Prim_nopath(1);
			int res2_tmp  = 0;
			
			for (int j = 1; j <= n; j++)
				if (dist[j] >= INF)
				{
					res2_tmp = INF;
					break;
				}
				else 
					res2_tmp += dist[j];
			
			//cout << res2_tmp << endl;
			
			res2 = min(res2, res2_tmp);
		
		}

		cout << " " << res2 << endl;

	}



	return 0;
}