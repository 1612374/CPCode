#include <bits/stdc++.h>
using namespace std;

int test, M, C, price[25][25];
bool can_reach[220][25]; // = true if you can reach the sum M - money in garment g

int main(){

    cin >> test;
    while (test--){
        cin >> M >> C;
        for (int i = 0; i < C; i++){
            cin >> price[i][0]; // size of garment
            for (int j = 1; j <= price[i][0]; j++){
                cin >> price[i][j];
            }
        }

        memset(can_reach, false, sizeof can_reach);

        for (int i = 1; i <= price[0][0]; i++){
            can_reach[M - price[0][i]][0] = true;
        }

        for (int j = 1; j < C; j++){
            for (int i = 0; i < M; i++){
                if (can_reach[i][j - 1]){
                    for (int l = 1; l <= price[j][0]; l++){
                        if (i - price[j][l] >= 0)
                            can_reach[i - price[j][l]][j] = true;
                    }
                }
            }
        }
        int i;
        for (i = 0; i <= M && !can_reach[i][C-1]; i++);

        if (i == M + 1)
            cout << "no solution\n";
        else
            cout << M - i << endl;

    }

    return 0;
}
