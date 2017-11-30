//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1744
#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;
int t, n;
double x, y;
double F[101][101];
typedef pair<double, double> pdd;


vector <pdd> graph;


double euclid_square(pdd A, pdd B){
  return sqrt((A.first - B.first)*(A.first - B.first) + 
    (A.second - B.second)*(A.second - B.second));
}


int main(){

  //freopen("x.txt", "r", stdin);
  cin >> t;
  int cs = 1;
  while (t--){
    cin >> n;

    graph.clear();

    for (int i = 0; i < n; i++){
      cin >> x >> y;
      graph.push_back(pdd(x, y));
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        F[i][j] = euclid_square(graph[i], graph[j]);
        
        if (F[i][j] > 10) F[i][j] = INF;
        
        //if (F[i][j] != INF) cout << F[i][j] << " ";  
        //cout << F[i][j] << endl;

      }
    }

    for (int k = 0; k < n; k++){
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          if (F[i][j] > F[i][k] + F[k][j]){
            F[i][j] = F[i][k] + F[k][j];
          }
        }
      }
    }


    double res = 0;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (F[i][j] > res)
          res = F[i][j];
      }
    }

    printf("Case #%d:\n", cs++);
    if (res == INF) cout << "Send Kurdy\n";
    else printf("%.4lf\n", res);
    cout << endl;

  }
  
  return 0;
}