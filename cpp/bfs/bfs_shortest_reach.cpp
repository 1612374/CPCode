#include <bits/stdc++.h>
using namespace std;

#define MAX 2001

int V, E; 
int path[MAX];
int dis[MAX];	
vector <int> graph[MAX];
bool vis[MAX];



void BFS(int s){	

	for (int i = 1; i <= V; i++){
	 	path[i] = -1;
	 	vis[i] = false;
	 	dis[i] = 0;
    }

    //dis[s] = 0;
 	queue <int> q;

 	q.push(s);
 	vis[s] = true;

 	while (q.empty() == false){
 	 			
 	 	int tmp = q.front();
 	 	q.pop();
 	 	vector <int>::iterator i;
 	 	
 	 	for (i = graph[tmp].begin(); i != graph[tmp].end(); i++){
 	 	  	if (vis[*i] == false){	
 	 			vis[*i] = true;
 	 			path[*i] = tmp;
 	 			q.push(*i);
 	 			dis[*i] = dis[tmp] + 1;		
 	 		}
 	 	 	
 	 	}
 	}

}


void print_ans(int s, int d, int *back){
	if (d == s){
	 	printf("0 ");
	 	return ;
 	}
 	int b[MAX], len = 0;
	int t = back[d];
	b[len++] = d;
	while (t != s){
		 	
		if (t == -1){
		 	printf("-1 ");
		 	return ;
		}
		
		b[len++] = t;
		t = back[t];
		
	}

	int ans = 0;

	for (int i = len - 1; i >= 0; i--){
	 	ans += 6;
	}

	cout << ans << " ";

}

int main(){
    int q;
    cin >> q;

	for (int k = 1; k <= q; k++){
	  	cin >> V >> E;
	  	int u, v;
	  	for (int i = 1; i <= E; i++){
	  	 	cin >> u >> v;
	  	 	graph[u].push_back(v);
	  	 	graph[v].push_back(u);	
		}

		int s;
		cin >> s;

		
		BFS(s);
		
		for (int i = 1; i <= V; i++){
		 	if (i != s){
		 		//print_ans(s, i, path);
		 		if (dis[i] == 0) cout << "-1 ";
		 		else
		 			cout << dis[i]*6 << " ";
		 	}
		}
		cout << endl;

		for (int i = 1; i <= V; i++)
			graph[i].clear();

	}

	return 0;
}