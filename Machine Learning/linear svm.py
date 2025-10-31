import numpy as np
import matplotlib.pyplot as plt
from sklearn.svm import SVC

xp = np.array([[3, 1], [3, -1], [6, 1], [6, -1]])
yp = np.ones(len(xp))
xn = np.array([[1, 0], [0, 1], [0, -1], [-1, 0]])
yn = -np.ones(len(xn))
x = np.concatenate(xp, xn)
y = np.concatenate(yp, yn)

svm = SVC(kernel="linear")
svm.fit(x, y)
support_vectors = svm.support_vectors_
w = svm.coef_[0]
bias = svm.intercept_[0]
w = [round(coeff) for coeff in w]
bias = round(bias)
print("Weight:", w)
print("Bias", bias)

plt.scatter(xp[:, 0], xp[:, 1], color="blue", label="Positive")
plt.scatter(xn[:, 0], xn[:, 1], color="red", label="Negative")
if w[1] != 0:
    x_values = np.linspace(-1, 7, 10)
    y_values = np.zeros_like(x_values) + (-bias / w[1])
    plt.plot(x_values, y_values, color="black", linestyle="-", label="Hyperplane")
else:
    x_values = np.full(10, -bias / w[0])  # For vertical line
    y_values = np.linspace(-1, 2, 10)
    plt.plot(x_values, y_values, color="black", linestyle="-", label="Hyperplane")
plt.scatter(
    support_vectors[:, 0],
    support_vectors[:, 1],
    color="grey",
    marker="s",
    label="Support Vectors",
)
plt.xlabel("X1")
plt.ylabel("X2")
plt.title("Linear SVM Classifier")
plt.legend()
plt.grid(True)
plt.show()
