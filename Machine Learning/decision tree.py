import pandas as pd
import numpy as np

def entropy(data):
  labels = data.iloc[:, -1]
  counts = labels.value_counts(normalize=True)
  return -sum(counts * np.log2(counts))

def information_gain(data, attribute):
  total_entropy = entropy(data)
  values, counts = np.unique(data[attribute], return_counts=True)
  weighted_entropy = np.sum([(count / len(data)) * entropy(data.where(data[attribute] == value).dropna()) for value, count in zip(values, counts)])
  return total_entropy - weighted_entropy

def id3(data, target_attribute, attributes):
  if len(np.unique(data[target_attribute])) <= 1:
    return np.unique(data[target_attribute])[0]
  elif len(attributes) == 0:
    return np.unique(data[target_attribute])[np.argmax(np.unique(data[target_attribute], return_counts=True)[1])]
  else:
    best_attribute = max(attributes, key=lambda x: information_gain(data, x))
    tree = {best_attribute: {}}
    for value in np.unique(data[best_attribute]):
      subset = data.where(data[best_attribute] == value).dropna()
      tree[best_attribute][value] = id3(subset, target_attribute, [attr for attr in attributes if attr != best_attribute])
    return tree

data = pd.DataFrame({
    'Outlook': ['Sunny', 'Sunny', 'Overcast', 'Rainy', 'Rainy', 'Rainy', 'Overcast', 'Sunny', 'Sunny', 'Rainy', 'Sunny', 'Overcast', 'Overcast', 'Rainy'],
    'Temperature': ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Cool', 'Mild', 'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Mild'],
    'Humidity': ['High', 'High', 'High', 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'High'],
    'Windy': ['Weak', 'Strong', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong', 'Weak', 'Strong'],
    'PlayTennis': ['No', 'No', 'Yes', 'Yes', 'Yes', 'No', 'Yes', 'No', 'Yes', 'Yes', 'Yes', 'Yes', 'Yes', 'No']
})

tree = id3(data, 'PlayTennis', list(data.columns)[:-1])
print(tree)
