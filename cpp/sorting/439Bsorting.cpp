#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;
    vector <long long> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += c[i] * x;
        if (x > 1)
            x--;
    }
    cout << ans;
    return 0;
}
