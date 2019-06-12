#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    while (1){

        scanf("%d", &n);

        if (n == 0) break;

        priority_queue<int, vector<int>, greater<int> > q;

        int tmp;
        for (int i = 0; i < n; i++){
            scanf("%d", &tmp);
            q.push(tmp);
        }

        int total = 0, cost = 0;
        while (q.size()>1){

            total = q.top();
            q.pop();
            total += q.top();
            q.pop();

            cost+=total;

            q.push(total);

        }

        cout << cost << endl;

    }



    return 0;
}
