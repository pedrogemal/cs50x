from cs50 import get_string

def ask():

    text = get_string("Text: ")
    count(text)

def count(text):

    letters = 0
    words = 0
    sentences = 0

    for character in text:
        if character >= 'a' and character <= 'z' or character >= 'A' and character <= 'Z':
            letters += 1
        elif character == ' ':
            words += 1
        elif character == '.' or character == '?' or character == '!':
            sentences += 1

    # Count the last word
    if len(text) > 2:
        words += 1

    check(letters, words, sentences)

def check(letters, words, sentences):
    avgLettersPercent = letters / words * 100
    avgSentencesPercent = sentences / words * 100

    preciseIndex = 0.0588 * avgLettersPercent - 0.296 * avgSentencesPercent - 15.8
    clIndex = round(preciseIndex)

    if clIndex > 16:
        print("Grade 16+")
    elif (clIndex < 1):
        print("Before Grade 1")
    else:
        print(f"Grade {clIndex}")

ask()