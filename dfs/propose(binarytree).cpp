#include <bits/stdc++.h>
using namespace std;
int n;

vector<int> graph[1001];
int vis[1001];
int dis[1001];


void DFS(int s){
 	
	for (int i = 1; i <= n; i++){
		vis[i] = false;	 	
		dis[i] = 0;
	}

	stack<int> st;

	st.push(s);
	vis[s] = true;

	
	while (st.empty() == false){

	 	int tmp = st.top();

	 	st.pop();

	 	vector<int>::iterator i;
	 	
	 	for (i = graph[tmp].begin(); i != graph[tmp].end(); i++){

	 	 	if (vis[*i] == false){

	 	 	 	vis[*i] = true;
	 	 	 	st.push(*i);
	 	 	 	dis[*i] = dis[tmp] + 1;
	 	 	}
	 	}


	}


}

int main(){
    scanf("%d", &n);
 	
 	int u, v;
 	for (int i = 0; i < n - 1; i++){
 		scanf("%d%d", &u, &v);
 		graph[u].push_back(v);
 		graph[v].push_back(u);
 	}
    
    DFS(1);

    /*
    for (int i = 2; i <= n; i++)
        printf("%d %d\n",i, dis[i]); 
     */

    int g;

    scanf("%d", &g);
    int tmp;
    int res = 0, minn = 100000;
    for (int i = 0; i < g; i++)
    {
        cin >> tmp;
        if (dis[tmp] < minn){
            minn = dis[tmp];
            res = tmp;
        }
        else if (dis[tmp] == minn){
            if (res > tmp)
                res = tmp;
        }

    }

	cout << res;

    return 0;
}










