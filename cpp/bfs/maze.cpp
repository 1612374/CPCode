//spoj MAZE
#include <bits/stdc++.h>
using namespace std;

struct coor{
    int x, y;
};

int t, m, n;
char grid[21][21];
char grid_tmp[21][21];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool intab(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

coor Get(int x, int y){
    coor res;
    res.x = x;
    res.y = y;
    return res;
}



bool isValid(int sx, int sy, int ex, int ey){
    bool vis[30][30] = {false};

    queue <coor> Q;
    coor tmp = Get(sx, sy);

    Q.push(tmp);
    vis[sy][sx] = true;

    while (Q.empty() == false){

        coor tmp = Q.front();

        Q.pop();

        for (int i = 0; i < 4; i++){

            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];

            //printf("%d-%d\n",nx,ny);

            if (intab(nx,ny) && vis[ny][nx] == false && grid_tmp[ny][nx] == '.')
            {
                vis[ny][nx] = true;
                Q.push(Get(nx,ny));

                if (nx == ex && ny == ey)
                    return true;
            }

        }

    }

    return false;

}

int main(){

    scanf("%d", &t);

    for (int i = 0; i < t; i++){
        scanf("%d%d", &m, &n);

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> grid[i][j];
                grid_tmp[i][j] = grid[i][j];
            }
        }

        //-----------------------------
        //check  entry and exit
        vector <coor> gate;
        for (int j = 0; j < n; j++){
            if (grid[0][j] == '.'){
                coor tmp;
                tmp.x = j;
                tmp.y = 0;
                gate.push_back(tmp);
                grid[0][j] = ',';
            }

            if (grid[m - 1][j] == '.'){
                coor tmp;
                tmp.x = j;
                tmp.y = m - 1;
                gate.push_back(tmp);
                grid[m - 1][j] = ',';
            }
        }

        for (int i = 1; i < m - 1; i++){
            if (grid[i][0] == '.'){
                coor tmp;
                tmp.x = 0;
                tmp.y = i;
                gate.push_back(tmp);
                grid[i][0] = ',';
            }

            if (grid[i][n - 1] == '.'){
                coor tmp;
                tmp.x = n - 1;
                tmp.y = i;
                gate.push_back(tmp);
                grid[i][n - 1] = ',';
            }
        }

        if (gate.size() != 2){
            puts("invalid");
            continue;
            /*cout << gate[0].x << " " << gate[0].y << endl;
            cout << gate[1].x << " " << gate[1].y << endl;*/
        }

        if (isValid(gate[0].x, gate[0].y, gate[1].x, gate[1].y))
            puts("valid");
        else
            puts("invalid");
    }

}
