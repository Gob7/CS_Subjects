def sequential_covering(examples):
    rules = []
    remaining_examples = examples.copy()

    while not remaining_examples.empty:
        rule = generate_rule(remaining_examples)
        rules.append(rule)
        remaining_examples = remove_covered_examples(remaining_examples, rule)

    return rules

def generate_rule(examples):
    rule = {}
    for attribute in examples.columns[:-1]:
        value = examples[attribute].mode()[0]
        rule[attribute] = value

    return rule

def remove_covered_examples(examples, rule):
    for attribute, value in rule.items():
        examples = examples[examples[attribute] != value]

    return examples

# Example usage
import pandas as pd

# Example dataset
data = {
    'Outlook': ['Sunny', 'Sunny', 'Overcast', 'Rainy', 'Rainy', 'Rainy', 'Overcast', 'Sunny', 'Sunny', 'Rainy', 'Sunny', 'Overcast', 'Overcast', 'Rainy'],
    'Temperature': ['Hot', 'Hot', 'Hot', 'Mild', 'Cool', 'Cool', 'Cool', 'Mild', 'Cool', 'Mild', 'Mild', 'Mild', 'Hot', 'Mild'],
    'Humidity': ['High', 'High', 'High', 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'Normal', 'Normal', 'High', 'Normal', 'High'],
    'Windy': ['Weak', 'Strong', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong', 'Weak', 'Weak', 'Weak', 'Strong', 'Strong', 'Weak', 'Strong'],
    'PlayTennis': ['No', 'No', 'Yes', 'Yes', 'Yes', 'No', 'Yes', 'No', 'Yes', 'Yes', 'Yes', 'Yes', 'Yes', 'No']
}

df = pd.DataFrame(data)

rules = sequential_covering(df)
for i, rule in enumerate(rules):
    print(f"Rule {i+1}: {rule}")
