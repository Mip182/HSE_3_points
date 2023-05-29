t = int(input())
c = list(map(int, input().split()))
c.sort()
ans = []
while c[0] < c[1]:
    if (c[2] + c[0]) / 2 == c[1]:
        print("YES")
        for i in range(0, c[1] - c[0]):
            ans.append([c[0] + i, c[2] - i])
        print(len(ans))
        if t == 1:
            for v in ans:
                print(*v)
        exit(0)
    ans.append([c[0], c[1]])
    c[0] += 1
    c[1] -= 1
while c[1] < c[2]:
    if (c[2] + c[0]) / 2 == c[1]:
        print("YES")
        for i in range(0, c[1] - c[0]):
            ans.append([c[0] + i, c[2] - i])
        print(len(ans))
        if t == 1:
            for v in ans:
                print(*v)
        exit(0)
    ans.append([c[1], c[2]])
    c[1] += 1
    c[2] -= 1
print("NO")