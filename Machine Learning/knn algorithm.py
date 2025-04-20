import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier

x = [2.0,3.0,5.0,7.0,10.0]
y = [3.0,4.0,6.0,8.0,10.0]
label = ['A', 'A', 'B', 'B', 'A']
d = {'Red':'A', 'Green':'B', 'A':'Red', 'B':'Green'}
classes=[]
for i in label:
    classes.append(d[i])
data = list(zip(x, y))
knn = KNeighborsClassifier(n_neighbors=3)
knn.fit(data, classes)
new_x = 6.0
new_y = 7.0
new_point = [(new_x, new_y)]
prediction = knn.predict(new_point)
print('DP\tx\ty\tLabel')
for i in range(len(x)):
    print(i+1,x[i],y[i],label[i],sep='\t')
print(len(x)+1,new_x,new_y,d[prediction[0]],sep='\t')
plt.scatter(x + [new_x], y + [new_y], c=classes + [prediction[0]])
plt.text(x=new_x+0.3, y=new_y-0.3, s=f"new point, class: {d[prediction[0]]}")
plt.show()
