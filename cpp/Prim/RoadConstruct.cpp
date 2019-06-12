//http://lightoj.com/volume_showproblem.php?problem=1041
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100
#define INF 1e9

int test, m ,n;
map<string, int> M;
typedef pair<int, int> pii;
typedef vector<pii> vii;

vii graph[MAX];
vector <bool> vis(MAX, false);
vector <int> dist(MAX, INF);


void dfs(int s){
	vis[s] = true;

	for (int i = 0; i < graph[s].size(); i++){
		pii tmp = graph[s][i];
		if (vis[tmp.first] == false){
			dfs(tmp.first);
		}
	}
}

void Prim(int s){
  priority_queue <pii, vii, greater<pii > > pq;

  pq.push(pii(0,s));
  dist[s] = 0;

  while (!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    vis[u] = true;

    for (int i = 0; i < graph[u].size(); i++){
      int v = graph[u][i].first;
      int w = graph[u][i].second;

      if (!vis[v] && dist[v] > w){
        dist[v] = w;
        pq.push(pii(w,v));
      }
    }
  }
}


int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);

	scanf("%d", &test);
	int t = test;
	string s1, s2;
	int u, v, w, res;
	while (test--){
		cout << "Case " << t - test << ": ";
		scanf("%d", &m);
		n = 1;

		M.clear();

		for (int i = 0; i < MAX; i++){
      		graph[i].clear();
      		vis[i] = false;
    }


		for (int i = 0; i < m; i++)
		{
			cin >> s1 >> s2 >> w;

			if (!M[s1]) {
				M[s1] = n++;
			}

			u = M[s1];

			if (!M[s2]) {
				M[s2] = n++;
			}
			
			v = M[s2];

			graph[u].push_back(pii(v, w));
			graph[v].push_back(pii(u, w));

		}

		dfs(1);

		bool IMPOSSIBLE = false;
		for (int i = 1; i < n; i++){
			if (vis[i] == false){
				IMPOSSIBLE = true;
				break;
			}
		}

		if (IMPOSSIBLE){
		 cout << "Impossible\n";
		 continue;
		}

		vis = vector<bool>(MAX, false);
		dist = vector<int>(MAX, INF);

		Prim(1);

		res = 0;
 
    for (int i = 1; i < n; i++) {
    	res += dist[i];
    }
		cout << res << endl;
	}
	
	return 0;
}