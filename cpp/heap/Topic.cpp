#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Topic{
    int ID;
    ll change;
    ll n_score;
    bool operator<(const Topic &tp) const{
        if (change == tp.change)
            return ID < tp.ID;
        return change < tp.change;
    }
};

int n;

int main(){

    scanf("%d", &n);

    priority_queue <Topic> q;

    ll z, id, p, l, c, s;
    for (int i = 0; i < n; i++){
        cin >> id >> z >> p >> l >> c >> s;

        Topic tmp;
        tmp.ID = id;
        tmp.n_score = (50*p + 5*l + 10*c + 20*s);
        tmp.change = (50*p + 5*l + 10*c + 20*s) - z;

        q.push(tmp);

    }

    int cnt = 0;
    while (q.empty() == false){
        Topic tmp = q.top();
        cout << tmp.ID << " " << tmp.n_score << endl;
        cnt++;
        if (cnt == 5)
            break;

        q.pop();
    }

    return 0;
}
