# Using 'get_string' for getting the input
from cs50 import get_string


def main():
    text = get_string("Text: ")

    nlet = n_letters(text)
    nwords = n_words(text)
    nsent = n_sentences(text)

    L = nlet / nwords * 100
    S = nsent / nwords * 100

    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade >= 1 and grade < 17:
        print("Grade ", grade)
    elif grade > 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")


# Function to count the number of letters in the text
# This time I thought that the best way of exclude non letter characters
# Was by using a exclusivity condition (if statement) with chr() function
# Found the function in https://www.tutorialsteacher.com/python/chr-method website
def n_letters(text):
    nlet = len(text)
    for c in text.lower():
        if c < chr(97) or c > chr(122):
            nlet -= 1
    return nlet


# Function to count the number of word in the text
def n_words(text):
    nwords = text.split()
    nwords = len(nwords)
    return nwords


# Function to count the number of sentences in the text
def n_sentences(text):
    nsent = 0
    for i in text:
        if i == '.' or i == '!' or i == '?':
            nsent += 1
    return nsent


# "Prototype" main function calling
main()