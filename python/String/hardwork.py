#http://codeforces.com/problemset/problem/61/B
a = input()
b = input()
c = input()
n = int(input())

def process(s):
    res = ""
    for ch in s:
        if (ch.isalpha()):
            res += str(ch.lower())
            
    return res

a = process(a)
b = process(b)
c = process(c)

ss = []

ss.append(a+b+c)
ss.append(a+c+b)
ss.append(b+c+a)
ss.append(b+a+c)
ss.append(c+a+b)
ss.append(c+b+a)

for i in range(n):
    strr = input()
    strr = process(strr)
    
    flag = False
    for tmp in ss:
        if (strr == tmp):
            flag = True
            break

    if (flag):
        print("ACC")
    else:
        print("WA")
