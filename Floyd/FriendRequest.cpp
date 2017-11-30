//http://www.spoj.com/problems/SOCIALNE/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#define MAX 55
const int INF =1e9;

vector <vector<char> > graph;
vector <vector<int> > dist;
//vector <vector<int> > path;

int m;

void Floyd(){

  int i, j, k;

  for (i = 0; i < m; i++){
    for (j = 0; j < m; j++){
      dist[i][j] = (graph[i][j] == 'N' ? 0 : 1);
      
    }
    dist[i][i] = 3;
  }

  /*
  for (int i = 0; i < m; i++){
    for (int j = 0; j < m; j++){
      cout << dist[i][j];
    }
    cout << endl;
  }*/

  for (k = 0; k < m; k++){
    for (i = 0; i < m; i++){
      for (j = 0; j < m; j++){
        if (dist[i][j] == 0){
          if (dist[i][k] == 1 && dist[k][j] == 1){
            dist[i][j] = 2;
          }
        }
      }
    }
  }

}

int main(){
  //freopen("x.txt","r", stdin);
  //freopen("xx.txt","w", stdout);
  int T;
  cin >> T;

  while (T--){
    string tmp;
    cin >> tmp;
    m = tmp.length();
    //cout << m;

    graph = vector <vector<char> >(m, vector<char>(m));
    dist = vector <vector<int> >(m, vector<int>(m));

    int x = 0;
    for (int j = 0; j < m; j++){
      graph[0][j] = tmp[x++];
    }


    for (int i = 1; i < m; i++){
      for (int j = 0; j < m; j++){
        cin >> graph[i][j];
      }
    }

    Floyd();

    int id = 0, res = 0;
    /*
    for (int i = 0; i < m; i++){
      for (int j = 0; j < m; j++){
        cout << dist[i][j];
      }
      cout << endl;
    }*/


    for (int i = 0; i < m; i++){
      int cnt = 0;
      for (int j = 0; j < m; j++){
        if (dist[i][j] == 2) cnt++;
      }
      if (cnt > res){
        id = i;
        res = cnt;
      }
    }

    cout << id << " " << res << endl;
  }

  return 0;
}