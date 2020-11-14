import sys
import csv
import cs50

if len(sys.argv) != 2:
    print("Usage: import file.csv")
    sys.exit(1)

if not (sys.argv[1].endswith(".csv")):
        sys.exit("You must provide a .csv file")

# Open database
db = cs50.SQL("sqlite:///students.db")

# Create table if not exists
# db.execute("CREATE TABLE IF NOT EXISTS students (id INT, first VARCHAR(255), middle VARCHAR(255), last VARCHAR(255), house VARCHAR(10), birth INT, PRIMARY KEY(id))")

with open(sys.argv[1], 'r') as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Iterate over CSV file
    for row in reader:

        student = []

        for part in row["name"].split(" "):
            student.append(part)

        student.append(row["house"])
        student.append(row["birth"])

        if (len(student) == 5):
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", student[:5])


        if (len(student) == 4):
            db.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", student[:4])
