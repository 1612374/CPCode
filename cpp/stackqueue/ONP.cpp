 #include <bits/stdc++.h>
 using namespace std;

 bool isOperand(char c)
{
    return (c <= 'z' && c >= 'a');
}

bool isOperator(char c)
{
    return (c == '-' || c == '+' || c == '/' || c == '*' || c == '^');
}

bool isPrioritize(char op1, char op2)
{
    if ((op1 == op2) || (op1 == '*' && op2 == '/') || (op1 == '/' && op2 == '*')
        || (op1 == '/' && op2 == '^') || (op1 == '*' && op2 == '^')) return false;

    if (op1 == '+' || op1 == '-') return false;

    return true;
}

void ToPolishNotation(string expr, queue<string> &P, stack<string> &S)
{
            int len = expr.length();
            for (int i = 0; i < len; i++)
            {
                if (isOperand(expr[i])) // la toan hang, dua tat ca vao queue
                {
                    string tmp = "";
                    tmp.push_back(expr[i]);
                    i++;
                    while (i < len && isOperand(expr[i]))
                    {
                        tmp.push_back(expr[i]);
                        i++;
                    }
                    i--;
                    P.push(tmp);
                }
                else if (isOperator(expr[i])) //la toan tu
                {
                    string tmp = "";
                    tmp.push_back(expr[i]);

                    if (S.size() == 0) // stack rong thi dua vao stack
                        S.push(tmp);
                    else
                    {
                        string tmp1 = S.top();
                        //neu tren dinh stack la dau ngoac hoac toan tu co do uu tien thap hon thi dua vao stack
                        if (tmp1[0] == '(' || isPrioritize(tmp[0], tmp1[0]))
                            S.push(tmp);
                        else
                        {
                            while (S.size() != 0)
                            {
                                string tmp2 = S.top();
                                if (tmp2[0] == '(' || isPrioritize(tmp[0], tmp2[0])) break; //neu den dau ngoac thi dung
                                P.push(tmp2);
                                S.pop();
                            }
                            S.push(tmp);
                        }
                    }

                }
                else if (expr[i] == '(')
                {
                    string tmp = "";
                    tmp.push_back(expr[i]);
                    S.push(tmp);
                }
                else if (expr[i] == ')')
                {
                    string tmp = S.top();
                    // giai phong tat ca cac toan tu nam tren dau ngoac trong stack
                    while (tmp[0] != '(')
                    {
                        P.push(tmp);
                        S.pop();
                        tmp = S.top();
                    }
                    S.pop(); // giai phong dau '('
                }

            }
            // dua cac toan tu trong stack vao queue->ky phap ba lan
            while (S.size() != 0)
            {
                string tmp = S.top();
                P.push(tmp);
                S.pop();
            }
}

int main(){

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        string s;
        cin >> s;
        queue <string> P;
        stack <string> S;

        ToPolishNotation(s, P, S);

        while (P.empty() == false){
            cout << P.front();
            P.pop();
        }
        cout << endl;
    }
    return 0;
}
