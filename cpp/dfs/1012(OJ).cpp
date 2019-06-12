#include <bits/stdc++.h>
using namespace std;

int t, w, h;
char grid[21][21];
bool  vis[21][21] = {false};

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0 ,1, -1};

int res = 1;

bool intab(int i, int j){

    return i >= 0 && i < h && j >= 0 && j < w;
}

void DFS(int i, int j){
    vis[i][j] = true;

    for (int k = 0; k < 4; k++){
        int ni = i + di[k];
        int nj = j + dj[k];

        if (intab(ni,nj) && grid[ni][nj] == '.' && vis[ni][nj] == false){
            res++;
            DFS(ni, nj);
        }

    }

}

int main(){
    cin >> t;

    for (int k = 0; k < t; k++){
        cin >> w >> h;

        int si, sj;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin >> grid[i][j];
                if (grid[i][j] == '@'){
                    si = i;
                    sj = j;
                }
            }
        }

        DFS(si,sj);

        printf("Case %d: %d\n", k + 1, res);
        res = 1;

        for (int i = 0; i < 21; i++){
            for (int j = 0; j < 21; j++){
                vis[i][j] = false;
            }
        }
    }

    return 0;
}
