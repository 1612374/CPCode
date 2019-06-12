//http://codeforces.com/contest/844/problem/C
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
const int MAX = 1e5 + 10;

int a[MAX], b[MAX], n;
vector <vector <int> > ans(MAX);
int ans_sz = 0;
bool vis[MAX] = {false};

void dfs(int s)
{
  if (vis[s])
    return;

  ans[ans_sz].push_back(s + 1);
  vis[s] = true;
  int next = lower_bound(b, b+n, a[s]) - b;
  dfs(next);
}

int main(int argc, char const *argv[])
{
  //freopen("xx.txt", "r", stdin);

  cin >> n;
  FOR(i, n){
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b, b+n);

  FOR(i, n){
    if (vis[i] == false){
      dfs(i);
      ans_sz++;
    }
  }

  cout << ans_sz << "\n";
  FOR(i, ans_sz){
    cout << SZ(ans[i]) << " ";
    FOR(j, SZ(ans[i])){
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
