//http://codeforces.com/problemset/problem/161/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m , x, y, a[100001], b[100001];
    cin >> n >> m >> x>> y;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    int res[100001] = {0}, ans = 0;
    int rx[100001], ry[100001];
    while (i < n){
        while (j < m && b[j] < a[i] - x) j++;

        if (j == m)
            break;

        if (b[j] >= a[i] - x && b[j] <= a[i] + y){
            rx[ans]=i, ry[ans++]=j++;
        }

        i++;
    }

    cout << ans << endl;

    for (int i = 0; i < ans; i++)
        cout << rx[i]+1 << ' ' << ry[i]+1 << endl;

    return 0;
}
