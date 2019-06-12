#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_proble m&problem=1876
import queue
while (True):
    n = int(input())
    if (n == 0):
        exit()

    q = queue.Queue()
    for x in range(1,n+1):
        q.put(x)

    discard = list()

    while (q.qsize() > 1):
        tmp = q.get()
        discard.append(tmp)
        tmp = q.get()
        q.put(tmp)

    print("Discarded cards:", end=" ")
    for i in range(len(discard) - 1):
        print(discard[i], end=', ')

    print(discard[len(discard) - 1])

    print("Remaining card: %d" % q.queue[0])


