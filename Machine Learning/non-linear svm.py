import numpy as np
import matplotlib.pyplot as plt
from sklearn.svm import SVC

eps = np.finfo(float).eps


def tf(p):
    dt = np.sqrt(np.sum(p**2, axis=1))
    for i, d in enumerate(dt):
        if d > 2:
            p[i] = [
                4 - p[i][1] + abs(p[i][0] - p[i][1]),
                4 - p[i][0] + abs(p[i][0] - p[i][1]),
            ]
    return p


xp = tf(np.array([[2, 2], [2, -2], [-2, -2], [-2, 2]]))
yp = np.ones(len(xp))
xn = tf(np.array([[1, 1], [-1, 1], [-1, -1], [1, -1]]))
yn = -np.ones(len(xn))
x = np.concatenate(xp, xn)
y = np.concatenate(yp, yn)

svm = SVC(kernel="linear")
svm.fit(x, y)
support_vectors = svm.support_vectors_
bias = round(svm.intercept_[0])
w = [round(coeff) for coeff in svm.coef_[0]]
# print("Weight:",w)
# print("Bias",bias)

plt.scatter(xp[:, 0], xp[:, 1], color="blue", label="Positive")
plt.scatter(xn[:, 0], xn[:, 1], color="red", label="Negative")
if w[1] != 0:
    x_values = np.linspace(-4, 4, 10)
    y_values = (-bias - w[0] * x_values) / (w[1] + eps)
    plt.plot(x_values, y_values, color="black", linestyle="-", label="Hyperplane")
else:
    plt.axvline(
        x=-bias / (w[0] + eps), color="black", linestyle="-", label="Hyperplane"
    )
plt.scatter(
    support_vectors[:, 0],
    support_vectors[:, 1],
    color="grey",
    marker="s",
    label="Support Vectors",
)
plt.xlabel("X1")
plt.ylabel("X2")
plt.title("Non-Linear SVM Classifier")
plt.legend()
plt.grid(True)
plt.show()
