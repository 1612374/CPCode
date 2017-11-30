//https://www.hackerrank.com/contests/womens-codesprint-2/challenges/minimum-loss
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, tmp, a[200010];
set<ll> S;

int main(){

  //freopen("x.txt","r", stdin);
  scanf("%lld", &n);

  for (int i = 0; i  < n; i++){
    cin >> a[i];
  }

  ll res = 1e12;
  int j = 0;
  for (int i = 1; i < n; i++){
    for (; j < i; j++){
      S.insert(a[j]);
    }
    set<ll>::iterator up_val ;

    up_val = S.upper_bound(a[i]);

    if (*up_val - a[i] > 0) res = min(res, *up_val - a[i]);
    
    
  }

  cout << res;

  return 0;
}