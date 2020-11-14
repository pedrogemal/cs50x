from cs50 import get_int

heigth = 0
width = 0

def askDigit():
    height = get_int("Height:")
    checkDigit(height)

def checkDigit(height):
    if height >= 1 and height <= 8:
        buildPyramid(height)
    else:
        print("Please use a number from 1 to 8.")
        askDigit()

def buildPyramid(height):

    width = height

#Loop for a new line
    for i in range(1, height + 1):
        num_hashes = i
        num_spaces = width - num_hashes

        #Loop for spaces
        print(" " * num_spaces, end="")

        #Loop for hashes
        print("#" * num_hashes, end="")

        #Space between pilars
        print("  ", end="")

        #Loop for hashes
        print("#" * num_hashes)

askDigit()