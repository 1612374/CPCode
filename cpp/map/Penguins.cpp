//http://acm.timus.ru/problem.aspx?num=1585 
#include <iostream>
#include <map>
#include <set>
#include <fstream>
using namespace std;

int n;
map<string, int> M;
set<string> S;

int main(){

  //freopen("xx.txt", "r", stdin);

  cin >> n;
  string tmp;
  getline(cin, tmp);
  for (int i =0 ; i < n; i++){
    getline(cin, tmp);
    M[tmp]++;
    S.insert(tmp);
  }

  set<string>::iterator it;

  int cnt = 0;
  string res = "";
  for (it = S.begin(); it != S.end(); it++){
    if (M[*it] > cnt) {
      cnt = M[*it];
      res = *it;
    }
  }

  cout << res;
  return 0;
}