def dist(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5


"""
n=int(input('Enter number of points: '))
k=int(input('Enter number of centroids: '))
points=[]
for i in range (n):
    p=eval(input('x, y: '))
    points.append(p)
"""

n = 8
k = 3
points = [(2, 10), (5, 8), (1, 2), (2, 5), (7, 5), (4, 9), (8, 4), (6, 4)]

old = [-1] * n
new = [-1] * n
data = [-1] * (n * k)
centroid = points[:k]
print(points)
print(centroid)

while True:
    for i in range(n):
        x = i * k
        for j in range(k):
            data[x + j] = dist(points[i], centroid[j])
        new[i] = data[x : x + k].index(min(data[x : x + k]))
    print("\n")
    for i in range(n):
        x = i * k
        print(data[x : x + k])
    print("cluster:")
    print(old)
    print(new)
    if old == new:
        break
    else:
        old = list(new)
        for i in range(k):
            x = new.count(i)
            j = 0
            xsum = ysum = 0
            for _ in range(x):
                y = new.index(i, j, n)
                j = y + 1
                xsum += points[y][0]
                ysum += points[y][1]
            centroid[i] = [xsum / x, ysum / x]
        print("centroid:\n", centroid)
