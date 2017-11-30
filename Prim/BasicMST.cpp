//http://www.spoj.com/problems/MST/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<pii> vii;
 
#define MAX 100100
const int INF = 1e9;
 
vector<pair<int, int> > graph[MAX];
bool vis[MAX];
vector<int> dist(MAX, INF);
 
int n, m;
 
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
 
int main(){
 
  cin >> n >> m;
  int u, v, w;
  for (int i =0 ; i < m; i++){
    cin >> u >> v >> w;
 
    graph[u].push_back(pii(v, w));
    graph[v].push_back(pii(u, w));
  }
 
 
  Prim(1);
 
  long long res = 0;
  for (int i = 1; i <= n; i++){
    res += 1LL*dist[i];
  }
 
  cout << res;
 
  return 0;
} 
