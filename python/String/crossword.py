def inp(): 
    return map(int, input().split(' '))
n, m = inp()
v = []
for i in range(0, n):
    temp = input() 
    v.append(temp)
 
output = ""
for i in range(0, n): 
    for j in range(0, m):
        flag = True 
        for k in range(0, n):
            if (v[k][j] == v[i][j] and k != i):
                flag = False
        for k in range(0, m):
            if (v[i][k] == v[i][j] and k != j):
                flag = False
        if (flag):
            output = output + str(v[i][j])
print(output)
