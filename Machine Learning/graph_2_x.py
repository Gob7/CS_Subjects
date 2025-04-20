import matplotlib.pyplot as plt
import numpy as np

# Define the range of x values
x = np.linspace(-4, 5, 100)

# Calculate the values for 2^x and x^2
y1 = 2**x
y2 = x**2

# Create the plot
plt.figure(figsize=(8, 6))
plt.plot(x, y1, label=r"$2^x$", color="blue")
plt.plot(x, y2, label=r"$x^2$", color="red")

# Add labels and title
plt.xlabel("x")
plt.ylabel("y")
plt.title("Graphs of $2^x$ and $x^2$")
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.grid(True)

# Add a legend
plt.legend()

# Show the plot
plt.show()
