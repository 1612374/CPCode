//https://www.hackerrank.com/challenges/largest-permutation/problem
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+12;
int n,k,a[MAX], idx[MAX];
bool check[MAX]={false};
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        idx[a[i]] = i;
    }

    int  x = 1;
    while (k && x < n){
        if (a[x] == n-x+1){
            x++;
            continue;
        }
        int tmp = idx[n-x+1];
        idx[n-x+1] = idx[a[x]]; // = x
        idx[a[x]] = tmp;

        swap(a[tmp], a[x]);
        k--;
        x++;
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
