//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
const int INF = 1e9;

struct triad{
    int src;
    int dest;
    int wei;
};

vector <int> dist(MAX, INF);
vector <triad> graph;

int n, m;
//int path[MAX];

bool BellmanFord(int src, vector<triad> &graph, vector<int> &dist){

    int u, v, w;
    dist[src] = 0;
    for (int i = 1; i <= n - 1; i++){
        for (int j = 0; j < m; j++){
            u = graph[j].src;
            v = graph[j].dest;
            w = graph[j].wei;
            if (dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                //path[v] = u;
            }
        }
    }

    //
    for (int i = 0; i < m; i++){
        u = graph[i].src;
        v = graph[i].dest;
        w = graph[i].wei;
        if (dist[u] != INF && dist[u] + w < dist[v]){
            return false;
        }
    }

    return true;
}

int main(){
    int c;
    cin >> c;
    int  x, y, t;
    while (c--){
        cin >> n >> m;

        dist = vector<int>(n, INF);
        graph.clear();

        for (int i = 0; i < m; i++){
            triad tmp;
            cin >> x >> y >> t;
            tmp.src = x;
            tmp.dest = y;
            tmp.wei = t;
            graph.push_back(tmp);
        }

        bool check = BellmanFord(0, graph, dist);

        if (check == false)
            cout << "possible\n";
        else
            cout << "not possible\n";

    }

    return 0;
}
