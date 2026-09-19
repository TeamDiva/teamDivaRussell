from collections import deque

def checkTop(board,col):
    for j in range(len(board)):
        if board[j][col]>0:
            tmp = board[j][col]
            board[j][col]=0
            return tmp
    return 0

def solution(board,moves):
    answer =0
    queue = deque()

    for i in moves:
        num=checkTop(board,i-1)
        # print("num : ",num)
        if num!=0:
            if len(queue)>=1:
                top = queue.pop()
                if top==num:
                    answer+=2
                else:
                    queue.append(top)
                    queue.append(num)
            else:
                queue.append(num)
    return answer