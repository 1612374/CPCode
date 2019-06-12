//http://www.spoj.com/problems/OPCPIZZA/
#include <bits/stdc++.h>
using namespace std;

vector <int> a;

int main(){

  int t, n, s;
  scanf("%d", &t);
  while (t--){

    scanf("%d%d", &n, &s);
    a = vector <int>(n);
    for (int i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i < n; i++){
      int tmp = s - a[i];
      if (binary_search(a.begin() + i + 1, a.end(), tmp))
        res++;
    }

    cout << res << endl;

  }


  return 0;
}
