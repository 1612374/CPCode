//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/
#include <bits/stdc++.h>
using namespace std;
int t, n, x;
vector <int> a;
int main(){

	cin >> t;
	while (t--){
		cin >> n >> x;
		a.resize(n);

		for (int i = 0; i < n; i++) 
			cin >> a[i];

		set <int> mS(a.begin(), a.end());

		if (mS.size() > x) cout << "Average\n";
		else if (mS.size() < x) cout << "Bad\n";
		else cout << "Good\n";
	}

	return 0;
}