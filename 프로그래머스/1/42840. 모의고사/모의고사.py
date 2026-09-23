def solution(answers):
    answer = []
    list1 = [1,2,3,4,5]
    list2 = [2,1,2,3,2,4,2,5]
    list3 = [3,3,1,1,2,2,4,4,5,5]
    points = [0,0,0]
    for i in range(len(answers)):
        num = answers[i]
        points[0] += (1 if list1[i%5] == num else 0)
        points[1] += (1 if list2[i%8] == num else 0)
        points[2] += (1 if list3[i%10] == num else 0)
    maxPoint = points[0]
    for point in points:
        if maxPoint<point:
            maxPoint=point
    for i in range(len(points)):
        if maxPoint==points[i]:
            answer.append(i+1)
    return answer