#include <bits/stdc++.h>
using namespace std;

struct coor{
    int i, j, numNode;
};

int n, m, k;
char grid[51][51];
bool vis[51][51] = {false};
vector <coor> res;
int di[] = {0,0,1,-1};
int dj[] = {1,-1,0,0};
bool bigcheck = true;

bool intab(int i, int j){
    return i >= 0 && i < n && j >=0 && j < m;
}

bool isSea(int i, int j){
    return i == 0 || j == 0 || i == n - 1 || j == m - 1;
}

void DFS(int i, int j, int &numNode){

    vis[i][j] = true;

    for (int k = 0; k < 4; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if (intab(ni,nj) && grid[ni][nj] == '.' && vis[ni][nj] == false){
            if (isSea(ni, nj)){
                numNode = 0;
                bigcheck = false;
            }
            else{
                numNode++;
                DFS(ni,nj, numNode);
            }
        }
    }

}

void printgrid(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void Sort(){

    if (res.size() > 0){
        for (int i = 0; i < res.size() - 1; i++){
            for (int j = i+1; j < res.size(); j++){
                if (res[i].numNode < res[j].numNode){
                    swap(res[i], res[j]);
                }
            }
        }
    }
}

void full_lake(int i, int j){
    grid[i][j] = '*';

    for (int k = 0; k < 4; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if (intab(ni,nj) && grid[ni][nj] == '.'){
            full_lake(ni,nj);
        }
    }


}

int main(){

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!isSea(i, j) && grid[i][j] == '.' && vis[i][j] == false){
                int numNode = 1;
                DFS(i, j, numNode);
                if (bigcheck == true){
                    cnt++;
                    coor tmp;
                    tmp.i = i, tmp.j = j, tmp.numNode = numNode;
                    res.push_back(tmp);
                }
                else bigcheck = true;
            }
        }
    }

    Sort();

    /*for (int i = 0; i < res.size(); i++){
        cout << res[i].i << " " << res[i].j << " " << res[i].numNode << endl;
    }*/

    int sz = res.size();

    int ans = 0; //minimum number of cells which should be transformed from water to land
    while (sz > k){
        full_lake(res[sz - 1].i, res[sz - 1].j);
        ans += res[sz - 1].numNode;
        sz--;
        res.resize(sz);
    }
    cout << ans << endl;
    printgrid();

    return 0;
}