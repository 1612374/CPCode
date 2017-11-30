#include <bits/stdc++.h>
using namespace std;

int main(){
    int P, C;
    int cs = 1;
    while (1){
        cin >> P >> C;
        if (P == 0 && C == 0)
            break;
        printf("Case %d:\n", cs++);
        int sz = min(P, C);
        queue <int> q;
        for (int i = 1; i <= sz; i++)
            q.push(i);

        char tmp;
        for (int i = 1; i <= C; i++){
            cin >> tmp;
            if (tmp == 'N'){
                int x = q.front();
                cout << x << endl;
                q.pop();
                q.push(x);
            }
            else if (tmp == 'E'){
                int y;
                cin >> y;
                queue <int> q2;
                q2.push(y);
                while (q.empty() == false){
                    if (q.front() == q2.front()){
                        q.pop();
                    }
                    else{
                        q2.push(q.front());
                        q.pop();
                    }
                }
                swap(q,q2);
            }
        }

    }
    return 0;
}
