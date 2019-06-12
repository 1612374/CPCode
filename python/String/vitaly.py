#http://codeforces.com/problemset/problem/518/A

s = input()
t = input()

r = len(s) - 1

while (s[r] == 'z'):
    r-=1

res = ""
for i in range(r):
    res += str(s[i])

ch = chr(ord(s[r]) + 1)
res += str(ch)

for i in range(r + 1, len(s)):
    res += "a"

if (res < t):
    print(res)
else:
    print("No such string")
