//http://acm.timus.ru/problem.aspx?space=1&num=1837
#include <bits/stdc++.h>
using namespace std;

int n, vertex = 0;
map <string, int> M;
set <string> list_name;

vector <int> graph[500];
vector <bool> vis;
vector <int> dis;

void bfs(int s){

  dis = vector<int>(500, 0);
  vis = vector<bool>(500, false);

  queue <int> q;
  q.push(s);
  vis[s] = true;
  
  while (q.empty() == false){
    int to = q.front();
    q.pop();
    for (int i =0; i < graph[to].size(); i++){
      int k = graph[to][i];
      if (vis[k] == false){
        vis[k] = true;
        q.push(k);
        dis[k] = dis[to] + 1;
      }
    }
  }
}

int main(){
  //freopen("xx.txt","r", stdin);
  scanf("%d", &n);

  string s1, s2, s3;

  for (int i = 0; i < n; i++){
    cin >> s1 >> s2 >> s3;
    if (M[s1] == 0) M[s1] = ++vertex;
    if (M[s2] == 0) M[s2] = ++vertex;
    if (M[s3] == 0) M[s3] = ++vertex;

    list_name.insert(s1);
    list_name.insert(s2);
    list_name.insert(s3);

    graph[M[s1]].push_back(M[s2]);
    graph[M[s2]].push_back(M[s1]);
    graph[M[s1]].push_back(M[s3]);
    graph[M[s3]].push_back(M[s2]);
    graph[M[s2]].push_back(M[s3]);
    graph[M[s3]].push_back(M[s1]);
  }

  int s = M["Isenbaev"];

  bfs(s);

  set<string>::iterator it;
  for (it = list_name.begin(); it!=list_name.end(); it++){
    if (dis[M[*it]] == 0 && *it != "Isenbaev")
      cout << *it << " " << "undefined" << endl;
    else cout << *it << " " << dis[M[*it]] << endl;
  }

}
