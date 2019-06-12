//http://codeforces.com/problemset/problem/424/B
#include <iostream>
#include <map>
#include <cstdio>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

map<double, int> city;

int main(){

  int n,s;
  cin >> n >> s;

  int x, y, k;
  double z;
  int sz = city.size();
  for (int i = 0; i < n; i++){
    cin >> x >> y >> k;

    z = sqrt((double)x*x + (double)y*y);

    city[z] += k;
      

  }

  map<double, int>::iterator it;

  it = city.begin();

  bool check = true;
  


  while (it != city.end()){
    
    s += it->second;
    
    //cout << it->first << " " << s << endl;

    if (s >= 1000000){
      printf("%.7lf",it->first);
      check = false;
      break;
    }

    it++;
  }

  if (check) cout << "-1";

  return 0;
}