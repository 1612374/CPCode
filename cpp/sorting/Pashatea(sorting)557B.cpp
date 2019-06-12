#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
    int n,w;
    cin >> n >> w;
    vector <int> a(2*n);
    for (int i = 0; i < 2*n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    double ans = 0;
    if (a[0]*2 > a[n]){
        ans = (double)(a[n])*1.5 * (double)n;
    }
    else
        ans = (double)a[0] * 3 * n;

    cout << fixed << setprecision(9) << min(ans, (double)w);
    return 0;
}
