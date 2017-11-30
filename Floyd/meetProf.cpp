//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1112
#include <bits/stdc++.h>
using namespace std;

int n;
char a,b,c,d;
int e;
char s, t;
int n_ver;

const int INF = 1e9;
int Fy[30][30], Fm[30][30];
//bool check_vertex[30] = {false};


void Init(){
  for (int i = 0; i < 30; i++){
    for (int j = 0; j < 30; j++){
      Fy[i][j] = Fm[i][j] = INF;
    }
    Fy[i][i] = Fm[i][i] = 0;
    //check_vertex[i] = false;
  }
}

void Floyd(int F[][30]){
  for (int k = 0; k < n_ver; k++){
    for (int i = 0; i < n_ver; i++){
      for (int j = 0; j < n_ver; j++){
        if (F[i][j] > F[i][k] + F[k][j]){
          F[i][j] = F[i][k] + F[k][j];
        }
      }
    }
  }
}



int main(){
  //freopen("x.txt", "r", stdin);

  while (1){
    cin >> n;
    if (n == 0) break;
    Init();
    //cout << Fm[1][1] << endl;

    for (int i = 0; i < n; i++){
      cin >> a >> b >> c >> d >> e;

      //check_vertex[a - 65] = check_vertex[b - 65] = check_vertex[c - 65] = check_vertex[d - 65] = true;

      if (a == 'Y')
        (b == 'U') ? (Fy[c - 65][d - 65] = min(e, Fy[c - 65][d - 65])) : (Fy[c - 65][d - 65] = Fy[d - 65][c - 65] = min(e, Fy[c - 65][d - 65]));
      else if (a == 'M')
        (b == 'U') ? (Fm[c - 65][d - 65] = min(e, Fm[c - 65][d - 65])) : (Fm[c - 65][d - 65] = Fm[d - 65][c - 65] = min(e, Fm[c - 65][d - 65]));

    }

    //cout << Fm[3][2] << " " << Fm[2][3] << endl;
    //cout << Fy[2][0] << " " << Fy[0][2] << endl;
    
    n_ver = 30;
    
    cin >> s >> t;
    //cout << "sd";

    Floyd(Fy);
    Floyd(Fm);
    
    int ans = INF;
    
    for (int i = 0; i < n_ver; i++){
      if (Fy[s - 65][i] + Fm[t - 65][i] < ans){
        ans = Fy[s - 65][i] + Fm[t - 65][i];
      }
    }

    if (ans == INF) cout << "You will never meet.\n";
    else{
      cout << ans;
      for (int i = 0; i < n_ver; i++){
        if (ans == Fy[s - 65][i] + Fm[t - 65][i]) 
          cout << " " << (char)(i + 65); 
      }

      cout << endl;
    }
    
  }

  return 0;
}