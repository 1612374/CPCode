#https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3359
import queue


def inp():
    return map(int, input().split(' '))


count = 0
while (1 == 1):
    p, c = inp()
    q = queue.Queue()
    if (p == 0 and c == 0):
        break
    if (p <= c):
        for i in range(0, p):
            q.put(i + 1)
    else:
        for i in range(0, c):
            q.put(i + 1)
    count += 1
    print("Case " + str(count))
    for i in range(0, c):
        line = input().split(' ')
        s = line[0]
        if (s == 'N'):
            temp = q.get()
            print(temp)
            q.put(temp)
        else:
            x = int(line[1])
            temp = queue.Queue()
            temp.put(x)
            n = q.qsize()
            for j in range(0, n):
                k = q.queue[0]
                if (x == k):
                    q.get()
                else:
                    temp.put(q.get())
            swap = temp
            temp = q
            q = swap



