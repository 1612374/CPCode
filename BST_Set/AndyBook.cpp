//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1756
#include <bits/stdc++.h>
using namespace std;

set <string> S;

int main(){

  //freopen("x.txt", "r", stdin);
  string in, tmp = "";

  while (cin >> in){
    
    tmp = "";
    for (int i = 0; i < in.length(); i++){
      char c = tolower(in[i]);
      
      if (isalpha(c)) tmp += c;
      else if (tmp != ""){
        
        S.insert(tmp);
        tmp = "";
      
      }
    
    }

    if (tmp != "")
      S.insert(tmp);
  }

  set<string>::iterator it;
  for (it = S.begin(); it != S.end(); it++){
    cout << *it << "\n";
  }

  return 0;
}