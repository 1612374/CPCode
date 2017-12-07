//http://codeforces.com/contest/844/my
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

string s;
int k;

int main(int argc, char const *argv[])
{
  cin >> s;
  cin >> k;

  if (SZ(s) < k || k > 26){
    cout << "impossible";
    return 0;
  }

  int cnt[256] = {0};

  FOR(i, SZ(s)){
    cnt[s[i]]++;
  }

  int res = 0;
  REP(i, 97, 122){
    if (cnt[i] >= 1){
      res++;
    }
  }

  if (k > res)
    cout << k - res;
  else
    cout << 0;
  return 0;
}