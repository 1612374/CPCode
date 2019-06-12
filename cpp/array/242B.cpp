#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100001], b[100001];
int main(){
    int _max = 0, _min = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        if (_max < b[i])
            _max = b[i];
        if (_min > a[i])
            _min = a[i];
    }

    for (int i = 1; i <= n; i++){
        if (a[i] == _min && b[i] == _max)
        {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
