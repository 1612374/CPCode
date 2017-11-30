//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2498
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int t, n;
map<string, int> M;
int parent[100001], cnt[100001];

int findSet(int u)
{
	while(u != parent[u])
		u = parent[u];

	return u;
}

int main(int argc, char const *argv[])
{
	//freopen("xx.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> t;

	while(t--)
	{	
		for (int k = 0; k < 100001; k++){
			cnt[k] = 1, parent[k] = k;
		}
		M.clear();

		cin >> n;
		int num = 0;
		string s1, s2;
		while (n--)
		{
			cin >> s1 >> s2;
			int tx, ty;
      tx = M[s1];
     	if(tx == 0)
      	M[s1] = ++num, tx = num;
  		ty = M[s2];
  		if(ty == 0)
      	M[s2] = ++num, ty = num;

			int up = findSet(tx);
			int vp = findSet(ty);

			int res = 0;
			if (up != vp)
				if (cnt[up] > cnt[vp]){
					cnt[up] += cnt[vp];
					parent[vp] = up;
					res = cnt[up];
				}
				else{
					cnt[vp] += cnt[up];
					parent[up] = vp;
					res = cnt[vp];
				}
			else
				res = cnt[vp];

			cout << res << endl;
		}
	}


	return 0;
}
