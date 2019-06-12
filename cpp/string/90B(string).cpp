#include <bits/stdc++.h>
using namespace std;

int m, n;
vector <string> vs;
string s;

bool ok(int i, int j){
    for (int k = 0; k < m; k++){
       if (i != k && vs[i][j] == vs[k][j]){
          return false;
       }
    }
    for (int k = 0; k < n; k++){
       if (j != k && vs[i][j] == vs[i][k]){
          return false;
       }
    }
    return true;
}

int main(){
  cin >> m >> n;

  for (int i = 0; i < m; i++){
     cin >> s;
     vs.push_back(s);
  }

  for (int i = 0; i < m; i++){
     for (int j = 0; j < n; j++){
         if (ok(i,j))
           cout << vs[i][j];
     }
  }
  return 0;
}