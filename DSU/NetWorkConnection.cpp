//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=734
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

int test, b, c, n;
char a;
int parent[MAX];

int findSet(int u){
	while(u != parent[u])
		u = parent[u];

	return u;
}

void unionSet(int u, int v){
	int up = findSet(u);
	int vp = findSet(v);

	parent[vp] = up;
}

int  main(int argc, char const *argv[])
{ 
	//freopen("xx.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> test;
	string s;


	while (test--){
		cin >> n;
		getline(cin, s);
	

		int cnt_true = 0;
		int cnt_false = 0;



		for (int i = 1; i <= n; ++i){
			parent[i] = i;
		}

		
		while (getline(cin, s)){
			
			if (s == "")
				break;
			stringstream ss(s);

			ss >> a >> b >> c;

			if (a == 'c')
			{
				unionSet(b, c);
			}
			else if (a == 'q')
			{
				if (findSet(b) == findSet(c))
				{
					cnt_true += 1;
				}
				else
					cnt_false += 1;
			}

		}

		cout << cnt_true << "," << cnt_false;
		if (test) cout << endl << endl;
	}
	cout << endl;
	return 0;
}	