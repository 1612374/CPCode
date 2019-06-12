#http://www.spoj.com/problems/ONP/
n = int(input())
for i in range(n):
    expression = input()
    stack = list()
    for c in expression:
        if (c.isalpha()):
            print(c, end='')
        elif (c == ')'):
            print(stack[-1], end='')
            stack.pop()
        elif (c != '('):
            stack.append(c)

    print("\n", end='')

