G = [[0,1,0,0,1,0],
     [1,0,1,0,1,0],
     [0,1,0,1,0,0],
     [0,0,1,0,1,1],
     [1,1,0,1,0,0],
     [0,0,0,1,0,0]]

def DFS(G, start):
    done = [0] * len(G)
    todo = [start]
    while(todo):
        node = todo.pop()
        if done[node]:
            continue
        print(node)
        done[node] = 1
        for i in range(len(G)):
            if 1 == G[node][i] and 0 == done[i]:
                todo.append(i)

DFS(G, 0)