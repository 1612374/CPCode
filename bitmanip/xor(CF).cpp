//http://codeforces.com/problemset/problem/862/C
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

int x, n;

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);
	int tmp = 90235;
	cin >> n >> x;	

	if (n == 2 && x == 0){
		cout << "NO\n";
		return 0;
	}

	ll pw = pow(2, 17);

	cout << "YES\n";

	if (n == 1){
		cout << x;
		return 0;
	}

	if (n == 2){
		cout << "0 " << x;
		return 0;
	}


	int y = 0;

	FORI(i, n - 3){
		cout << i << " ";
		y ^= i;
	}



	if (y == x){
		cout << pw << " " << pw*2 << " ";
		ll z = pw^(pw*2);
		cout << z;
	}
	else{
		cout << "0 " << pw << " ";
		ll z = pw^x^y;
		cout << z; 
	}


	return 0;
}