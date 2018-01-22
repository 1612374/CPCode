//https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem
#include <bits/stdc++.h>
using namespace std;

int N, T;

void print(int t, int v){
    while (t--){
        cout << v;
    }
}

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);
        bool check = false;
        for (int i = N; i >= 0; i--){
            if (i % 3 == 0 && (N - i) % 5 == 0){
                print(i,5);
                print(N-i,3);
                putchar('\n');
                check = true;
                break;
            }
        }
        if (!check) printf("-1\n");
    }
    return 0;
}
