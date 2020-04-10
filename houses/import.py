import csv
import cs50
from sys import argv, exit

db = cs50.SQL("sqlite:///students.db")


if len(argv) != 2:
    print("missing command-line argument")
    exit(1)

with open(argv[1], "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        name = row["name"].split()
        if len(name) == 2:
            name.insert(1, None)
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   name[0], name[1], name[2], row["house"], row["birth"])
