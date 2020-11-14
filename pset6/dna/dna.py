import sys
import csv

strs = ['AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)
    readDocs(sys.argv[1], sys.argv[2])

def readDocs(db, text):
    with open(db, 'r') as database:
        data_lines = csv.reader(database)
        data = [row for row in data_lines]

    with open(text, 'r') as sequences:
        dna = sequences.read()

    countSequences(data, dna)

def countSequences(data, dna):
    counts = []

    for i in range(1, len(data[0])):
        count = 1
        string = data[0][i]
        while string * count in dna:
            count += 1
        counts.append(str(count - 1))

    for j in range(1, len(data)):
        if data[j][1:len(data[0])] == counts:
            print(data[j][0])
            exit(0)
    print('No Match')

if __name__ == "__main__":
    main()