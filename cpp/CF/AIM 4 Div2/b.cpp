//http://codeforces.com/contest/844/problem/B
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
int n, m, a[100][100];

int main(int argc, char const *argv[])
{
  //freopen("xx.txt", "r", stdin);

  cin >> n >> m;

  FOR(i, n){
    FOR(j, m){
      cin >> a[i][j];
    }
  }

  ll res = 0;

  int cnt_b_row[100] = {0};
  int cnt_b_col[100] = {0};

  FOR(i, n){
    FOR(j, m){
      if (a[i][j] == 0){
        cnt_b_col[j]++;
        cnt_b_row[i]++;
      }
    }
  }

  ll pow[70]; // key of problem
  pow[0] = 1;
  for(int i=1;i<70;i++) pow[i] = pow[i-1]*2;

  FOR(i, n){
    res += (pow[cnt_b_row[i]] - 1);
    res += (pow[m - cnt_b_row[i]] - 1);
  }

  FOR(j, m){
    res += (pow[cnt_b_col[j]] -  1);
    res += (pow[n - cnt_b_col[j]] - 1);
  }

  cout << res-n*m;
}