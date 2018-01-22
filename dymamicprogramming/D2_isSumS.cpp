#include <bits/stdc++.h>
using namespace std;
int N, S, L[100][100];
int a[100];
int main(){
    freopen("x.txt","r",stdin);
    scanf("%d %d", &N, &S);
    for (int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
        L[i][a[i]] = 1;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= S; j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= S; j++){
            if (L[i - 1][j] == 1 || L[i-1][j-a[i]] == 1)
                L[i][j] = 1;
        }
    }

    cout << endl;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= S; j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }



    cout << L[N][S] << endl;
    return 0;
}
