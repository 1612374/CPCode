#https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895
import queue
 
def inp():
    line = input().split(' ')
    if line.count(''):
        line.remove('')
    return map(int, line)
 
class topic:
    change_score = 0
    id = 0
    new_score = 0
    def __lt__(self, other):
        return self.change_score < other.change_score or (self.change_score == other.change_score and self.id > other.id)
 
def solve():
    n = int(input())
    pq = queue.PriorityQueue()
    for i in range(n):
        id, old_score, post, like, comment, share = inp()
        temp = topic()
        temp.id = id
        temp.new_score = post * 50 + like * 5 + comment * 10 + share * 20
        temp.change_score = old_score - temp.new_score
        pq.put(temp)
    for i in range(5):
        temp = pq.get()
        print(str(temp.id) + " " + str(temp.new_score))
 
if __name__ == '__main__':
    solve()

