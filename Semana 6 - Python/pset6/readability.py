import cs50
import sys
import re

#Fuction for count words in text
def countWords(text):
    pattern = r"\b[a-zA-Z]+(?:'[a-zA-Z]+)?\b"
    words = re.findall(pattern,text)
    return len(words)

#Function for count letters in text
def countLetters(text):
    count = 0
    for i in text:
        if i.isalpha():
            count += 1
    return count

#Function for count phrases in text
def countPhrases(text):

    return len(re.findall(r"[.!?]+", text))

#Calculate the grade and print it
def checkgrade(text):
    words = countWords(text)
    letters = countLetters(text)
    phrases = countPhrases(text)

    L = (letters / words) * 100
    S = (phrases / words) * 100

    grade = (0.0588 * L) - (0.296 * S) - 15.8
    grade = round(grade)

    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")



def main():
    text = cs50.get_string("Text: ")
    checkgrade(text)




main()
