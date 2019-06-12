//http://codeforces.com/problemset/problem/888/C
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
const int MAX = 1500 + 10;

string s;

int solve(char c){
  int prev = -1;
  int ans = 0;
  int len = s.length();
  for (int i = 0; i < len; i++){
    if (s[i] == c){
      ans = max(ans, i - prev);
      prev = i;
    }
  }

  ans = max(len - prev, ans);
  return ans;
}

int main(){

  //freopen("xx.txt","r", stdin);

  cin >> s;
  int res = s.length();
  int len = s.length();

  char c;
  int j, k;

  for (int i = 0; i < 26; i++){
    c = 'a' + i;

    res = min(solve(c), res);
  }

  cout << res;


 // cout << solve('c');
  return 0;
}