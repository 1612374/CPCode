//http://codeforces.com/contest/862/problem/B
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

int n;
bool vis[MAX] = {false};
vector <vector <int> > graph(MAX);
int color[MAX] = {0};

void dfs(int s){
	vis[s] = true;

	FOR(i, SZ(graph[s])){
		int node = graph[s][i];
		if (!vis[node]){
			color[node] = 1 - color[s];
			dfs(node);
		}
	}
}

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);

	cin >> n;

	int x, y;
	FOR(i, n - 1){
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	dfs(1);

	ll l, r;
	l = r = 0;
	FORI(i, n){
		if (color[i] == 1) l++;
		else r++;
	}

	cout << 1LL*l*r - 1LL*(n - 1);	

	return 0;
}
