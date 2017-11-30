#include <bits/stdc++.h>
using namespace std;

int di[] = {-1,1,0,0};
int dj[] = {0,0, 1, -1};
int R, C;

struct coor
{
  int i, j;
};

coor Get(int i, int j){
    coor res;
    res.i = i;
    res.j = j;
    return res;
}

bool intab(int i, int j){
  return i >= 0 && i < R && j >=0 && j < C;
}

void bfs(int si, int sj, char grid[][1001], int dist[][1001]){
  
  bool vis[1001][1001] = {false};

    queue <coor> Q;
    coor tmp = Get(si, sj);

  Q.push(tmp);
    vis[si][sj] = true;

    while (Q.empty() == false){

        coor tmp = Q.front();

        Q.pop();

        for (int k = 0; k < 4; k++){

            int ni = tmp.i + di[k];
            int nj = tmp.j + dj[k];

            //printf("%d-%d\n",nx,ny);

            if (intab(ni, nj) && vis[ni][nj] == false && grid[ni][nj] != 'X')
            {
                vis[ni][nj] = true;
                Q.push(Get(ni,nj));

                dist[ni][nj] = dist[tmp.i][tmp.j] + 1;
            }

        }

    }
}

int main(){

  //freopen("x.txt", "r", stdin);

  while (1){
    cin >> R >> C;

    if (R == 0 && C == 0)
      break;

    char grid[1001][1001] = {'0'};
    int dist[1001][1001] = {0};


    int rows;
    cin >> rows;

    int b_row, row;
    for (int i = 0; i < rows; i++){
      cin >> row;
      cin >> b_row;

      for (int j = 0; j < b_row; j++){
        int bomb;
        cin >> bomb;
        grid[row][bomb] = 'X';
      }
    }

    int si, sj;
    cin >> si >> sj;
    int a, b;
    cin >> a >> b;

    bfs(si, sj, grid, dist);

    cout << dist[a][b] << endl;;

  }

  return 0;
}