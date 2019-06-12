//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/description/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

long long n, m, t, tmp;

int main(){
  //freopen("x.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--){
    cin >> n >> m;

    set<long long> mS;

    for (int i = 0; i < n; i++){
      cin >> tmp;
      mS.insert(tmp);
    }

    int sz = mS.size();
    
    for (int i = 0; i < m; i++){
      cin >> tmp;

      mS.insert(tmp);
      
      if (mS.size() > sz) cout << "NO\n";
      
      else {
        cout << "YES\n";
      }
      
      sz = mS.size();
    }
  
  }


  return 0;
}