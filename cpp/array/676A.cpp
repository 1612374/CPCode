#include <iostream>
#include <algorithm>
using namespace std;
int n, a[101], mx = 0, mn = 101, idx1 = 0, idx2 = 0;
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            idx1 = i;
        }

        if (a[i] < mn){
            mn = a[i];
            idx2 = i;
        }
    }

    if (max(idx1, idx2) > n - 1 - min(idx1, idx2))
        cout << max(idx1, idx2);
    else
        cout << n - 1 - min(idx1, idx2);

    return 0;
}
