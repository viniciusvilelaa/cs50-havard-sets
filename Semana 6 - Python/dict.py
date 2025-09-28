#Data type DICT
#Dict saves pairs of Keys and Values

people = {
    "Vinicius": "84981462636",
    "Vanessa": "16174951000",
    "Elson": "84988993273"
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")
