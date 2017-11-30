//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498
//check circle, nice problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;

typedef pair<int, int> pii;

#define MAX 110
const int INF = 1e9;

int n, sz, tmp;

vector <pii> edges;
int ene[MAX];
vector <int> dist(MAX);


bool bfs(int s){

	queue<int> q;
	q.push(s);

	vector<bool> vis(MAX, false);
	vis[s] = true;

	while (!q.empty()){

		s = q.front();
		q.pop();

		for (int i = 0; i < edges.size(); i++){
			pii e = edges[i];
			if (s == e.first && vis[e.second] == false){
				vis[e.second] = true;

				q.push(e.second);
				if (e.second == n){
					return true;
				}
			}
		}


	}

	return false;

}


int main(){

	//freopen("x.txt", "r", stdin);

    while (true){
        cin >> n;
        if (n == -1) break;

        edges.clear();
        dist = vector<int>(MAX, -INF);

        for (int i = 1; i <= n; i++){

            cin >> ene[i] >> sz;

            for (int j = 0;j < sz; j++){
                cin >> tmp;
                edges.push_back(pii(i, tmp));
            }

        }



        dist[1] = 100;

        for (int i = 1; i <= n - 1; i++){
            for (int j = 0; j < edges.size(); j++){
                pii e = edges[j];
                if (dist[e.first] <= 0) continue;
            	dist[e.second] = max(dist[e.second], dist[e.first] + ene[e.second]);
            }
        }

        // check circle
        bool check_cycle = false;
        for (int j = 0; j < edges.size(); j++){
        	pii e = edges[j];
        	if (dist[e.first] <= 0) continue;
        	if (dist[e.second] < dist[e.first] + ene[e.second] && bfs(e.first))
        	{
        		check_cycle = true;
        		break;
        	}
        }

        if (dist[n] > 0 || check_cycle) cout << "winnable\n";
        else cout << "hopeless\n";


    }

    return 0;
}
