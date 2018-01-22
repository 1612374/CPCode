//http://codeforces.com/contest/812/problem/A
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

int a[5][5];

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);

	FOR(i, 4) FOR(j, 4) cin >> a[i][j];
	
	if (a[0][3]){
		if (a[0][1]|| a[0][2]|| a[0][0]|| a[1][0]||a[2][1]||a[3][2]){
			cout << "YES";
			return 0;
		}
	}

	if (a[1][3]){
		if (a[0][2]||a[1][1]||a[2][0]||a[3][1]||a[1][0]||a[1][2]){
			cout << "YES";
			return 0;
		}
	}

	if (a[2][3]){
		if (a[0][1]||a[1][2]||a[2][1]||a[3][0]||a[2][0]||a[2][2]){
			cout << "YES";
			return 0;
		}
	}

	if (a[3][3]){
		if (a[0][0]||a[1][1]||a[2][2]||a[3][1]||a[3][0]||a[3][2]){
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}