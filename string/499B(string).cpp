#include <bits/stdc++.h>
using namespace std;
struct str{
  string s1;
  string s2;
  string best;
};

int n, m;
vector <str> vs;

int main(){
  scanf("%d%d", &n, &m);
  string tmp1, tmp2;
  for (int i = 0; i < m; i++){
     cin >> tmp1 >> tmp2;
     str tmp;
     tmp.s1 = tmp1;
     tmp.s2 = tmp2;
     if (tmp1.length() > tmp2.length())
        tmp.best = tmp2;
     else
        tmp.best = tmp1;
     vs.push_back(tmp);
  }
  string sx;
  for (int i = 0; i < n; i++){
      cin >> sx;
      for (int j = 0; j < m; j++){
      	 if (sx == vs[j].s1 || sx == vs[j].s2){
      	    cout << vs[j].best << " ";
         }
      }
  }

  return 0;
}