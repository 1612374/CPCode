#include <bits/stdc++.h>
using namespace std;

int main(){
  //freopen("x.txt", "r", stdin);

  int t;

  cin >> t;
  int n, m;
  int a[101];

  
  for (int k = 0; k < t; k++){
    cin >> n >> m;
    vector<int> b;
    queue<int> q;
    for (int i = 0; i < n; i++){
      cin >> a[i];
      b.push_back(a[i]);
    }

    sort(b.begin(), b.end());

    /*for (int i = 0; i < b.size(); i++)
      cout << b[i] << " ";
    cout <<  endl;*/

    for (int i = 0; i < n; i++){
      q.push(i);
    }

    int cnt = 1;
    
    while (1){

      if (q.empty() == false && a[q.front()] == b[b.size() - 1]){
        if (q.front() == m){
          cout << cnt << endl;
          break;
        }
        else{
          //int tmp = q.front();
          q.pop();
          cnt++;
          int sz = b.size();
          b.resize(sz - 1);
        }
      }
      else{
        int tmp = q.front();
        q.pop();
        q.push(tmp);

      }
    }
    
    /*
    while(q.empty() == false){
      int tmp  =q.front();
      if (a[tmp] == b[b.size() - 1]){
        if (tmp == m)
      }
    }*/



  }

  return 0;
}