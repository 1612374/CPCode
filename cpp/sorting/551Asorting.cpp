#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.rbegin(), b.rend());
    int R[100001];
    int r = 1;
    int k = r;
    R[b[0]] = r;
    k++;
    for (int i = 1; i < n; i++){
        if (b[i] != b[i - 1]){
            r = k;
        }
        R[b[i]] = r;
        k++;
    }

    for (int i = 0; i < n; i++)
        cout << R[a[i]] << " ";

    return 0;
}
