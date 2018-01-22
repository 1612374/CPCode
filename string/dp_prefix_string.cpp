//http://codeforces.com/contest/814/problem/C
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
int n, q, qi;
char ci;
int ans[150][MAX] = {{0}};

int main(int argc, char const *argv[])
{
	cin >> n;
	cin >> s;

	//prefix
	for (char c = 'a'; c <= 'z'; c++){
		for (int i = 0; i < n; i++){
			int cnt_rep = 0;
			for (int j = i; j < n; j++){
				if (s[j] != c) cnt_rep++;
				REMAX(ans[c][cnt_rep], j-i+1);
			}
		}
		for (int i = 1; i < MAX; i++){
			REMAX(ans[c][i], ans[c][i - 1]);
		}
	}

	cin >> q;
	FOR(i, q){
		cin >> qi >> ci;
		cout << ans[ci][qi] << endl;
	}

	return 0;
}