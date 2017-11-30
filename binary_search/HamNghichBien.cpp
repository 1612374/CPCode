//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1282
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int p, q, r, s, t, u;

double f(double x){
  return p*exp(-x) + q * sin(x) + r * cos(x) + s*tan(x) + t*x*x + u; // ham nghich bien, nen ap dung binary_search
}

int main(){
  //freopen("x.txt", "r", stdin);

  while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6){
    if (f(1) > 0 || f(0) < 0)    // ham nghich bien
      cout << "No solution\n";
    else{
      double lo = 0.0, hi = 1.0, mid;
      for (int i = 0; i < 30; i++){ 
        mid = (lo + hi) / 2;
        if (f(mid) > 0)
          lo = mid;
        else hi = mid;
      }

      printf("%.4lf\n", lo);
    }

  }

  return 0;
}