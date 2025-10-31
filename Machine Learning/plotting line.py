import numpy as np
import matplotlib.pyplot as p

x = [2, 4, 6, 8]
y = [3, 0, -3, -6]
n = len(x)
xy = np.multiply(x, y)
x2 = np.square(x)
d = n * sum(x2) - sum(x) ** 2
m = (n * sum(xy) - sum(x) * sum(y)) / d
c = (sum(y) * sum(x2) - sum(x) * sum(xy)) / d
print("m =", m)
print("c =", c)
p.plot(x, y)
p.plot(x, y, "r*")
p.show()
