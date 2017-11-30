//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

typedef long long ll;
int n, q;
vector<ll> a;

int main(){

  //freopen("x.txt", "r", stdin);

  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int tmp;
  cin >> q;
  for (int j = 0; j < q; j++){
    cin >> tmp;
    vector <ll>::iterator low_value;

    low_value = lower_bound(a.begin(), a.end(), tmp);
    int idx1 = low_value - a.begin();

    vector <ll>::iterator upp_value;
    upp_value = upper_bound(a.begin(), a.end(), tmp);
    int idx2 = upp_value - a.begin();

    if (idx1 <= 0) cout << "X ";
    else cout << a[idx1 - 1] << " ";

    if (idx2 < 0 || idx2 >= n) cout << "X";
    else cout << a[idx2];

    cout << endl;
  }

  return 0;
}