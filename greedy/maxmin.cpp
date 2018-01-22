//https://www.hackerrank.com/challenges/angry-children/problem
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+12;
int a[MAX], n, k;
int main(){
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    int res = 1e9;

    int i = 0, j = k - 1;
    while (j < n){

        res = min(res, a[j] - a[i]);
        j++;
        i++;
    }
    cout << res;

    return 0;
}
