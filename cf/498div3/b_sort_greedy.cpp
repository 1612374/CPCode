//http://codeforces.com/contest/1006/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); 
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> res(n);
	vector<int> a(n); 
	for (int i = 0; i < n; ++i) {
		cin >> res[i].first;
		a[i] = res[i].first;
		res[i].second = i + 1;
	}
	
	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	sort(res.begin(), res.begin() + k, [&](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
	
	int lst = 0, sum = 0;
	for (int i = 0; i < k - 1; ++i) {
	    sum += *max_element(a.begin() + lst, a.begin() + res[i].second);
		lst = res[i].second;	
	}
	sum += *max_element(a.begin() + lst, a.end());
	cout << sum << endl;
	

	lst = 0;
	for (int i = 0; i < k - 1; ++i) {
		cout << res[i].second - lst << " ";
		lst = res[i].second;	
	}
	cout << n - lst << endl;
	
	return 0;
}