def solution(citations):
    answer = 0
    length=len(citations)
    citations.sort()
    new = [length-index if value>=length-index  else -1 for index , value in enumerate(citations)]
    answer=max(new)
    if answer == -1:
        return 0
    return answer