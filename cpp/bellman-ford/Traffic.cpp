//http://www.lightoj.com/volume_showproblem.php?problem=1074
#include <bits/stdc++.h>
using namespace std;

#define MAX 205
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
    freopen("xx.txt", "w", stdout);
    int T;
    cin >> T;



    int u, v, w;
    int x, q;
    for (int r = 1; r <= T; r++){
        cin >> n;
        vector <int> busy;

        graph.clear();
        dist = vector<int>(n + 1, INF);

        for (int i = 0; i < n; i++){
            cin >> x;
            busy.push_back(x);
        }

        cin >> m;

        for (int i = 0; i < m; i++){
            cin >> u >> v;
            w = (busy[v - 1] - busy[u - 1])*(busy[v - 1] - busy[u - 1])*(busy[v - 1] - busy[u - 1]);
            triad tmp;
            tmp.src = u;
            tmp.dest = v;
            tmp.wei = w;
            graph.push_back(tmp);
        }

        cin >> q;

        int k;
        BellmanFord(1, graph, dist);
        printf("Case %d:\n", r);
        while (q--){
            cin >> k;
            if (dist[k] != INF && dist[k] >= 3)
                cout << dist[k] << endl;
            else
                cout << "?\n";

        }
    }

    return 0;
}
