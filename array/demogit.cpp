#include <bits/stdc++.h>
using namespace std;
int t, n, k, per[100001];
int main(){
	//freopen("input.txt", "r", stdin);
	bool check = false;
	scanf("%d", &t);
	for (int j = 1; j <= t; j++){
		scanf("%d%d", &n, &k);
		for (int x = 0; x < n; x++) per[x] = x + 1;
		do{
			int i = 0;
			for (;i < n; i++){
				if (abs(per[i] - (i + 1)) != k) break;
			}
			i--;
			if (i == n - 1 && abs(per[n-1] - n) == k){
				for (int i = 0; i < n; i++) cout << per[i] << " ";
				cout << endl; check = true; 
				break;
			}
		}while(next_permutation(per, per + n));

		if (!check) cout << "-1" << endl;
		else check = false;
	}
	cout << "lala" << endl;
	return 0;
}
