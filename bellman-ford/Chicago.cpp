//https://www.urionlinejudge.com.br/judge/en/problems/view/1655
//basic bell-man but with double weight
#include <bits/stdc++.h>
using namespace std;

#define MAX 105
const int INF = 1e9;

struct triad{
    int src;
    int dest;
    double wei;
};

vector <triad> graph;
vector <double> dist;

int m, n;

bool bellmanFord(int src){

    dist[src] = 1.0;

    int u , v;
    double w;

    for (int i = 1; i <= n - 1; ++i){
        for (int j = 0; j < graph.size(); j++){
            u = graph[j].src;
            v = graph[j].dest;
            w = graph[j].wei;
            if (dist[u] != 0 && dist[u]*w > dist[v] && v != 1){
                dist[v] = dist[u]*w;
            }
        }
    }

    for (int j = 0; j < m; j++){
        u = graph[j].src;
        v = graph[j].dest;
        w = graph[j].wei;
        //cout <<  dist[u]*w << endl;
        if (dist[u] != 0 && dist[u]*w > dist[v] && v != 1){
            return false;
        }
    }

    return true;
}

int main(){

    //freopen("x.txt", "r", stdin);

    while (true){
        cin >> n ;
        if (n > 0) cin >> m;
        else break;

        graph.clear();
        dist = vector <double>(MAX, 0.0);

        int u, v, w;
        double fw;
        for (int i = 0; i < m; i++){
            cin >> u >> v >> w;
            fw = (double)w / 100;
            triad tmp;
            tmp.src = u;
            tmp.dest = v;
            tmp.wei = fw;
            graph.push_back(tmp);
            tmp.src = v;
            tmp.dest = u;
            graph.push_back(tmp);
        }

        bellmanFord(1);

        printf("%.6f percent\n", dist[n]*100.0);

    }

    return 0;
}
