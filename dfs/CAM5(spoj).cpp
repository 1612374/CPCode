#include <bits/stdc++.h>
using namespace std;

int t, n, e, a, b;
vector<int> graph[100000];
bool vis[100000] = {false};

void DFS(int i){
    vis[i] = true;

    vector <int>::iterator it;

    for (it = graph[i].begin(); it != graph[i].end(); it++){
        if (vis[*it] == false){
            DFS(*it);
        }
    }

}

int main(){
    scanf("%d", &t);
    for (int k = 0; k < t; k++){


        scanf("%d", &n);
        scanf("%d", &e);
        for (int i = 0; i < e; i++){
            scanf("%d%d", &a, &b);

            graph[a].push_back(b);
            graph[b].push_back(a);

        }

        int ans = 0;

        for (int i = 0; i < n; i++){
            if (vis[i] == false){
                DFS(i);
                ans++;
            }
        }
        cout << ans << endl;

        for (int i = 0; i < n; i++){
            graph[i].resize(0);
        }

        memset(vis, false, 100000*sizeof(vis[0]));
    }

    return 0;
}
