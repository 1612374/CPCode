//http://www.spoj.com/problems/EKO/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef long long ll;
ll n, m;
vector<ll> a;

int main(){

  //freopen("x.txt", "r", stdin);
  
  cin >> n >> m;
  a.resize(n);

  int maxi = 0;
  for (int i =0 ; i < n; i++){
    cin >> a[i];
    if (a[i] > maxi)
      maxi = a[i];
  }
  

  ll left = 0, right = maxi, mid;
  ll ans =0 ;
  while (left <= right){
    mid = left + (right - left) / 2;

    ll cuted = 0;
    for (int i = 0; i < n; i++){
      if (a[i] - mid > 0)
        cuted += a[i] - mid;

    }

    if (cuted == m){
      ans = mid;
      break;
    }

    if (cuted < m){
      right = mid - 1;
    }
    else{
      if (mid > ans)
        ans = mid;

      left = mid + 1;
    }

  }

  cout << ans;

  return 0;
}