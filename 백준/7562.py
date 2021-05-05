from collections import deque
import sys

testcase = int(sys.stdin.readline())

moves = [
    (1,-2),
    (2, -1),
    (2, 1),
    (1, 2),
    (-1, 2),
    (-2, 1),
    (-2, -1),
    (-1, -2)
]

def bfs(src, dst, size):
    queue = deque([src])
    visited = [[-1]*l for _ in range(size)]
    visited[src[0]][src[1]] = 0

    while len(queue) > 0:
        src = queue.popleft()

        if src == dst:
            return visited[src[0]][src[1]]
        
        for move in moves:
            nxt = src[0] + move[0], src[1] + move[1]
            if (0 <= nxt[0] < size) and (0 <= nxt[1] < size) and visited[nxt[0]][nxt[1]] == -1:
                visited[nxt[0]][nxt[1]] = visited[src[0]][src[1]] + 1
                queue.append(nxt)
                
    return visited[dst[0]][dst[1]]


for _ in range(testcase):
    l = int(sys.stdin.readline())
    src = tuple(map(int, sys.stdin.readline().split()))
    dst = tuple(map(int, sys.stdin.readline().split()))

    print(bfs(src, dst, l))