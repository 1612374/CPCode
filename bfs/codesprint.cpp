//https://www.hackerrank.com/contests/world-codesprint-12/challenges/red-knights-shortest-path
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
const int MAX = 210;
int di[]={-2,-2,0, 0, 2, 2};
int dj[]={-1, 1,2,-2, 1,-1};

int is,js,ie,je,n,dist[MAX][MAX],path[MAX][MAX];

bool intab(int i, int j)
{
  return i >= 0 && i < n && j >=0 && j < n;
}

bool bfs()
{
  bool vis[MAX][MAX] = {false};
  queue <pii> Q;
  
  Q.push(mp(is,js));
  
  while (Q.empty()==false)
  {
    pii tmp = Q.front();
    Q.pop();

    FOR(k,6)
    {
      int ni = tmp.fi + di[k];
      int nj = tmp.se + dj[k];
      if (intab(ni,nj) && vis[ni][nj]==false)
      {
        vis[ni][nj] = true;
        Q.push(mp(ni,nj));
        dist[ni][nj] = dist[tmp.fi][tmp.se]+1;
        path[ni][nj] = k;
        if (ni == ie && nj == je)
          return true;
      }
    }
  }
    
  return false;
}

int main(int argc, char const *argv[])
{
  cin >> n;
  cin >> is >> js >> ie >> je;
  stack <string> res;
  int tmpi = ie, tmpj = je;
  if (bfs()==false)
    cout << "Impossible"; 
  else
  {
    int i, j, k;
    while (1)
    { 
      k = path[ie][je];
      if (k == 0)
        res.push("UL");
      else if (k == 1)
        res.push("UR");
      else if (k == 2)
        res.push("R");
      else if (k == 3)
        res.push("L");
      else if (k == 4)
        res.push("LR");
      else if (k == 5)
        res.push("LL");
      
      ie = ie - di[k];
      je = je - dj[k];

      if (ie == is && je == js)
        break;
      
    }
    cout << res.size() << endl;
    while (res.empty()==false){
      cout << res.top() << " ";
      res.pop();
    }
  }
  return 0;
}

