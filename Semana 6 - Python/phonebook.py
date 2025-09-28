import csv

from cs50 import get_string

with open("phonebook.csv", "a") as file:
    writer = csv.writer(file)
    name = get_string("Name: ")
    number = get_string("Number: ")

    writer.writerow([name, number])
file.close()
