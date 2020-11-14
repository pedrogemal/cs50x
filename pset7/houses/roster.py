import sys
import csv
import cs50

if len(sys.argv) != 2:
    print("Usage: roster {house}")
    sys.exit(1)

# Open database
db = cs50.SQL("sqlite:///students.db")

students = db.execute("SELECT * from students WHERE house = ? ORDER BY last ASC, first ASC", sys.argv[1])

for student in students:
    if student['middle'] != None:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")