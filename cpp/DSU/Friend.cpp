//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int p[30001], cnt[30001];

int findSet(int u){
	while(u != p[u])
		u = p[u];

	return u;
}

void unionSet(int u, int v){
	int up = findSet(u);
	int vp = findSet(v);

	if (up != vp){
		if (cnt[up] > cnt[vp]){
			cnt[up] += cnt[vp];
			p[vp] = up;
		}
		else{
			cnt[vp] += cnt[up];
			p[up] = vp;
		}
	} 
}

int main(int argc, char const *argv[])
{
	//freopen("xx.txt","r", stdin);
	cin >> t;

	while(t--){
		cin >> n >> m;
		int x, y;

		for (int i = 1; i <= n; i++){
			p[i] = i, cnt[i] = 1;
		}

		for (int i = 0; i < m; i++){
			cin >> x >> y;

			unionSet(x, y);
		}
		int res = 0;
		for (int i = 1; i <= n; i++){
			res = max(cnt[i], res);
		}

		cout << res << endl;
	}

	return 0;
}