import cs50

# Prompt User for X
x = cs50.get_int("x: ")
# Prompt User for Y
y = cs50.get_int("y: ")

# Conditions
if (x < y):
    print("X is less than Y")
elif (x > y):
    print("X is greater than y")
else:
    print("x is equals to y")
