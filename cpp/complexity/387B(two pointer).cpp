//http://codeforces.com/problemset/problem/387/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a[100001], b[100001];
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    int i = 0, j = 0;
    while (i < n && j < m){
        if (b[j] >= a[i]) {
            i++;
        }
        j++;
    }

    cout << n - i;


    return 0;
}
